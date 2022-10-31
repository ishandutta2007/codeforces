//In the name of God
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int,int> pii; 
#define sz(x) ((int)(x).size())

const int maxN = 3 * 1000 * 100 + 10; 

int w[maxN]; 
vector<pii> c[maxN]; 

ll ans; 

ll dn[maxN], up[maxN]; 

void dfs(int s, int p) { 
    dn[s] = w[s];
    ans = max(ans, dn[s]);
    for( auto x : c[s] ) {
        if( x.first == p ) continue;
        dfs( x.first , s ); 
        ans = max(ans, dn[s] + dn[x.first] - x.second);
        dn[s] = max(dn[s], w[s] + dn[x.first] - x.second);
    }
}

int main() { 
    ios::sync_with_stdio(false); 
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> w[i]; 
    for(int i = 1; i < n; i++) { 
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        c[u].push_back( {v, w} ); 
        c[v].push_back( {u, w} ); 
    }

    dfs(0, 0); 

    cout << ans << endl;

    return 0;
}