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

const int N = 1000 * 100 + 100;

pair<pii,int> edges[N];
vector<pii> e[N];

int n, m;

int anscnt;
bool mark[N];
int ind; 
int ord[N];
int req[N];

void dfs(int s, int v) { 
    mark[s] = true; 
    for( auto x : e[s] ) 
        if( !mark[x.first] && x.second > v ) 
            dfs( x.first , v ); 

    ord[s] = ind++;
}

bool canDo(int val, bool pr = false) { 
    memset(mark, 0, sizeof mark);

    ind = 0;
    for(int i = 0; i < n; i++) 
        if( !mark[i] ) 
            dfs(i, val);

    for(int i = 0; i < m; i++) { 
        int c = edges[i].second;
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        if( c > val && ord[u] < ord[v] ) 
            return false;
        if( c <= val && ord[u] < ord[v] && pr ) {
            req[i] = true;
            anscnt++; 
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    cin >> n >> m; 

    int mx = 0;
    for(int i = 0; i < m; i++) { 
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--; 
        e[u].push_back( {v, c} ); 
        edges[i] = { {u,v} , c };
        mx = max( mx, c );
    }

    int lo = -1, hi = mx; 

    while( hi - lo > 1 ) { 
        int mid = (hi+lo)/2; 

        if( canDo(mid) ) 
            hi = mid; 
        else
            lo = mid;
    }

    canDo(hi, true); 

    cout << hi << ' ' << anscnt << endl;

    for(int i = 0; i < m; i++) 
        if( req[i] ) 
            cout << i + 1 << ' ';
    cout << endl;


    return 0;
}