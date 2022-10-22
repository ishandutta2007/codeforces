#include <iostream>
using namespace std;

int x, y;

int main()
{
    bool firs = false;
    cin >> x >> y;
    while (true) {
          firs = !firs;
          if (firs) {
                    if (x >= 2 && y >= 2) { x -= 2; y -= 2; }
                    else if (x >= 1 && y >= 12) { x--; y -= 12; }
                    else if (y >= 22) y -= 22;
                    else break;
          } else {
                 if (y >= 22) y -= 22;
                 else if (x >= 1 && y >= 12) { x--; y -= 12; }
                 else if (x >= 2 && y >= 2) { x -= 2; y -= 2; }
                 else break;
          }
    }
    if (firs) cout << "Hanako\n";
    else cout << "Ciel\n";
    return 0;
}