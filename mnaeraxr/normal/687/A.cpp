#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int color[maxn];
vi adj[maxn];

bool dfs(int s, int c){
    color[s] = c;
    for (auto u : adj[s]){
        if (color[u]){
            if (color[u] == c)
                return false;
        }
        else{
            bool ok = dfs(u, c * -1);
            if (!ok) return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ok = true;

    for (int i = 1; i <= n && ok; ++i)
        if (!color[i]) ok = dfs(i, 1);

    if (!ok) cout << -1 << endl;
    else{
        vector<int> V1, V2;
        for (int i = 1; i <= n; ++i)
            (color[i] == 1 ? V1 : V2).push_back(i);

        cout << V1.size() << endl;
        for (auto u : V1) cout << u << " ";
        cout << endl;

        cout << V2.size() << endl;
        for (auto u : V2) cout << u << " ";
        cout << endl;
    }

    return 0;
}