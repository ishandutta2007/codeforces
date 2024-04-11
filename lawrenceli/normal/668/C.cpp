#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int maxn = 100100;
const ld eps = 1e-12;

int n;
ld pmax[maxn], pmin[maxn];
ld qa[maxn], qb[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> pmax[i];
    for (int i = 1; i <= n; i++) cin >> pmin[i];

    ld b = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        c += pmax[i];
        b += pmax[i] + pmin[i];

        ld d = b * b - 4 * c;
        if (d < 0) d = 0;
        ld p1 = (b - sqrt(d)) / 2;
        ld p2 = (b + sqrt(d)) / 2;

        qa[i] = p1;
        qb[i] = p2;
    }

    cout << fixed << setprecision(10);
    for (int i = 1; i <= n; i++)
        cout << qa[i] - qa[i - 1] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++)
        cout << qb[i] - qb[i - 1] << ' ';
    cout << '\n';
}