#include <bits/stdc++.h>

using namespace std;

const int maxc = 200025;
const int maxn = 200025;
const int mod = 998244353;

vector<int> idx[maxc];
bool sieve[maxc];
vector<int> prs;

vector<int> g[maxn];
int pa[20][maxn];
int dfn[maxn], dfc;
int dep[maxn];
void dfs(int i, int f) {
    dfn[i] = dfc++;
    for (int j: g[i]) {
        if (j == f) continue;
        dep[j] = dep[i] + 1;
        pa[0][j] = i;
        for (int l = 0; l + 1 < 20; l++)
            pa[l+1][j] = pa[l][pa[l][j]];
        dfs(j, i);
    }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    int d = dep[b] - dep[a];
    for (int i = 0; i < 20; i++)
        if (d >> i & 1)
            b = pa[i][b];
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--)
        if (pa[i][a] != pa[i][b])
            a = pa[i][a], b = pa[i][b];
    return pa[0][a];
}

vector<pair<int,int>> build(vector<int> &vs) {
    vector<pair<int,int>> res;
    sort(vs.begin(), vs.end(), [](int i, int j) {
        return dfn[i] < dfn[j];
    });
    vector<int> s = {0};
    for (int v: vs) if (v != 0) {
        int o = lca(v, s.back());
        if (o != s.back()) {
            while (s.size() >= 2 and dfn[s[s.size() - 2]] >= dfn[o]) {
                res.emplace_back(s[s.size()-2], s.back());
                s.pop_back();
            }
            if (s.back() != o) {
                res.emplace_back(s.back(), o);
                s.back() = o;
            }
        }
        s.push_back(v);
    }
    for (size_t i = 1; i < s.size(); i++)
        res.emplace_back(s[i - 1], s[i]);
    return res;
}

bool mark[maxn];
vector<pair<int,int>> tr[maxn];
pair<int,int> dfs1(int n, int i, int f) {
    int64_t s = mark[i];
    int64_t res = 0;
    for (auto [j, w]: tr[i]) {
        if (j == f) continue;
        auto [sz, ans] = dfs1(n, j, i);
        s += sz;
        res += ans;
        res += 1LL * sz * (n - sz) % mod * w;
        res %= mod;
    }
    return {s, res};
}

int calc(vector<int> &vs) {
    {
        auto es = build(vs);
        for (auto [a, b]: es) {
            tr[a].clear();
            tr[b].clear();
            mark[a] = mark[b] = false;
        }
        for (auto [a, b]: es) {
            // cerr << "edge " << a << ' ' << b << endl;
            int len = abs(dep[a] - dep[b]);
            tr[a].emplace_back(b, len);
            tr[b].emplace_back(a, len);
        }
        for (int x: vs)
            mark[x] = true;
    }
    auto [f, s] = dfs1(vs.size(), 0, -1);
    // cerr << "result = " << f << ' ' << s << endl;
    return dfs1(vs.size(), 0, -1).second;
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        idx[x].push_back(i);
    }

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);

    for (int i = 2; i < maxc; i++) {
        if (!sieve[i]) {
            prs.push_back(i);
        }
        for (int p: prs) {
            if (i * p >= maxc) break;
            sieve[i * p] = true;
            if (i % p == 0) break;
        }
    }

    const int inv2 = (mod + 1) / 2;

    int64_t ans = 0;
    for (int p: prs) {
        vector<int> tmp;
        for (int i = p; i < maxc; i += p)
            for (int j: idx[i])
                tmp.push_back(j);
        int sz = tmp.size();
        if (sz == 0) continue;
        // if (sz <= 2) continue;
        // cerr << "p = " << p << "; ";
        // for (int j: tmp)
        //     cerr << j+1 << ",";
        // cerr << "\b ";
        // cerr << endl;
        ans += 1LL * calc(tmp) * (sz - 2) % mod * inv2 % mod;
        ans %= mod;
    }

    cout << ans << '\n';
}