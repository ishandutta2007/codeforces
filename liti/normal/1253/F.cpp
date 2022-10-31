//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 1000*100 + 10;
const int M = 3*N;

ll dis[N]; 
int col[N]; 

vector<pii> c[N]; 

vector<pair<ll,pair<int,int>>> edges; 
vector<int> ch[M];

int par[N]; 

set<pair<ll,int>> curr;

ll qx[M], qy[M], ql[M], qr[M]; 

int dfind(int u) {
    return par[u] < 0 ? u : par[u] = dfind(par[u]); 
}

void dmerge(int u,  int v) {
    u = dfind(u); 
    v = dfind(v); 

    if( u == v  ) return; 

    if(  par[u] > par[v] ) 
        swap(u, v); 

    par[u] += par[v]; 
    par[v] = u;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int n, m, k, q;
    cin >> n >> m >> k >> q; 

    for(int i = 0; i < m; i++) { 
        int u, v,w;
        cin >> u >> v >> w; 
        u--; v--; 
        c[u].pb({v, w}); 
        c[v].pb({u, w}); 
    }

    memset(dis, 63, sizeof dis);

    for(int i = 0; i < k; i++) { 
        dis[i] = 0; 
        col[i] = i; 
        curr.insert({dis[i], i}); 
    }

    while(curr.size()) { 
        int s = curr.begin()->second; 
        curr.erase(curr.begin()); 

        for(auto x : c[s]) 
            if( dis[x.F] > dis[s] + x.S ) { 
                curr.erase( {dis[x.F], x.F} );
                dis[x.F] = dis[s] + x.S;
                col[x.F] = col[s];  
                curr.insert( {dis[x.F], x.F} );
            }
    }


    for(int x = 0; x < n; x++)
        for(auto y : c[x]) {
            if( x < y.F && col[x] != col[y.F] ) 
                edges.pb( {dis[x] + dis[y.F] + y.S, {col[x], col[y.F]}} ); 
        }

    sort(edges.begin(), edges.end()); 

    for(int i = 0; i < q; i++) { 
        cin >> qx[i] >> qy[i]; 
        qx[i]--; qy[i]--; 

        ql[i] = -1, qr[i] = sz(edges)-1; 
    }

    for(int t = 0; t < 20; t++) {
        for(int i = 0; i < q; i++) 
            if( qr[i] - ql[i] > 1 ) { 
                int mid = (ql[i] + qr[i])/2;
                ch[mid].pb(i); 
            }


        memset(par, -1, sizeof par); 
        for(int i = 0;  i < sz(edges); i++) { 
            dmerge(edges[i].S.F, edges[i].S.S); 
            for(auto x : ch[i]) 
                if( dfind(qx[x]) == dfind(qy[x]) ) 
                    qr[x] = i;
                else
                    ql[x] = i;

            ch[i].clear();
        }

    }

    for(int i = 0;  i < q; i++) 
        cout << edges[qr[i]].F << '\n';

    return 0;
}