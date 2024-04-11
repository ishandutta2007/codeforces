#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 5005;
const int INF = 1e9;

int n, m, t[MAXN], l[MAXN], r[MAXN], v[MAXN], dif[MAXN], a[MAXN], b[MAXN];

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n >> m;
    for (int i=1; i<=n; i++) a[i] = INF;

    for (int i=0; i<m; i++) {
        cin >> t[i] >> l[i] >> r[i] >> v[i];

        if (t[i] == 1) {
            for (int j=l[i]; j<=r[i]; j++)
                dif[j] += v[i];
        } else {
            for (int j=l[i]; j<=r[i]; j++)
                a[j] = min(a[j], v[i] - dif[j]);
        }
    }

    for (int i=1; i<=n; i++) b[i] = a[i];

    for (int i=0; i<m; i++) {
        if (t[i] == 1) {
            for (int j=l[i]; j<=r[i]; j++)
                b[j] += v[i];
        } else {
            int x = -INF;
            for (int j=l[i]; j<=r[i]; j++)
                x = max(x, b[j]);
            if (x != v[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for (int i=1; i<=n; i++) cout << a[i] << ' ';

    return 0;
}