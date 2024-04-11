#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 1;

int ds[maxn];

int root(int a){
    return ds[a] < 0 ? a : ds[a] = root(ds[a]);
}

bool join(int a, int b){
    a = root(a), b = root(b);
    if (a == b) return false;
    if (ds[a] < ds[b]) swap(a, b);
    ds[b] += ds[a];
    ds[a] = b;
    return true;
}

vi adj[maxn];
bool R[maxn];

int open[maxn], close[maxn], tmm = 0;

void dfs(int s){
    open[s] = tmm++;
    for (auto u : adj[s])
        dfs(u);
    close[s] = tmm++;
}

bool ischildren(int u, int v){
    return open[v] <= open[u] && close[u] <= close[v];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(ds, -1, sizeof ds);

    int n, m;

    cin >> n >> m;

    vector<pii> query;
    vector<vector<pii>> ancestor;
    vector<bool> ans;

    for (int i = 0; i < m; ++i){
        int t; cin >> t;

        if (t == 1){
            int u, v;
            cin >> u >> v;
            adj[v].push_back(u);
            R[u] = true;
            query.push_back({u, v});
        }
        else if (t == 2){
            int q; cin >> q;
            query.push_back({-1, q});
            ancestor.push_back({});
        }
        else{
            int u, q; cin >> u >> q;
            ancestor[q - 1].push_back({u, ans.size()});
            ans.push_back(false);
        }
    }

    for (int i = 1; i <= n; ++i)
        if (!R[i]) dfs(i);

    int quiz = -1;

    for (auto q : query){
        if (q.first > -1){
            join(q.first, q.second);
        }
        else{
            ++quiz;
            int u = q.second;
            for (auto cand : ancestor[quiz]){
                int v = cand.first;
                if (root(u) == root(v) && ischildren(u, v))
                    ans[cand.second] = true;
            }
        }
    }

    for (auto a : ans)
        cout << (a ? "YES" : "NO") << endl;

    return 0;
}