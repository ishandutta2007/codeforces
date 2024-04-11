#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int root(int a, vi &ds){
    return ds[a] < 0 ? a : ds[a] = root(ds[a], ds);
}

bool join(int a, int b, vi &ds){
    a = root(a, ds), b = root(b, ds);
    if (a == b) return false;
    if (ds[a] < ds[b]) swap(a, b);
    ds[b] += ds[a];
    ds[a] = b;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;

    vector<vi> M(n, vi(m));
    vector<int> ds(n * m, -1);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> M[i][j];

    vector<vi> adj(n * m);
    vi num(n * m), deg(n * m);

    // Merging

    for (int i = 0; i < n; ++i){
        vector<pii> V(m);
        for (int j = 0; j < m; ++j)
            V[j] = {M[i][j], i * m + j};

        sort(V.begin(), V.end());

        for (int j = 1; j < m; ++j){
            if (V[j - 1].first == V[j].first)
                join( V[j - 1].second, V[j].second, ds );
        }
    }

    for (int j = 0; j < m; ++j){
        vector<pii> V(n);

        for (int i = 0; i < n; ++i)
            V[i] = {M[i][j], i * m + j};

        sort(V.begin(), V.end());

        for (int i = 1; i < n; ++i){
            if (V[i - 1].first == V[i].first)
                join(V[i - 1].second, V[i].second, ds);
        }
    }

    // Building DAG

    for (int i = 0; i < n; ++i){
        vector<pii> V(m);
        for (int j = 0; j < m; ++j)
            V[j] = {M[i][j], i * m + j};

        sort(V.begin(), V.end());

        for (int j = 1; j < m; ++j){
            if (V[j - 1].first < V[j].first){
                adj[ root(V[j - 1].second, ds) ].push_back( root(V[j].second, ds) );
                deg[ root(V[j].second, ds) ]++;
            }
        }
    }

    for (int j = 0; j < m; ++j){
        vector<pii> V(n);

        for (int i = 0; i < n; ++i)
            V[i] = {M[i][j], i * m + j};

        sort(V.begin(), V.end());

        for (int i = 1; i < n; ++i){
            if (V[i - 1].first < V[i].first){
                adj[ root(V[i - 1].second, ds) ].push_back( root(V[i].second, ds) );
                deg[ root(V[i].second, ds) ]++;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < n * m; ++i){
        if (root(i, ds) == i && !deg[i]){
            q.push(i);
            num[i] = 1;
        }
    }

    while (!q.empty()){
        int u = q.front(); q.pop();

        for (auto v : adj[u]){
            num[v] = max(num[v], num[u] + 1);
            deg[v]--;

            if (deg[v] == 0) q.push(v);
        }
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            int u = root(i * m + j, ds);
            cout << num[u] << " ";
        }
        cout << endl;
    }

    return 0;
}