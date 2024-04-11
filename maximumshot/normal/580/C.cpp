#include <iostream>
#include <cmath>
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
#include <complex>
#include <unordered_map>

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

int n, m, ans = 0;
vec< int > a;
vec< vec< int > > g;

void read() {
    scanf("%d %d", &n, &m);
    a.resize(n + 1);
    g.resize(n + 1);
    for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
    for(int u, v, i = 1;i <= n - 1;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dfs(int v, int c = 0, int par = -1) {
    if(a[v]) c++;
    else c = 0;
    if(c > m) return;
    int child = 0;
    for(int i = 0;i < (int)g[v].size();i++) {
        int to = g[v][i];
        if(to == par) continue;
        child++;
        dfs(to, c, v);
    }
    if(child == 0) ans++;
}

bool solve() {
    
    read();

    dfs(1);

    printf("%d\n", ans);

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}