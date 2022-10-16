#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 300000 + 10;

vector<pii> adj[maxn];
int value[maxn];

vector<int> active;

int solve(int s, int p=-1){
    int x = value[s] == 1;

    for (auto e : adj[s]){
        int u = e.first, idx = e.second;
        if (u == p) continue;
        int val = solve(u, s);
        if (val) active.push_back(idx);
        x ^= val;
    }

    return x;
}

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    memset(ds, -1, sizeof ds);

    int p = 0;
    int pos = -1;

    for (int i = 1; i <= n; ++i){
        cin >> value[i];
        p ^= int(value[i] == 1);
        if (value[i] == -1)
            pos = i;
    }

    if (p){
        if (pos != -1){
            value[pos] = 1;
        }
        else{
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        if (join(u, v)){
            adj[u].push_back({v, i+1});
            adj[v].push_back({u, i+1});
        }
    }

    solve(1);

    cout << active.size() << endl;

    for (auto u : active)
        cout << u << endl;

    return 0;
}