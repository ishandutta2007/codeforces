//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 100 * 1000 + 10; 
const int maxL = 20; 
typedef pair<int,int> pii;

int h[maxN], par[maxN][maxL];
int st[maxN]; 

pii mn[maxN][maxL], mx[maxN][maxL]; 
int lg[maxN];

vector<int> c[maxN];

void dfs(int s) { 
    static int ind = 0; 
    st[s] = ind++;

    for(int k = 1; k < maxL; k++) 
        par[s][k] = par[par[s][k-1]][k-1];

    for( auto x : c[s] ) { 
        par[x][0] = s; 
        h[x] = h[s] + 1; 
        dfs( x ); 
    }
}

int getH(int u, int h) { 
    for( int i = 0; i < maxL ; i++) 
        if( (h>>i) & 1 ) 
            u = par[u][i]; 
    return u; 
}

int lca(int u, int v) { 
    if( h[u] < h[v] ) 
        swap( u, v ); 
    u = getH( u , h[u] - h[v] ); 

    if( u == v ) return u; 

    for(int k = maxL - 1; k >= 0; k-- ) 
        if( par[u][k] != par[v][k] ) { 
            u = par[u][k]; 
            v = par[v][k]; 
        }
    return par[u][0]; 
}

pii get(int l, int r) { 
    if( l == r ) 
        return pii(-1, -1);

    int len = lg[r-l]; 
    auto f = min(mn[l][len], mn[r-(1<<len)][len]);
    auto s = max(mx[l][len], mx[r-(1<<len)][len]);

    return pii(f.second, s.second);
}

int get(int l, int r, int mid) { 
    auto f = get(l, mid);
    auto s = get(mid+1, r);
    if( l == mid ) f = s; 
    if( mid + 1 == r ) s = f; 

    pii ret; 
    if( st[s.first] < st[f.first] ) 
        ret.first = s.first;
    else
        ret.first = f.first;

    if( st[s.second] > st[f.second] ) 
        ret.second = s.second;
    else
        ret.second = f.second;

    return lca(ret.first, ret.second);
}

int main() { 
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;

    for(int i = 1; i < n; i++) { 
        int p;
        cin >> p; 
        p--; 
        c[p].push_back(i); 
    }
    dfs(0); 

    lg[1] = 0; 
    for(int i = 2; i < maxN ; i++ ) 
        lg[i] = lg[i/2] + 1;

    for(int i = n - 1 ; i >= 0; i-- ) { 
        mn[i][0] = mx[i][0] = {st[i], i}; 
        for(int k = 1; i + (1<<k) <= n ; k++ ) {
            mn[i][k] = min( mn[i][k-1] , mn[i+(1<<(k-1))][k-1] );
            mx[i][k] = max( mx[i][k-1] , mx[i+(1<<(k-1))][k-1] ); 
        }
    }

    for(int i = 0; i < q; i++) { 
        int l, r;
        cin >> l >> r; 
        l--; 

        int len = lg[r-l]; 
        auto ret = get( l , r ); 

        int x = get(l, r, ret.first);
        int y = get(l, r, ret.second); 
        if( h[x] < h[y] ) {
            swap(x, y);
            swap(ret.first, ret.second);
        }
        cout << ret.first+1 << ' ' << h[x] << '\n';
    }
}