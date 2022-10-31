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

const int N = 1000*100 + 100;

const int mod = 1e9 + 7;

int sum(int a, int b){ 
    int c=  a + b; 
    if( c >= mod ) c -= mod; 
    return c;
}
int mul(int a, int b) { 
    return 1ll * a * b % mod; 
}
int bpow(int a, int b) { 
    int r = 1; 
    for( ; b ; b /=2 ) { 
        if( b % 2 == 1 ) 
            r = mul(r, a ); 
        a = mul(a, a ); 
    }

    return r;
}

vector<int> e[N]; 
int mark[N]; 

int dfs(int s) { 
    mark[s] = true; 
    int ret = 1; 
    for(auto x : e[s]) 
        if( !mark[x] ) 
            ret += dfs(x); 
    return ret; 
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); 
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n-1; i++) { 
        int u, v, c;
        cin >> u >> v >> c; 
        u--; v--; 
        if( c == 0 ) {
            e[v].pb(u); 
            e[u].pb(v); 
        }
    }

    int ans = bpow(n, k); 
    for(int i = 0; i < n; i++) 
        if( !mark[i] ) { 
            int sz = dfs(i); 
            ans = sum(ans, mod - bpow(sz, k)); 
        }

    cout << ans << endl;

    return 0;
}