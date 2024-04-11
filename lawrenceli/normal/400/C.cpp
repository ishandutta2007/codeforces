#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

int n, m, x, y, z, p;

int main() {
    ios :: sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> x >> y >> z >> p;
    int on = n, om = m;
    for (int i=0; i<p; i++) {
        n = on, m = om;
        int r, c;
        cin >> r >> c;
        r--; c--;
        for (int j=0; j<x%4; j++) {
            int nr = c, nc = n - r - 1;
            r = nr, c = nc;
            swap(n, m);
        }
        for (int j=0; j<y%2; j++)
            c = m - c - 1;
        for (int j=0; j<4-(z%4); j++) {
            int nr = c, nc = n - r - 1;
            r = nr, c = nc;
            swap(n, m);
        }

        cout << r+1 << ' ' << c+1 << '\n';
    }

    return 0;
}