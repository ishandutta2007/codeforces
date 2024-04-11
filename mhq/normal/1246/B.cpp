#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = (int)1e5 + 100;
int a[maxN];
int lp[maxN];
vector < pair < int, int > > fact[maxN];
map < vector < pair < int, int > >, int > mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = 2 * i; j < maxN; j += i) lp[j] = i;
        }
    }
    for (int i = 2; i < maxN; i++) {
        int c = i;
        while (c > 1) {
            int p = lp[c];
            int ex = 0;
            while (c % p == 0) {
                c /= p;
                ex++;
            }
            if (ex % k == 0) {
                continue;
            }
            fact[i].emplace_back(p, ex % k);
        }
        sort(fact[i].begin(), fact[i].end());
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vector < pair < int, int > > need;
        for (auto it : fact[a[i]]) {
            need.emplace_back(it.first, k - it.second);
        }
        ans += mp[need];
        mp[fact[a[i]]]++;
    }
    cout << ans;
    return 0;
}