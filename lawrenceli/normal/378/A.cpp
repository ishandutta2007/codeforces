#include <iostream>
#include <cstdio>
#include <ios>
#include <algorithm>

using namespace std;

int a, b;
int num[3];

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> a >> b;
    for (int i=1; i<=6; i++) {
        int x = abs(a - i), y = abs(b - i);
        if (x < y) num[0] ++;
        else if (x == y) num[1] ++;
        else num[2] ++;
    }

    cout << num[0] << ' ' << num[1] << ' ' << num[2] << endl;
    return 0;
}