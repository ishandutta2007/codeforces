#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <map> 
#include <time.h> 
#include <string> 
#include <algorithm> 
#include <queue> 
#include <assert.h> 
#include <math.h> 
#include <complex>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++) 
#define FOR(i,a,b) for(int i=(a);i<(b);i++) 
#define pb push_back 
#define mp make_pair 
#define x first 
#define y second 
#define all(v) (v).begin(),(v).end() 

typedef long long int ll;
typedef vector<ll> lll;
typedef complex<double> point;

const int INF = 2e9;
const int mod = 1e9 + 7;
const ll LONGINF = 4e18;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795;

vector<pair<int, int>> g[100100];
int deg[100100], n, st[100100], mxe[100100], d[100100];

void dfs(int v){
    if (st[v] == 1){
        return;
    }
    st[v] = 1;
    For(i, g[v].size()){
        dfs(g[v][i].x);
        if (d[g[v][i].x] + 1 > d[v]){
            d[v] = d[g[v][i].x] + 1;
            mxe[v] = max(mxe[g[v][i].x], g[v][i].y);
        }
    }
}

void solve(){
    int m, a, b;
    scanf("%d%d", &n, &m);
    For(i, n){
        deg[i] = 0;
        d[i] = mxe[i] = st[i] = 0;
    }
    For(i, m){
        scanf("%d%d", &a, &b);
        --a;
        --b;
        g[a].pb(mp(b, i));
        ++deg[a];
        ++deg[b];
    }
    int s = 0, v = 0;
    For(i, n){
        if (deg[i] == g[i].size()) ++s, v = i;
    }
    if (s > 1){
        printf("-1");
        return;
    }
    dfs(v);
    if (d[v] != n - 1){
        printf("-1");
        return;
    }
    printf("%d", mxe[v] + 1);
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}