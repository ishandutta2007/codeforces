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

const int N = 2 * 1000 * 100 + 100;

vector<int> c[N]; 

int mark[2][N]; 

void dfs(bool t, int s, int bad) { 
    mark[t][s] = true;  
    for(auto x : c[s]) 
        if( !mark[t][x] && x != bad ) 
            dfs(t, x, bad); 
}

void solve() { 
    int n, m, a, b; 
    cin >> n>> m >> a >> b; 
    a--; b--;

    for(int i = 0; i < n;i++) { 
        c[i].clear(); 
        mark[0][i] = mark[1][i] = 0; 
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u>> v;
        u--; 
        v--; 
        c[u].pb(v); 
        c[v].pb(u);  
    }

    dfs(0, a, b); 
    dfs(1, b, a);  

    int cnt[2] = {0, 0}; 
    for(int i = 0;i  < n; i++) 
        if( i != a && i != b && mark[1][i] != mark[0][i] ) { 
            if( mark[0][i] ) 
                cnt[0]++; 
            else
                cnt[1]++; 
        }

    cout << 1ll * cnt[0] * cnt[1] << '\n';
}

int main() {
    int t; 
    cin >> t; 
    while( t-- ) 
        solve(); 
    return 0;
}