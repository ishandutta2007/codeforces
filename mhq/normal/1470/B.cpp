#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e6 + 10;
int n, q;
int a[maxN];
int lp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = 2 * i; j < maxN; j += i) lp[j] = i;
        }
    }
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n;
        map<int,int> mp;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            int res = 1;
            int x = a[i];
            while (x > 1) {
                int p = lp[x];
                int cc = 0;
                while (x % p == 0) {
                    cc ^= 1;
                    x /= p;
                }
                if (cc) res *= p;
            }
            mp[res]++;
        }
        int st = 0;
        int after = 0;
        int cur_z = 0;
        for (auto& it : mp) {
            st = max(st, it.second);
            if (it.first == 1 || it.second % 2 == 0) {
                cur_z += it.second;
            }
        }
        after = max(st, cur_z);
        cin >> q;
        while (q--) {
            ll w;
            cin >> w;
            if (w == 0) cout << st << '\n';
            else cout << after << '\n';
        }
    }
    return 0;
}