#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

int n, m;
vec< vec< int > > g; 
vec< char > isAtacked; 

void read() {
    scanf("%d %d", &n, &m);

    g.resize(n + 1);

    for(int u, v, i = 1;i <= n - 1;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    isAtacked.resize(n + 1, 0);

    for(int x, i = 1;i <= m;i++) {
        scanf("%d", &x);
        isAtacked[x] = 1;
    }
}

//

int mnPathLength = inf, ans = -1;
vec< int > dp1, dp2, p;
vec< char > need;
vec< vec< int > > mas, pr, sf;

void dfs(int v, int par = -1) {
    int child = 0, sum = 0, ok = 0;

    p[v] = par;

    if(isAtacked[v]) need[v] = 1;

    for(int i = 0;i < (int)g[v].size();i++) {
        int to = g[v][i];
        if(par == to) continue;
        dfs(to, v);
        child++;
        if(need[to]) need[v] = 1, sum += dp1[to] + 2;
    }

    dp1[v] = sum;

    for(int i = 0;i < (int)g[v].size();i++) {
        int to = g[v][i], tmp;
        if(par == to || !need[to]) continue;
        ok = 1;
        tmp = sum - 2 - dp1[to] + 1 + dp2[to];
        dp2[v] = min(dp2[v], tmp);
    }

    if(!ok) dp2[v] = 0;

    if(child == 0) {
        dp1[v] = dp2[v] = 0;
        need[v] = isAtacked[v];
    }
}

inline void upd(int Length, int vertex) {
    //cout << "\nupd( " << Length << ", " << vertex << ")\n";
    if(Length < mnPathLength) {
        mnPathLength = Length;
        ans = vertex;
    }else if(Length == mnPathLength && vertex < ans) {
        ans = vertex;
    }
}

void go(int v, int par = -1, int parDp1 = 0, int parDp2 = 0, int parNeed = 0) {

    //cout << v << " " << par << " : " << parDp1 << " ; " << parDp2 << " ; " << parNeed << '\n';

    // upd

    upd(dp2[v] + parNeed * (2 + parDp1), v);
    if(parNeed) upd(dp1[v] + 1 + parDp2, v);

    int SumNeed = parNeed + isAtacked[v], sz = (int)g[v].size();

    for(int i = 0;i < sz;i++) {
        int to = g[v][i];
        if(to != par) SumNeed += need[to];
    }

    for(int i = 0;i < sz;i++) {
        int to = g[v][i], vDp1, vDp2, vNeed;
        if(to == par) continue;

        vDp1 = dp1[v] + parNeed * (2 + parDp1) - need[to] * (2 + dp1[to]);
        vDp2 = inf;

        if(i > 0 && pr[v][i - 1] != inf) vDp2 = min(vDp2, pr[v][i - 1] + parNeed * (2 + parDp1) - need[to] * (2 + dp1[to]));
        if(i + 1 < sz && sf[v][i + 1] != inf) vDp2 = min(vDp2, sf[v][i + 1] + parNeed * (2 + parDp1) - need[to] * (2 + dp1[to]));
        if(parNeed) vDp2 = min(vDp2, dp1[v] - need[to] * (2 + dp1[to]) + parDp2 + 1);
        if(vDp2 == inf) vDp2 = 0;

        vNeed = (SumNeed - need[to] > 0?1 : 0);

        go(to, v, vDp1, vDp2, vNeed);
    }
}

void precalc() {
    p.resize(n + 1, -1);
    dp1.resize(n + 1, inf);
    dp2.resize(n + 1, inf);
    need.resize(n + 1, 0);
    dfs(1);

    /*cout << "\n";
    for(int i = 1;i <= n;i++) cout << i << " : " << dp1[i] << " " << dp2[i] << " " << (int)need[i] << '\n';
    cout << '\n';*/

    mas.resize(n + 1);
    pr.resize(n + 1);
    sf.resize(n + 1);

    for(int i = 1;i <= n;i++) {
        int sz = (int)g[i].size(), sum = 0;
        mas[i].resize(sz, inf);
        pr[i].resize (sz, inf);
        sf[i].resize (sz, inf);
        for(int j = 0;j < sz;j++) {
            int to = g[i][j];
            if(to == p[i] || !need[to]) continue;
            sum += dp1[to] + 2;
        }
        for(int j = 0;j < sz;j++) {
            int to = g[i][j];
            if(to == p[i] || !need[to]) continue;
            mas[i][j] = sum - 2 - dp1[to] + 1 + dp2[to];
        }
        int value1 = inf, value2 = inf;
        for(int j = 0;j < sz;j++) {
            value1 = min(value1, mas[i][j]);
            value2 = min(value2, mas[i][sz - 1 - j]);
            pr[i][j] = value1;
            sf[i][sz - 1 - j] = value2;
        }
    }

    go(1);
}

bool solve() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    read();
    precalc();

    printf("%d\n%d\n", ans, mnPathLength);

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}