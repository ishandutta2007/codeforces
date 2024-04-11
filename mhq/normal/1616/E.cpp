#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
ll fenw[maxN];
int cnt[26];
vector<int> gg[26];
int n;
void upd(int v, int by) {
    while (v <= n) {
        fenw[v] += by;
        v = (v | (v - 1)) + 1;
    }
}
ll get(int r) {
    ll ans = 0;
    while (r > 0) {
        ans += fenw[r];
        r &= (r - 1);
    }
    return ans;
}
ll get(int l, int r) {
    if (l > r) return 0;
    return get(r) - get(l - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n;
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < 26; i++) gg[i].clear();
        for (int i = 0; i < s.size(); i++) {
            gg[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            reverse(gg[i].begin(), gg[i].end());
        }
        for (int i = 0; i <= n; i++) {
            fenw[i] = 0;
        }
        ll ans = 1e18;
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            int best = 1e9;
            for (int z = 0; z < 26; z++) {
                if (!gg[z].empty() && z < (int)(t[i] - 'a')) {
                    best = min(best, gg[z].back());
                }
            }
            if (best < n) {
                ll he = cur + best - get(best);
                ans = min(ans, he);
            }
            if (gg[t[i] - 'a'].empty()) break;
            int pos = gg[t[i] - 'a'].back();
            gg[t[i] - 'a'].pop_back();
            cur += pos - get(pos);
            upd(pos + 1, 1);
        }
        if (ans > 1e17) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}