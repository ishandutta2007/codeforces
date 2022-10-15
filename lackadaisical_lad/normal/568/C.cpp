#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int n;
vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    n = g.size();
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void solve() {
    string alp;
    cin >> alp;
    int l = alp.size();
    vector<int> kek(l);
    vector<int> low(2, l + 1);
    for (int i = 0; i < l; i++) {
        kek[i] = alp[i] == 'V';
        low[kek[i]] = min(low[kek[i]], i);
    }
    sort(low.begin(), low.end());
    int n, m;
    cin >> n >> m;
    g.resize(n * 2);
    gt.resize(n * 2);

    auto add_edge = [&](int p1, int t1, int p2, int t2) {
        int u = p1 * 2 + t1;
        int v = p2 * 2 + t2;
        g[u].push_back(v);
        g[v ^ 1].push_back(u ^ 1);
        gt[v].push_back(u);
        gt[u ^ 1].push_back(v ^ 1);
    };

    auto del_edge = [&](int p1, int t1, int p2, int t2) {
        int u = p1 * 2 + t1;
        int v = p2 * 2 + t2;
        g[u].pop_back();
        g[v ^ 1].pop_back();
        gt[v].pop_back();
        gt[u ^ 1].pop_back();
    };

    for (int i = 0; i < m; i++) {
        int p1, p2;
        char t1, t2;
        cin >> p1 >> t1 >> p2 >> t2;
        p1--, p2--;
        t1 = t1 == 'V';
        t2 = t2 == 'V';
        add_edge(p1, t1, p2, t2);   
    }
    if (low[0] >= l) {
        for (int i = 0; i < n; i++) {
            add_edge(i, 1, i, 0);
        }
    }
    if (low[1] >= l) {
        for (int i = 0; i < n; i++) {
            add_edge(i, 0, i, 1);
        }
    }

    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        add_edge(i, kek[s[i] - 'a'] ^ 1, i, kek[s[i] - 'a']);
    }
    if (solve_2SAT()) {
        cout << s << '\n';
        return;
    }
    for (int i = n - 1; i >= 0; i--) {
        del_edge(i, kek[s[i] - 'a'] ^ 1, i, kek[s[i] - 'a']);
        vector<int> vis(2);
        for (int j = s[i] - 'a' + 1; j < l; j++) {
            if (vis[kek[j]]) continue;
            vis[kek[j]] = 1;
            add_edge(i, kek[j] ^ 1, i, kek[j]);
            if (solve_2SAT()) {
                for (int k = 0; k < i; k++) {
                    cout << s[k];
                }
                cout << char('a' + j);
                for (int k = i + 1; k < n; k++) {
                    for (int j : low) {
                        if (j >= l) continue;
                        add_edge(k, kek[j] ^ 1, k, kek[j]);
                        if (solve_2SAT()) {
                            cout << char('a' + j);
                            break;
                        }
                        del_edge(k, kek[j] ^ 1, k, kek[j]);
                    }
                }
                cout << endl;
                return;
            }
            del_edge(i, kek[j] ^ 1, i, kek[j]);
        }
    }
    cout << "-1\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}