//In the name God
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int maxN = 1000 * 100 + 10; 

int cnt[maxN]; 
int k;
int par[maxN];
pair<int, pii> edges[maxN];

int dfind(int u) { 
    return par[u] < 0 ? u : par[u] = dfind(par[u]);
}

bool dmerge(int u, int v) { 
    u = dfind(u), v = dfind(v); 
    if( u == v ) return false;

    if( par[u] < par[v] ) swap(u, v); 

    par[v] += par[u];
    cnt[v] += cnt[u];
    par[u] = v;

    return (cnt[v]==k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    memset(par, -1, sizeof par); 

    int n, m;
    cin >> n >> m >> k;
    for(int i  = 0; i < k; i++) { 
        int x;
        cin >> x;
        cnt[x-1]++; 
    }

    for(int i = 0; i < m; i++) { 
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; 
        edges[i] = { w, {u, v} } ; 
    }

    sort(edges, edges + m);

    for(int i = 0; i < m; i++) 
        if( dmerge( edges[i].S.F, edges[i].S.S ) ) {
            for(int j = 0; j < k; j++)
                cout << edges[i].F << ' ';
            cout << endl;
            return 0;
        }

    return 0; 
}