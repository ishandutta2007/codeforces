#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
vector<int> g[maxN];
int n;
int h[maxN];
int pref_max[maxN];
int pref_min[maxN];
int sub[maxN];
int hei[maxN];
void dfs1(int v, int p) {
    sub[v] = h[v];
    for (int to : g[v]) {
        if (to == p) continue;
        hei[to] = hei[v] + 1;
        dfs1(to, v);
        sub[v] = max(sub[v], sub[to]);
    }
}
int up[maxN];
void dfs2(int v, int p) {
    vector<pair<int,int>> all;
    for (int to : g[v]) {
        if (to == p) continue;
        all.emplace_back(sub[to], to);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (int to : g[v]) {
        if (to == p) continue;
        up[to] = max(up[v], h[v]);
        if (to != all[0].second) up[to] = max(up[to], all[0].first);
        else if ((int)all.size() > 1) up[to] = max(up[to], all[1].first);
    }
    for (int to : g[v]) {
        if (to == p) continue;
        dfs2(to, v);
    }
}
int cnt_leaves[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<int> he;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        he.emplace_back(h[i]);
    }
    sort(he.begin(), he.end());
    he.erase(unique(he.begin(), he.end()), he.end());
    for (int i = 1; i <= n; i++) {
        h[i] = lower_bound(he.begin(), he.end(), h[i]) - he.begin() + 1;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs1(1, -1);
    up[1] = 0;
    dfs2(1, -1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> other;
        for (int to : g[i]) {
            if (hei[to] > hei[i]) other.emplace_back(sub[to]);
        }
        if (i != 1) other.emplace_back(up[i]);
        sort(other.begin(), other.end());
        reverse(other.begin(), other.end());
        assert(!other.empty());
        if (other.size() == 1) {
            cnt_leaves[1]++;
            cnt_leaves[h[i] + 1]--;
        }
        else {
            if (other[1] >= h[i]) {
                //nothing
            }
            else {
                cnt_leaves[other[1] + 1]++;
                cnt_leaves[h[i] + 1]--;
            }
        }
    }
    for (int i = 1; i <= he.size(); i++) {
        cnt_leaves[i] += cnt_leaves[i - 1];
//        cout << cnt_leaves[i] << " ... " << endl;
        assert(cnt_leaves[i] > 0);
    }
    for (int i = 1; i <= he.size(); i++) {
        cnt_leaves[i] = max(cnt_leaves[i], 2);
    }
    for (int i = 1; i <= he.size(); i++) {
        int delta = cnt_leaves[i];
        if (i != (int)he.size()) delta -= cnt_leaves[i + 1];
        assert(delta >= 0);
//        cout << cnt_leaves[i] << " ? " << endl;
        ans += 1LL * delta * he[i - 1];
    }
    cout << ans << '\n';
    return 0;
}