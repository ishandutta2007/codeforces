#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

vector<pii> adj[maxn];

int gauss[32];
int value[maxn];

int add(int v){
    while (v){
        int p = __lg(v);

        if (gauss[p] == 0){
            gauss[p] = v;
            break;
        }
        else
            v ^= gauss[p];
    }
    return v;
}

int get(int v){
    for (int i = __lg(v); ~i; --i){
        if (gauss[i] && (v >> i & 1))
            v ^= gauss[i];
    }
    return v;
}

void dfs(int s){
    for (auto e : adj[s]){
        int u = e.first, x = e.second;

        if (value[u] == -1){
            value[u] = value[s] ^ x;
            dfs(u);
        }
        else{
            add(value[s] ^ value[u] ^ x);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int u, v, x;
        cin >> u >> v >> x;

        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    memset(value, -1, sizeof value);

    value[1] = 0;
    dfs(1);

    cout << get(value[n]) << endl;

    return 0;
}