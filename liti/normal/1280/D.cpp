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
typedef pair<int, ll> pil;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 3000 + 10;
const int inf = 1e9; 

vector<int> c[N];
pil dp[N][N], tmp[N];

int a[N], b[N]; 
int sz[N];  
int n, m; 

void dfs(int s, int p) { 
    sz[s] = 1; 

    dp[s][1] = {0, a[s] - b[s]}; 

    for(auto x:  c[s])
        if( x != p ) { 
            dfs(x, s); 
            fill(tmp, tmp + sz[s] + sz[x] + 1, pil(-inf, -inf));
            for(int k = 1; k <= sz[s]; k++) 
                for(int p = 1; p <= sz[x]; p++) { 
                    tmp[k+p-1] = max(tmp[k+p-1], {dp[s][k].F + dp[x][p].F, dp[s][k].S +  dp[x][p].S}); 
                    tmp[k+p] = max(tmp[k+p], {dp[s][k].F + dp[x][p].F + (dp[x][p].S > 0), dp[s][k].S} ); 
                }

            copy(tmp, tmp + sz[s] + sz[x] + 1, dp[s]); 

            sz[s] += sz[x]; 
        }

}

void solve() { 
    memset(dp, -63, sizeof dp); 

    cin >> n >> m;

    for(int i = 0; i < n; i++) 
        cin >> b[i]; 
    for(int i = 0; i < n; i++) 
        cin >> a[i]; 

    fill(c, c + n, vector<int>()); 

    for(int i = 0; i < n-1; i++) { 
        int u, v;
        cin >> u >> v; 
        u--; v--;
        c[u].pb(v); 
        c[v].pb(u); 
    }

    dfs(0, 0); 
    cout << dp[0][m].F + (dp[0][m].S > 0) << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}