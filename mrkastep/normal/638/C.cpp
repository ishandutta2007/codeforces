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

vector<pair<int, int> > g[200200];

vector<int> col[200200];

void dfs(int v, int p, int ban){
    int c = 0;
    For(i, g[v].size()){
        if (g[v][i].x != p){
            if (c == ban) ++c;
            col[c].pb(g[v][i].y);
            dfs(g[v][i].x, v, c);
            ++c;
        }
    }
}

void solve(){
    int n, a, b;
    scanf("%d", &n);
    For(i, n - 1){
        scanf("%d%d", &a, &b);
        --a;
        --b;
        g[a].pb(mp(b, i + 1));
        g[b].pb(mp(a, i + 1));
    }
    dfs(0, -1, -1);
    int ans = 0;
    For(i, 200200){
        if (col[i].size() > 0) ++ans;
    }
    printf("%d\n", ans);
    For(i, 200200){
        if (col[i].size() > 0){
            printf("%d ", col[i].size());
            For(j, col[i].size()){
                printf("%d ", col[i][j]);
            }
            puts("");
        }
    }
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}