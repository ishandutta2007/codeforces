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

const int N = 5000 + 100;
const int K = 2*N + 100;
const int M = (4*N + 100)*2; 
int so = K-2, si = K-1; 

int a[N]; 
int p[N]; 

int mark[N]; 

set<int> toadd[N]; 

int ans[N]; 

int to[M], nex[M], head[K], cap[M], ecnt; 

void add_edge(int u, int v, int c) { 
    to[ecnt] = v, nex[ecnt] = head[u], head[u] = ecnt, cap[ecnt++] = c;
    to[ecnt] = u, nex[ecnt] = head[v], head[v] = ecnt, cap[ecnt++] = 0;
}

int dmk[K]; 

bool dfs(int s, int si) { 
    dmk[s] = true; 
    if( s == si ) return true; 

    for(int e = head[s] ; e != -1 ; e = nex[e] ) 
        if( cap[e] && !dmk[to[e]] && dfs(to[e], si) ) { 
            cap[e] --; 
            cap[e^1]++; 
            return true; 
        }
    return false;
}

int bad[N];

int main(){
    memset(head, -1, sizeof head); 

    ios::sync_with_stdio(false); cin.tie(0); 

    int n, m; 
    cin >> n >> m; 

    for(int i = 0; i < n; i++) 
        cin >> p[i]; 

    for(int i = 0; i < n; i++) {
        cin >> a[i]; 
        a[i]--;
    }

    int d; 
    cin >> d; 
    for(int i = 0; i < d; i++) { 
        cin >> bad[i]; 
        bad[i]--;
        mark[bad[i]] = true; 
    }


    for(int i = 0; i < m; i++)  
        add_edge(so, i, 1); 

    for(int i = 0; i < n; i++) 
        if( !mark[i] ) 
            toadd[p[i]].insert( i ); 

    int curr = 0;
    int flow = 0;

    for(int i = d-1; i >= 0; i--) { 
        while( flow == curr ) { 
            add_edge( m + curr , si , 1 ); 
            for(auto x: toadd[curr]) 
                add_edge( a[x] , m + curr , 1 ); 
            curr++; 
            memset(dmk, 0, sizeof dmk); 
            if( dfs(so, si) ) 
                flow++; 
        }
        ans[i] = flow; 

        if( p[bad[i]] < curr ) { 
            add_edge( a[bad[i]] , m + p[bad[i]] , 1 ); 
            memset(dmk, 0, sizeof dmk);
            if( dfs(so, si) ) flow++; 
        } else 
            toadd[p[bad[i]]].insert(bad[i]); 
    }

    for(int i = 0; i < d; i++) 
        cout << ans[i] << '\n';
    return 0;
}