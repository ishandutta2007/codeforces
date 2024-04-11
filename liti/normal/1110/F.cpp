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

const int N = 500*1000 + 10;

vector<pii> c[N];

ll mn[N*4]; 
ll val[N];
ll toadd[4*N];


int st[N], en[N], ind;

void dfs(int s, ll sum) {
    st[s] = ind++;

    for( auto x : c[s] ) 
        dfs( x.first, sum + x.second ); 

    en[s] = ind;

    if( c[s].empty() ) 
        val[st[s]] = sum;
    else
        val[st[s]] = 1e17;

}

void build(int xl, int xr, int ind) { 
    if( xr - xl == 1 ) {
        mn[ind] = val[xl];
        return;
    }
    int xm = (xl+xr)/2;
    build(xl, xm, ind * 2); 
    build(xm, xr, ind * 2 + 1); 
    mn[ind] = min(mn[ind*2], mn[ind*2+1]);
}

void add(int ql, int qr, ll qv, int xl, int xr, int ind) {
    if( xr <= ql || qr <= xl ) 
        return;
    if( ql <= xl && xr <= qr ) { 
        toadd[ind] += qv;
        mn[ind] += qv;
        return;
    }

    int xm = (xl+xr)/2;
    add(ql, qr, qv, xl, xm, ind * 2);
    add(ql, qr, qv, xm, xr, ind * 2 + 1);

    mn[ind] = toadd[ind] + min(mn[ind*2], mn[ind*2+1]);
}

ll get(int ql, int qr, int xl, int xr, int ind) { 
    if( xr <= ql || qr <= xl ) 
        return ll(1e17);
    if( ql <= xl && xr <= qr ) 
        return mn[ind]; 
    int xm = (xl+xr)/2;

    return toadd[ind] + min(get(ql, qr, xl, xm, ind * 2),
            get(ql, qr, xm, xr, ind * 2 + 1));
}


ll ans[N]; 
vector<pair<pii,int>> que[N];

int n, q;

void solve(int s) { 
    for( auto q : que[s] ) 
        ans[q.S] = get(q.F.F, q.F.S, 0, n, 1);
    for( auto x : c[s] ) { 
        add(0, n, ll(1) * x.S, 0, n, 1); 
        add(st[x.F], en[x.F], ll(-2) * x.S, 0, n, 1);
        solve(x.F);
        add(st[x.F], en[x.F], ll(2) * x.S, 0, n, 1);
        add(0, n, ll(-1) * x.S, 0, n, 1); 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    cin >> n >> q; 

    for(int i = 1; i < n; i++) { 
        int p, w;
        cin >> p >> w; 
        p--;
        c[p].push_back( {i, w} ); 
    }

    dfs(0, 0); 
    build(0, n, 1);
    
    for(int i = 0; i < q; i++) {
        int v, l, r;
        cin >> v >> l >> r;
        v--; 
        l--; 
        que[v].push_back( { {l, r} , i} );
    }
    

    solve(0);

    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';

    return 0;
}