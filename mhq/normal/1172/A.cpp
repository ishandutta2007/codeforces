#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int n;
int a[maxN], b[maxN];
int pos[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 0) pos[a[i]] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] != 0) pos[b[i]] = i;
    }
    if (pos[1] != 0) {
        int where = pos[1];
        bool ok = true;
        for (int j = where; j <= n; j++) {
            if (b[j] != 1 + (j - where)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            int lst = b[n];
            for (int j = lst + 1; j <= n; j++) {
                if (pos[j] == 0) continue;
                if (pos[j] > j - lst - 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << n - lst;
                return 0;
            }
        }
    }
    int ti = 0;
    for (int i = 1; i <= n; i++) {
        ti = max(ti, pos[i] - i + 1);
    }
    cout << ti + n;
    return 0;
}