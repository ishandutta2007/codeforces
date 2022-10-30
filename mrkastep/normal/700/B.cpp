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
#include <set>


using namespace std;

const int INF = 2e9;
const int mod = 1e9 + 7;
const long long LONGINF = 4e18;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<double, double> point;

ll ans = 0;

vector<int> g[200200];
int am[200200], un[200200];

void dfs1(int v, int par, int dpt){
    am[v] = un[v];
    ans += dpt*un[v];
    for (auto to : g[v]){
        if (to != par){
            dfs1(to, v, dpt + 1);
            am[v] += am[to];
        }
    }
}

void dfs2(int v, int par, int dpt, int todel){
    int s = 0, mx = -1, mxi = -1;
    for (auto to : g[v]){
        if (to != par){
            s += am[to];
            if (mx < am[to]){
                mx = am[to];
                mxi = to;
            }
        }
    }
    s += un[v];
    if (mx - todel>s - mx){
        ans -= (ll)(s - mx)*dpt * 2;
        dfs2(mxi, v, dpt + 1, todel + s - mx);
        return;
    }
    else{
        ans -= (ll)(s - todel)*dpt;
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        un[i] = 0;
    }
    for (int i = 0; i < 2 * k; ++i){
        int u;
        cin >> u;
        un[u - 1] = 1;
    }
    for (int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(0, -1, 0);
    dfs2(0, -1, 0, 0);
    cout << ans;
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}
//ll