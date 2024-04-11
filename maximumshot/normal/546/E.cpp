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

const int inf = 1000000000ll;
const LL inf64 = 1ll * inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << '\n';
    return os;
}

int n, m, s, t;
vec< int > a, b;
vec< pair<int, int> > e;
vec< vec<int> > g, f, c;

void addEdge(int x, int y, int capacity) {
    g[x][y] = g[y][x] = 1;
    c[x][y] = capacity;
}

void buildNet() {
    s = 0, t = 2 * n + 1;
    g = f = c = vec< vec<int> >(2 * n + 2, vec<int>(2 * n + 2));
    for(int i(1);i <= n;i++) {
        addEdge(s, i, a[i]);
        addEdge(i + n, t, b[i]);
        addEdge(i, i + n, inf);
    }

    for(int i(0);i < m;i++) {
        int x, y;
        x = e[i].first;
        y = e[i].second;
        addEdge(x, y + n, inf);
        addEdge(y, x + n, inf);
    }
}

void maxFlow() {
    queue<int> q;
    vec<bool> in(2 * n + 2, 0);
    vec<int> dist(2 * n + 2, inf), from(2 * n + 2, -1);

    q.push(s);
    in[s] = 1;
    dist[s] = 0;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        in[v] = 0;
        for(int i(0);i <= 2 * n + 1;i++) {
            if(v == i) continue;
            if(!g[v][i]) continue;
            int cf = c[v][i] - f[v][i];
            if(!cf) continue;
            if(dist[i] > dist[v] + 1) {
                dist[i] = dist[v] + 1;
                from[i] = v;
                if(!in[i]) {
                    in[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    if(from[t] == -1) return;

    int ans = inf;

    for(int v = t;from[v] != -1;v = from[v]) {
        int x, y, cf;
        x = from[v];
        y = v;
        cf = c[x][y] - f[x][y];
        ans = min(ans, cf);
    }

    for(int v = t;from[v] != -1;v = from[v]) {
        int x, y, cf;
        x = from[v];
        y = v;
        f[x][y] += ans;
        f[y][x] = -f[x][y];
    }

    maxFlow();
}

bool solve() 
{
    scanf("%d %d", &n, &m); 

    a.resize(n + 1);
    b.resize(n + 1);
    
    int s1 = 0, s2 = 0;

    for(int i(1);i <= n;i++) {
        scanf("%d", &a[i]);
        s1 += a[i];
    }

    for(int i(1);i <= n;i++) {
        scanf("%d", &b[i]);
        s2 += b[i];
    }

    if(s1 != s2) {
        puts("NO");
        return true;
    }

    for(int i(1);i <= m;i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        e.push_back(mp(u, v));
    }

    buildNet();

    maxFlow();

    int F = 0;
    for(int i(1);i <= n;i++) {
        F += f[s][i];
    }

    if(F != s1) {
        puts("NO");
        return true;
    }

    vec< vec<int> > ans(n + 1, vec<int>(n + 1));

    puts("YES");

    for(int i(1);i <= n;i++) {
        for(int j(1 + n);j <= 2 * n;j++) {
            int x = i, y = j - n;
            if(f[i][j] > 0) ans[x][y] = f[i][j];
        }
    }

    for(int i(1);i <= n;i++) {
        for(int j(1);j <= n;j++) {
            printf("%d ", ans[i][j]);
        }
        puts("");
    }

    return true;
}   

int main()  
{
    //while(solve());
    solve();

    return 0;
}