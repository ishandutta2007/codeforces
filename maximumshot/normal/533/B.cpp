#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

int n;
vec< vec<int> > g;
vec< LL > a, dp[2], par;

void dfs(int v, int par = -1) {
    LL t0 = 0, t1 = -inf64;
    for(int i(0);i < (int)g[v].size();i++) {
        int to = g[v][i];
        if(to == par) continue;
        dfs(to, v);
        LL t0t = max(t0 + dp[0][to], t1 + dp[1][to]);
        LL t1t = max(t1 + dp[0][to], t0 + dp[1][to]);   
        t0 = t0t;
        t1 = t1t;
    }

    dp[0][v] = t0;
    dp[1][v] = max(t1, t0 + a[v]);
}

bool solve()
{
    scanf("%d", &n);

    g.resize(n);
    a.resize(n);
    dp[0].resize(n);
    dp[1].resize(n);

    for(int p, i(0);i < n;i++) {
        scanf("%d %d", &p, &a[i]);
        p--;
        if(i) {
            g[i].push_back(p);
            g[p].push_back(i);
        }
    }
    
    dfs(0);

    printf("%I64d\n", max(dp[0][0], dp[1][0]));

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}