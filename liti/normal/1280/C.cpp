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

const int N = 2 * 100 * 1000 + 100;

vector<pii> c[N]; 

int n;
ll G; 
ll B; 

int dfs(int s, int p)  { 
    int sz = 1; 
    for(auto x : c[s]) 
        if( x.F != p ) { 
            int ret = dfs(x.F, s); 
            if( ret % 2 ) 
                G += x.S; 
            B += 1ll * x.S * min(ret, n - ret);
            sz += ret;
        }

    return sz; 
}

void solve() { 
    cin >> n; 
    n *= 2; 
    fill(c, c + n, vector<pii>()); 

    for(int i = 1; i < n; i++) { 
        int u, v, w;
        cin >> u >> v >> w; 
        u--; v--; 
        c[u].pb( {v, w} ); 
        c[v].pb( {u, w} );
    }

    G = 0; 
    B = 0;

    dfs(0, -1); 
    cout << G << " " << B << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 

    int t;
    cin >> t;

    while(t--) 
        solve(); 
}