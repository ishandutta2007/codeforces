#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int x = 1111111, y;
    cin >> y; x = min(x, y / 1);
    cin >> y; x = min(x, y / 1);
    cin >> y; x = min(x, y / 2);
    cin >> y; x = min(x, y / 7);
    cin >> y; x = min(x, y / 4);
    cout << x << endl;
    return 0;
}