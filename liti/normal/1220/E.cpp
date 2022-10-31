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

ll dp[N][2]; 
int a[N];

int mark[N]; 
vector<int> c[N], good[N]; 

bool dfs(int s, int p) {
    mark[s] = true; 

    int hasback = false;

    for(auto x: c[s]) {
        if( !mark[x] ) {
            hasback |= dfs(x, s); 
            dp[s][0] += dp[x][0]; 

            good[s].pb(x);
        } else if( x != p ) 
            hasback = true;
    }

    for(auto x: good[s]) 
        dp[s][1] = max(dp[s][1], dp[s][0]-dp[x][0]+dp[x][1]);

    dp[s][1] += a[s];
    if( hasback ) 
        dp[s][0] += a[s]; 

    return hasback; 
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int n, m;
    cin >> n >> m; 

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; 
        u--; v--; 
        
        c[u].pb(v); 
        c[v].pb(u); 
    }

    int s;
    cin >> s; 
    s--; 

    dfs(s, -1); 

    cout << dp[s][1] << endl;
    return 0;
}