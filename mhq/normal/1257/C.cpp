#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int& v : a) cin >> v;
        vector < int > was(n + 1, -1);
        int mn = n + 100;
        for (int i = 0; i < a.size(); i++) {
            if (was[a[i]] != -1) {
                mn = min(mn, i - was[a[i]] + 1);
            }
            was[a[i]] = i;
        }
        if (mn > n) cout << -1 << '\n';
        else cout << mn << '\n';
    }
    return 0;
}