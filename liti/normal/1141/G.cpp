//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = 2000*100 + 100;

vector<pii> c[N]; 
int col[N]; 
pii deg[N];

void dfs(int s, int p, int mod, int c = 0) {
    for(auto x : ::c[s])
        if( x.F != p ) { 
            col[x.S] = c; 
            c = (c+1) % mod; 
            dfs( x.F , s , mod , c ); 
        }
}


int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int n, k;
    cin >> n >> k;

    for(int i = 0; i + 1 < n; i++) { 
        int u, v;
        cin >> u >> v;
        u--; 
        v--; 
        c[u].pb( {v, i} ); 
        c[v].pb( {u, i} ); 
    }

    for(int i = 0; i < n; i++) 
        deg[i] = { sz(c[i]), i }; 

    sort(deg, deg + n); 
    reverse(deg, deg + n); 

    memset(col, -1, sizeof col); 
    dfs(0, -1, deg[k].F); 

    cout << deg[k].F << '\n';
    for(int i = 0; i < n-1; i++) 
        cout << 1 + col[i] << ' ';
    cout << endl;

    return 0;
}