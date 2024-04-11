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
const int LOG = 21;

vec< int > c[LOG], p[LOG], h;
vec< vec< int > > g, id;
vec<int> ans;

void dfs(int v, int par = -1, int H = 0) {
    p[0][v] = par;
    h[v] = H;
    for(int i(1);i < LOG;i++) {
        int x = p[i - 1][v];
        if(x == -1) break;
        p[i][v] = p[i - 1][x];
    }

    for(int i(0);i < (int)g[v].size();i++) {
        int to = g[v][i];
        if(to == par) continue;
        dfs(to, v, H + 1);
    }
}

int lca(int x, int y) {
    if(h[x] < h[y]) swap(x, y);

    for(int i(LOG - 1);i >= 0;i--) {
        int px = p[i][x];
        if(px == -1) continue;
        if(h[px] >= h[y])
            x = px;
    }

    for(int i(LOG - 1);i >= 0;i--) {
        int px, py;
        px = p[i][x];
        py = p[i][y];
        if(px == -1 || py == -1) continue;
        if(px != py) {
            x = px;
            y = py;
        }
    }

    if(x != y) x = p[0][x];

    return x;
}

void go(int v, int par = -1) {
    for(int i(0);i < (int)g[v].size();i++) {
        int to = g[v][i];
        int index = id[v][i];
        if(to == par) continue;
        ans[index] = c[0][to];
        go(to, v);
    }
}

bool solve()
{
    scanf("%d", &n);

    g.resize(n);
    id.resize(n);
    h.resize(n);
    ans.resize(n);

    for(int i(0);i < n - 1;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        id[x].push_back(i);
        id[y].push_back(i);
    }

    for(int i(0);i < LOG;i++) {
        c[i].resize(n, 0);
        p[i].resize(n, -1);
    }

    dfs(0);

    int k;
    scanf("%d", &k);

    for(int i(0);i < k;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--, y--;
        int z = lca(x, y);

        for(int j(LOG - 1);j >= 0;j--) {
            int px = p[j][x];
            int py = p[j][y];
            if(px != -1 && h[px] >= h[z]) {
                c[j][x]++;
                x = px;
            }
            if(py != -1 && h[py] >= h[z]) {
                c[j][y]++;
                y = py;
            }
        }
    }

    for(int j(LOG - 1);j > 0;j--) {
        for(int i(0);i < n;i++) {
            int x = p[j - 1][i];
            c[j - 1][i] += c[j][i];
            if(x != -1) c[j - 1][x] += c[j][i];
            c[j][i] = 0;
        }
    }

    go(0);

    for(int i(0);i < n - 1;i++) 
        printf("%d ", ans[i]);
    puts("");

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}