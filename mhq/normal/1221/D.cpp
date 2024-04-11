#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
int n;
ll a[maxN], b[maxN];
const int BUBEN = 4;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        vector < pair < ll, ll > > best;
        for (int i = 0; i <= BUBEN; i++) {
            best.emplace_back(b[1] * i, a[1] + i);
        }
        for (int i = 2; i <= n; i++) {
            vector < pair < ll, ll > > nbest;
            for (int j = 0; j <= BUBEN; j++) {
                ll mn = 2e18;
                for (auto it : best) {
                    if (it.second != a[i] + j) mn = min(mn, it.first);
                }
                mn += j * b[i];
                nbest.emplace_back(mn, a[i] + j);
            }
            best = nbest;
        }
        ll mn = 2e18;
        for (auto it : best) mn = min(mn, it.first);
        cout << mn << '\n';
    }
    return 0;
}