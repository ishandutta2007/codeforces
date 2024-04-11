#include <bits/stdc++.h>
using namespace std;

const int MX = 1E7 + 5, N = 500005;

int n, u, d[MX], a[N], b[N];

void init() {
    for (int i = 2; i * i <= MX; i++) {
        if (d[i] == 0) {
            for (int j = i * i; j <= MX; j += i) {
                d[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        if (d[u] == 0) {
            a[i] = b[i] = -1;
        } else {
            int tmp = d[u];
            a[i] = 1;
            while (u % tmp == 0) {
                a[i] *= tmp;
                u /= tmp;
            }
            if (u == 1) {
                a[i] = b[i] = -1;
            } else {
                b[i] = u;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " \n"[i == n];
    }
}