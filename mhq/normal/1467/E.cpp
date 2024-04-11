#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
int cnt[maxN];
vector<int> by[maxN];
int a[maxN];
int add[maxN];
int tin[maxN];
int tout[maxN];
int timer = 0;

bool is_anc(int v, int batya) {
    return tin[batya] <= tin[v] && tout[v] <= tout[batya];
}

vector<int> g[maxN];

void dfs(int v, int p) {
    tin[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
    }
    tout[v] = timer++;
}
int NEED = 0;
vector<int> F[maxN];
void dfs2(int v, int p) {
    for (int to : g[v]) {
        if (to == p) continue;
        dfs2(to, v);
    }
    if (cnt[a[v]] == 1) return;
    int who = (by[a[v]][0] == v ? by[a[v]][1] : by[a[v]][0]);
    int to_who = -1;
    for (int to : g[v]) {
        if (to == p) continue;
        if (is_anc(who, to)) to_who = to;
    }
    if (to_who != -1) {
        if (F[a[v]][1] < tin[to_who] || F[a[v]].back() > tout[to_who]) {
            cout << 0;
            exit(0);
        }
    }
    else {
        auto it = lower_bound(F[a[v]].begin(), F[a[v]].end(), tin[v]) - F[a[v]].begin();
        if (it > 0 && F[a[v]][it - 1] >= tin[v] && F[a[v]][it - 1] <= tout[v]) {
            cout << 0;
            exit(0);
        }
        if (it + 1 < F[a[v]].size() && F[a[v]][it + 1] >= tin[v] && F[a[v]][it + 1] <= tout[v]) {
            cout << 0;
            exit(0);
        }
    }
    if (to_who != -1) {
        add[to_who]++;
        NEED++;
    }
    else {
        add[1]++;
        add[v]--;
        NEED++;
    }

}
void dfs3(int v, int p) {
    for (int to : g[v]) {
        if (to == p) continue;
        add[to] += add[v];
        dfs3(to, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<int> xx;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        xx.emplace_back(a[i]);
    }
    sort(xx.begin(), xx.end());
    xx.erase(unique(xx.begin(), xx.end()), xx.end());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(xx.begin(), xx.end(), a[i]) - xx.begin();
        cnt[a[i]]++;
        by[a[i]].emplace_back(i);
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        F[a[i]].emplace_back(tin[i]);
    }
    for (int i = 0; i <= n; i++) sort(F[i].begin(), F[i].end());
    dfs2(1, -1);
    dfs3(1, -1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (add[i] == NEED) ans++;
    }
    cout << ans << '\n';
    return 0;
}