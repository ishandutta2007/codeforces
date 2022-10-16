#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100010;

vi adj[maxn];
int col[maxn];

bool ok(int u, int p){
    for (auto v : adj[u]){
        if (v == p) continue;

        if (p != -1 && col[v] != col[u])
            return false;

        if (!ok(v, u))
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<pii> edges(n - 1);

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;

        edges[i - 1] = {u, v};

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        cin >> col[i];

    int U = -1, V = -1;

    for (int i = 0; i < n - 1; ++i){
        int u = edges[i].first, v = edges[i].second;
        if (col[u] != col[v]){
            U = u, V = v;
            break;
        }
    }

    if (U == -1){
        cout << "YES" << endl;
        cout << 1 << endl;
    }
    else{
        if (ok(U, -1))
            cout << "YES" << endl << U << endl;
        else if (ok(V, -1))
            cout << "YES" << endl << V << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}