#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 2 * (int)1e5 + 100;
int a[maxN];
int bck[maxN];
vector < int > byId[maxN];
vector < pair < int, int > > ask[maxN];
int ans[maxN];
int fenw[maxN];
void upd(int v, int d) {
    while (v <= n) {
        fenw[v] += d;
        v = (v | (v - 1)) + 1;
    }
}
int lower_bound(int lim) {
    int lg = 21;
    int res = 0;
    for (int k = lg; k >= 0; k--) {
        int p = (res + (1 << k));
        if (p <= n && fenw[p] < lim) {
            lim -= fenw[p];
            res += (1 << k);
        }
    }
    return res + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < int > all;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all.push_back(a[i]);
    }
    cin >> m;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 1; i <= n; i++) {
        bck[i] = a[i];
        a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
        byId[a[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        int k, pos;
        cin >> k >> pos;
        ask[k].emplace_back(make_pair(pos, i));
    }
    int cur_sz = 0;
    for (int i = n; i >= 1; i--) {
        for (int pos : byId[i]) {
            upd(pos, 1);
            cur_sz++;
            for (auto t : ask[cur_sz]) {
                ans[t.second] = bck[lower_bound(t.first)];
            }
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
    return 0;
}