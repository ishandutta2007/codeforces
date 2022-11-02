//8:50
//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii; 

const int maxL = 20;
const int maxN = 5 * 100 * 1000 + 10; 

vector<int> c[maxN];
int a[maxN];
int par[maxN][maxL];
ll ans; 

void dfs(int s, int p) {
    par[s][0] = p;
    for(int i = 1; i < maxL ; i++)
        par[s][i] = par[par[s][i-1]][i-1]; 

    if( p != s ) { 
        ans += a[s]; 

        ll v = a[p]; 
        for(int i = 0; i < maxL; i++) 
             v = min( v, a[ par[s][i] ] * ll(1 + i) );
        ans += v; 
    }

    for(auto x : c[s]) 
        if( x != p ) 
            dfs( x , s );
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++)
        cin >> a[i]; 

    int s = min_element(a, a + n) - a; 

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        c[u].push_back(v); 
        c[v].push_back(u); 
    }

    dfs(s, s); 
    cout << ans << endl;

    return 0;
}