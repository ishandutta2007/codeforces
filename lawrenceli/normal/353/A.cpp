#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int n, x[MAXN], y[MAXN], sx, sy;
bool b;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> n;
    for (int i=0; i<n; i++) cin >> x[i] >> y[i];
    for (int i=0; i<n; i++) {
       if (x[i] % 2 != y[i] % 2) b = 1;
       sx += x[i]; sy += y[i];
    }
    if (sx % 2 == 0 && sy % 2 == 0) cout << 0 << endl;
    else if (sx % 2 == 1 && sy % 2 == 1) {
        if (b) cout << 1 << endl;
        else cout << -1 << endl;
    } else cout << -1 << endl;
    return 0;
}