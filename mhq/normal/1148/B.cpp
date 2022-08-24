#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
ll ta, tb;
int k;
const int maxN = 2 * (int)1e5 + 100;
ll a[maxN], b[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> ta >> tb >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    ll best = 0;
    int it = 1;
    for (int i = 0; i <= min(n, k); i++) {
        if (i == n) {
            cout << -1;
            return 0;
        }
        ll arive = a[i + 1] + ta;
        if (arive > b[m]) {
            cout << -1;
            return 0;
        }
        while (it <= m && b[it] < arive) it++;
        int le = k - i;
        if (m - it + 1 <= le) {
            cout << -1;
            return 0;
        }
        best = max(best, b[it + le] + tb);
    }
    cout << best;
    return 0;
}