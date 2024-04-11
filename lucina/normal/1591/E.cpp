#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
vector <int> g[nax];
int n, nq;
int ans[nax];
int a[nax];
array <int, 3> Q[nax];
vector <tuple <int, int, int>> queries[nax];

int64_t f[nax];
void add(int x, int y) {
    if (x == 0) return;
    for (; x < nax ; x += x & -x)
        f[x] += y;
}
int64_t get(int x) {
    int res = 0;
    for (; x > 0 ; x -= x & -x)
        res += f[x];
    return res;
}
int64_t get(int l, int r) {
    if (l > r) return 0;
    return get(r) - get(l - 1);
}

int cnt[nax];
set <int> V[nax];
void dfs(int v, int parent) {
    int x = a[v];
    add(cnt[x], -1);
    if (V[cnt[x]].count(x)) {
        V[cnt[x]].erase(x);
    }
    cnt[x] += 1;
    V[cnt[x]].insert(x);

    add(cnt[x], 1);
    for (auto [l, k, id] : queries[v]) {
        int L = l, R = n;
        int& cur_ans = ans[id];
        cur_ans = -1;
        while (L <= R) {
            int mid = L + R >> 1;
            if (get(l, mid) >= k) {
                cur_ans = mid;
                R = mid - 1;
            } else L = mid + 1;
        }
        if (cur_ans != -1) {
            cur_ans = *V[cur_ans].begin();
        }
    }
    for (int to : g[v]) {
        if (to == parent) continue;
        dfs(to, v);
    }
    add(cnt[x], -1);
    V[cnt[x]].erase(x);
    cnt[x] -= 1;
    V[cnt[x]].insert(x);
    add(cnt[x], 1);
}
void solve() {
    cin >> n >> nq;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    for (int i = 2 ; i <= n ; ++ i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for (int i = 1 ; i <= nq ; ++ i) {
        cin >> Q[i][0] >> Q[i][1] >> Q[i][2];
        queries[Q[i][0]].emplace_back(Q[i][1], Q[i][2], i);
    }
    dfs(1, 0);
    for (int i = 1 ; i <= nq ; ++ i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
        for (int i = 1 ; i <= n ; ++ i)
            g[i].clear();
        for (int i = 1 ; i <= n ; ++ i)
            queries[i].clear();
    }
}