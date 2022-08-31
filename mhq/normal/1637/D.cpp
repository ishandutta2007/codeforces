#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 105;
int a[maxN], b[maxN];
int n;
const int maxK = maxN * maxN;
typedef bitset<maxK> bs;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        bs cur;
        cur[0] = 1;
        for (int i = 1; i <= n; i++) {
            cur = (cur << a[i]) | (cur << b[i]);
        }
        ll best = 5e18;
        ll add_sq = 0;
        int S = 0;
        for (int i = 1; i <= n; i++) {
            add_sq += (n - 2) * a[i] * a[i];
            add_sq += (n - 2) * b[i] * b[i];
            S += a[i];
            S += b[i];
        }
        for (int i = 0; i < maxK; i++) {
            if (cur[i]) {
                ll he = i;
                ll we = S - i;
                best = min(best, he * he + we * we);
            }
        }
        cout << best + add_sq << '\n';
    }
    return 0;
}