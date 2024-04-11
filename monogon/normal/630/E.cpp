
#include <iostream>

using namespace std;

long long x1, y1, x2, y2;

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << ((y2 - y1) / 2 + 1) * ((x2 - x1) / 2 + 1) + ((y2 - y1) / 2) * ((x2 - x1) / 2) << endl;
}