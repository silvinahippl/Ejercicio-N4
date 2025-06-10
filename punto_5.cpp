#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> juegos;

    int opcion;
    do {
        cout << "\nCarga tu lista de juegos favoritos" << endl;
        cout << "1. Ver lista de juegos" << endl;
        cout << "2. Agregar un juego" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1: {
                if (juegos.empty()) {
                    cout << "La lista de juegos está vacía." << endl;
                } else {
                    cout << "\n Lista de Juegos " << endl;
                    for (auto inter = juegos.begin(); inter != juegos.end(); inter++) {
                        cout << "- " << *inter << endl;
                    }
                }
                break;
            }
            case 2: {
                string nuevoJuego;
                cout << "Ingrese el nombre del juego que desea agregar (una palabra): ";
                cin >> nuevoJuego; // Usando >> para leer una palabra
                juegos.push_back(nuevoJuego);
                cout << "\"" << nuevoJuego << "\" ha sido agregado a la lista." << endl;
                break;
            }
            case 3: {
                cout << "Ingrese el nombre del juego que desea quitar (una palabra): ";
                string juegoARemover;
                cin >> juegoARemover; // Usando >> para leer una palabra

                auto it = find(juegos.begin(), juegos.end(), juegoARemover);

                if (it != juegos.end()) {
                    juegos.erase(it);
                    cout << "\"" << juegoARemover << "\" ha sido removido de la lista." << endl;
                } else {
                    cout << "El juego \"" << juegoARemover << "\" no se encontró en la lista." << endl;
                }
                break;
            }
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, intente nuevamente." << endl;
        }
    } while (opcion != 0);

    return 0;
}
