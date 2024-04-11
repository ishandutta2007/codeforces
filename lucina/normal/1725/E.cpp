#include<bits/stdc++.h>
using namespace std;
const int L = 2e5 + 10;
const int nax = 2e5 + 10;
const int MOD = 998244353;
const int LG = 17;

inline void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
inline void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
inline int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
inline int sub(int a, int b){a-=b;if (a<0)a+=MOD;return a;}
inline int mul(int a, int b){return 1ll*a*b%MOD;}

int sm[L];
vector <int> at_p[L];
int n;
int par[nax][LG];
vector <int> g[nax];
int tin[nax];
int tout[nax];
int timer;
bool valid[nax];
int cnt[nax];
int sum[nax];
int dep[nax];

inline bool ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v) {
    if (ancestor(u, v)) return u;
    if (ancestor(v, u)) return v;

    for (int j = LG - 1 ; j >= 0 ; -- j) {
        if (!ancestor(par[u][j], v)) {
            u = par[u][j];
        }
    }
    return par[u][0];
}
void dfs_lca(int v, int parent) {
    par[v][0] = parent;
    tin[v] = ++timer;
    for (int j = 1 ; j < LG ; ++ j)
        par[v][j] = par[par[v][j - 1]][j - 1];

    for (int to : g[v]) {
        if (to == parent) continue;
        dep[to] = dep[v] + 1;
        dfs_lca(to, v);
    }
    tout[v] = ++ timer;
}
int ans = 0;
int sum_distance[nax];
int all_valid;
int cnt_sub[nax];
int sum_two_chain[nax];
int cnt_two_chain[nax];

void dfs_sum_distance(int v) {
    for (int to : g[v]) {
        dfs_sum_distance(to);
        plusle(sum_distance[v], add(sum_distance[to], mul(cnt_sub[to], dep[to] - dep[v])));
        cnt_sub[v] += cnt_sub[to];
    }
    if (valid[v]) cnt_sub[v] += 1;
}

void dfs(int v, int cnt_valid, int sum_dep_valid, int sum_dist) {

    int cnt_way = 0; int low_sum = 0;
    int cnt_cried = 0, sum_cried = 0;
    int s, su;
    for (int to : g[v]) {
        int new_sum_dist = add(mul(all_valid - cnt_sub[to], dep[to] - dep[v]),
        sub(add(sum_distance[v], sum_dist), add(sum_distance[to], mul(cnt_sub[to], (dep[to] - dep[v])))));

        dfs(to, cnt_valid + valid[v], add(sum_dep_valid, valid[v] * dep[v]), new_sum_dist);
            int c2cv = mul(cnt[to], cnt[v]);

        {
            s = mul(sum[to], cnt[v]);
            su = mul(2, mul(dep[v], c2cv));
            plusle(s, mul(sum[v], cnt[to]));
            low_sum = add(low_sum, s);
            if (valid[v]) plusle(ans, sub(s, su));

            s = mul(sum_two_chain[to], cnt[v]);
            plusle(s, mul(sum[v], cnt_two_chain[to]));
            su = mul(dep[v], mul(cnt_two_chain[to], cnt[v])) * 2 % MOD;
            plusle(ans, sub(s, su));
            s = mul(sum[to], cnt_two_chain[v]);
            plusle(s, mul(sum_two_chain[v], cnt[to]));
            su = mul(mul(2, dep[v]), mul(cnt_two_chain[v], cnt[to]));
            plusle(ans, sub(s, su));

            s = mul(sum_cried, cnt[to]);
            plusle(s, mul(sum[to], cnt_cried));
            su = mul(mul(3, dep[v]), mul(cnt[to], cnt_cried));
            plusle(ans, sub(s, su));
            plusle(sum_cried, add(mul(cnt[v], sum[to]), mul(sum[v], cnt[to])));
            plusle(cnt_cried, c2cv);
        }

        if (valid[v]) {
            s = mul(sum[to], cnt_valid);
            su = mul(cnt[to], sum_dep_valid);
            ans = add(ans, sub(s, su));
        }

        plusle(cnt_way, c2cv);
        plusle(sum[v], sum[to]);
        cnt[v] += cnt[to];
        plusle(cnt_two_chain[v], cnt_two_chain[to]);
        plusle(sum_two_chain[v], sum_two_chain[to]);
    }

    int cnt_dy = sub(mul(low_sum, all_valid - cnt_sub[v]), mul(mul(2, dep[v]), mul(cnt_way, all_valid - cnt_sub[v])));
    int cnt_dx = mul(cnt_way, sum_dist);
    plusle(ans, add(cnt_dy, cnt_dx));
    if (valid[v]) plusle(cnt_two_chain[v], cnt[v]), plusle(sum_two_chain[v], sum[v]), plusle(sum[v], dep[v]), cnt[v] += 1;
}

void solve_prime(int p) {
    vector <int> &g = at_p[p];
    all_valid = 0;
    for (int x : g) {
        valid[x] = true;
        all_valid += 1;
    }
    sort(g.begin(), g.end(), [&](int u, int v) {
            return tin[u] < tin[v];
         });
    for (int i = 0, k = g.size() ; i + 1 < k ; ++ i) {
        g.push_back(lca(g[i], g[i + 1]));
    }
    g.push_back(1);
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());

    sort(g.begin(), g.end(), [&](int u, int v) {
            return tin[u] < tin[v];
    });

    vector <int> stk;
    stk.push_back(g[0]);

    for (int i = 1 ; i < g.size() ; ++ i) {
        while (!stk.empty() && !ancestor(stk.back(), g[i])) stk.pop_back();
        ::g[stk.back()].push_back(g[i]);
        stk.push_back(g[i]);
    }

    dfs_sum_distance(1);
    dfs(1, 0, 0, 0);

    for (int x : g) {
        cnt[x] = sum[x] = valid[x] = cnt_sub[x] = sum_distance[x] = sum_two_chain[x] = cnt_two_chain[x] = 0;
        ::g[x].clear();
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    for (int i = 2 ; i < L ; ++ i) {
        if (sm[i]) continue;
        sm[i] = i;
        for (int j = i ; j < L ; j += i)
            if (!sm[j]) sm[j] = i;
    }
    tout[0] = 1e9;
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        int x; cin >> x;
        while (x > 1) {
            int s = sm[x];
            do {
                x /= s;
            } while (x % s == 0);
            at_p[s].push_back(i);
        }
    }
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs_lca(1, 0);
    for (int i = 1 ; i <= n ; ++ i) g[i].clear();

    for (int i = 2 ; i < L ; ++ i)
        if (!at_p[i].empty()) solve_prime(i);

    cout << ans << '\n';
}