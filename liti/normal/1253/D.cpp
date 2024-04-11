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

const int N = 200 * 1000 + 100;

int par[N], mx[N]; 

int dfind(int u) { 
    return par[u] < 0 ? u : par[u] = dfind(par[u]); 
}


void dmerge(int u, int v) { 
    u = dfind(u), v = dfind(v); 
    if( u == v ) return;

    if( par[u] > par[v] )
       swap(u, v);  

   par[u] += par[v];
   par[v] = u; 
   mx[u] = max(mx[u], mx[v]); 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 

    int n, m; 
    cin >> n >> m; 

    memset(par, -1, sizeof par); 

    for(int i = 0; i < n; i++) 
        mx[i] = i; 

    for(int i = 0; i < m; i++) { 
        int u, v;
        cin >> u >> v; 
        u--; v--; 
        dmerge(u, v); 
    }

    int last = -1; 
    int ans = 0; 

    for(int i = 0; i < n; i++){ 
        if( last < i ) 
            last = mx[dfind(i)]; 
        else if( dfind(i) != dfind(last) ) { 
            ans++; 
            dmerge(i, last); 
            last= mx[dfind(i)]; 
        }
    }

    cout << ans << endl;
           

    return 0;
}