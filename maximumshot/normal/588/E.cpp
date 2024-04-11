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

vec< int > gen(const vec< int > & a, const vec< int > & b) {
    vec< int > ans;
    int n = (int)a.size(), i = 0;
    int m = (int)b.size(), j = 0;
    while((int)ans.size() < 10 && i < (int)a.size() && j < (int)b.size()) {
        if(a[i] <= b[j]) ans.push_back(a[i++]);
        else ans.push_back(b[j++]);
    }
    while((int)ans.size() < 10 && i < (int)a.size()) ans.push_back(a[i++]);
    while((int)ans.size() < 10 && j < (int)b.size()) ans.push_back(b[j++]);
    return ans;
}

int n, m, q, root = 1;
vec< int > c;
vec< vec< int > > g;

void read() {
    
    scanf("%d %d %d", &n, &m, &q);

    g.resize(n + 1);
    c.resize(m + 1);

    for(int u, v, i = 0;i < n - 1;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1;i <= m;i++) {
        scanf("%d", &c[i]);
    }
}

const int LOG = 21;

vec< vec< int > > p;
vec< vec< vec< int > > > ans;
vec< int > h;

void dfs(int v, int par = -1, int H = 0) {
    p[v][0] = par;
    h[v] = H;
    for(int i = 0;i < (int)g[v].size();i++) {
        int to = g[v][i];
        if(par != to) dfs(to, v, H + 1);
    }
}

void prepare() {
    p.resize(n + 1);
    ans.resize(n + 1);
    h.resize(n + 1, -1);
    
    for(int i = 1;i <= n;i++) {
        p[i].resize(LOG, -1);
        ans[i].resize(LOG);
    }
    for(int i = 1;i <= m;i++) {
        ans[c[i]][0].push_back(i);
    }
    for(int i = 1;i <= n;i++) {
        sort(ALL(ans[i][0]));
        while((int)ans[i][0].size() > 10) {
            ans[i][0].pop_back();
        }
    }
    dfs(root);
    for(int i = 1;i < LOG;i++) {
        for(int j = 1;j <= n;j++) {
            int x = p[j][i - 1];
            if(x == -1) continue;
            p[j][i] = p[x][i - 1];
        }
    }
    for(int i = 1;i < LOG;i++) {
        for(int j = 1;j <= n;j++) {
            int x = p[j][i - 1];
            if(x != -1) {
                ans[j][i] = gen(ans[j][i - 1], ans[x][i - 1]);
            }else {
                ans[j][i] = ans[j][i - 1];
            }
        }
    }
}

int lca(int x, int y) {
    if(h[x] > h[y]) swap(x, y);
    for(int j = LOG - 1;j >= 0;j--) {
        int to = p[y][j];
        if(to == -1 || h[to] < h[x]) continue;
        y = to;
    }
    for(int i = LOG - 1;i >= 0;i--) {
        if(p[x][i] == -1 || p[y][i] == -1 || p[x][i] == p[y][i]) continue;
        x = p[x][i];
        y = p[y][i];
    }
    if(x != y) x = p[x][0];
    return x;
}

bool solve() {
    
    read();
    prepare();

    /*for(int j = 0;j < 2;j++) {
        cout << (1 << j) << '\n';
        
        for(int i = 1;i <= n;i++) {
            cout << "\t" << i << " : ";
            for(auto x : ans[i][j]) cout << x << " ";
            cout << '\n';
        }
    }*/

    for(int u, v, a, i = 0;i < q;i++) {
        scanf("%d %d %d", &u, &v, &a);
        vec< int > tmp;
        int t = lca(u, v);
    
        tmp = ans[t][0];

        for(int j = LOG - 1;j >= 0;j--) {
            int to = p[u][j];
            if(to == -1 || h[to] < h[t]) continue;
            tmp = gen(tmp, ans[u][j]);
            u = to;
        }
        for(int j = LOG - 1;j >= 0;j--) {
            int to = p[v][j];
            if(to == -1 || h[to] < h[t]) continue;
            tmp = gen(tmp, ans[v][j]);
            v = to;
        }
        int sz = min((int)tmp.size(), a);
        printf("%d ", sz);
        for(int j = 0;j < sz;j++) printf("%d ", tmp[j]);
        puts("");
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}