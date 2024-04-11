#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;
const int64 mod = 1000000007;

vector<pii> edges;
vector<int> r[maxn];
vector<int> group[maxn];
vector<int> adj[maxn];
bool solved[maxn];

int ds[maxn];

int root(int a){
    return ds[a] < 0 ? a : ds[a] = root(ds[a]);
}

bool join(int a, int b){
    a = root(a), b = root(b);
    if (a == b) return false;
    if (ds[a] > ds[b]) swap(a, b);
    ds[a] += ds[b];
    ds[b] = a;
    return true;
}

bool same(pii &a){
    return abs(a.first) == abs(a.second);
}

vector<int> L;

void build(int n, bool cycle=false){
    if (!cycle){
        int prev = -1;
        if (r[n].size() > 1){
            if (same(edges[r[n][0]])){
                L.push_back(edges[r[n][0]].first);
                L.push_back(edges[r[n][0]].second);
                prev = r[n][0];
            }
            else{
                L.push_back(edges[r[n][1]].first);
                L.push_back(edges[r[n][1]].second);
                prev = r[n][1];
            }
        }
        else{
            int u = edges[r[n][0]].first;
            int v = edges[r[n][0]].second;
            if (abs(u) != n) swap(u, v);
            L.push_back(u);
            L.push_back(v);

            prev = r[n][0];
            n = abs(v);
        }

        while (r[n].size() > 1){
            prev = r[n][0] + r[n][1] - prev;

            auto e = edges[prev];

            if (abs(e.first) != n)
                swap(e.first, e.second);

            L.push_back(e.first);
            L.push_back(e.second);

            int nn = abs(e.second);
            if (nn == n) break;
            n = nn;
        }
    }
    else{
        int beg = abs(n);
        int prev = r[beg][0];

        auto e = edges[prev];
        if (abs(e.first) != beg)
            swap(e.first, e.second);

        L.push_back(e.first);
        L.push_back(e.second);

        n = abs(e.second);

        while (n != beg){
            prev = r[n][0] + r[n][1] - prev;

            auto e = edges[prev];

            if (abs(e.first) != n)
                swap(e.first, e.second);

            L.push_back(e.first);
            L.push_back(e.second);

            n = abs(e.second);
        }
    }
}

int64 dp[maxn][2][2][2];

pair<int64,int64> calc(){
    dp[0][0][0][0] = 1;
    dp[0][1][1][0] = 1;

    int t = 1;

    for (int i = 0; i < (int)L.size(); i += 2, ++t){
        int u = L[i], v = L[i + 1];

        bool d = abs(u) == abs(v);

        for (int k = 0; k < 2; ++k){
            if (v < 0){
                dp[t][k][0][0] = (dp[t - 1][k][0][1] + (d ? 0 : dp[t - 1][k][1][1])) % mod;
                dp[t][k][0][1] = (dp[t - 1][k][0][0] + (d ? 0 : dp[t - 1][k][1][0])) % mod;

                if (u < 0){
                    dp[t][k][1][0] = (dp[t - 1][k][1][0] + (d ? 0 : dp[t - 1][k][0][1])) % mod;
                    dp[t][k][1][1] = (dp[t - 1][k][1][1] + (d ? 0 : dp[t - 1][k][0][0])) % mod;
                }
                else{
                    dp[t][k][1][0] = (dp[t - 1][k][1][1] + (d ? 0 : dp[t - 1][k][0][0])) % mod;
                    dp[t][k][1][1] = (dp[t - 1][k][1][0] + (d ? 0 : dp[t - 1][k][0][1])) % mod;
                }
            }
            else{
                dp[t][k][1][0] = ((d ? 0 : dp[t - 1][k][0][1]) + dp[t - 1][k][1][1]) % mod;
                dp[t][k][1][1] = ((d ? 0 : dp[t - 1][k][0][0]) + dp[t - 1][k][1][0]) % mod;

                if (u < 0){
                    dp[t][k][0][0] = (dp[t - 1][k][0][1] + (d ? 0 : dp[t - 1][k][1][0])) % mod;
                    dp[t][k][0][1] = (dp[t - 1][k][0][0] + (d ? 0 : dp[t - 1][k][1][1])) % mod;
                }
                else{
                    dp[t][k][0][0] = (dp[t - 1][k][0][0] + (d ? 0 : dp[t - 1][k][1][1])) % mod;
                    dp[t][k][0][1] = (dp[t - 1][k][0][1] + (d ? 0 : dp[t - 1][k][1][0])) % mod;
                }
            }
        }
    }

    --t;

    int64 b0 = 0, b1 = 0;


    if (abs(L[0]) == abs(L.back())){
        b1 = (dp[t][0][0][1] + dp[t][1][1][1]) % mod;
        b0 = (dp[t][0][0][0] + dp[t][1][1][0]) % mod;
    }
    else{
        for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j){
            b0 = (b0 + dp[t][i][j][0]) % mod;
            b1 = (b1 + dp[t][i][j][1]) % mod;
        }
    }

    return {b0, b1};
}

pair<int64,int64> solve(int g){
    if (r[g].empty()){
        return {2, 0};
    }

    L.clear();

    for (auto n : group[g]){
        if (r[n].size() == 1 || same(edges[r[n][0]]) || same(edges[r[n][1]])){
            build(n);
            return calc();
        }
    }

    build(g, true);
    return calc();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    memset(ds, -1, sizeof ds);

    int n, m;
    cin >> m >> n;

    for (int i = 0; i < m; ++i){
        int t, a, b;
        cin >> t >> a;
        if (t == 2) cin >> b;
        else b = a;

        r[abs(a)].push_back(i);
        if (abs(b) != abs(a)) r[abs(b)].push_back(i);
        edges.push_back(pii(a, b));

        join(abs(a), abs(b));
    }

    for (int i = 1; i <= n; ++i)
        group[root(i)].push_back(i);

    int64 b0 = 1, b1 = 0;

    for (int i = 1; i <= n; ++i){
        int g = root(i);

        if (solved[g]) continue;
        solved[g] = true;

        auto p = solve(g);

        int64 t0 = b0 * p.first % mod + b1 * p.second % mod;
        int64 t1 = b0 * p.second % mod + b1 * p.first % mod;
        t0 %= mod;
        t1 %= mod;
        b0 = t0, b1 = t1;
    }

    cout << b1 << endl;

    return 0;
}