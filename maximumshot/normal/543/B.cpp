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

int n, m;

vec< vec<int> > g, d;
int s1, t1, s2, t2, l1, l2;

bool check() {
    d.resize(n);
    for(int start = 0;start < n;start++) {
        vec<int> d1(n, inf);
        d1[start] = 0;
    
        vec<bool> vis(n, 0), in(n, 0);
        vis[start] = in[start] = 1;

        queue<int> q;
        q.push(start);

        while(!q.empty()) {
            int v = q.front();
            q.pop();
            in[v] = 0;
            for(int i(0);i < (int)g[v].size();i++) {
                int to = g[v][i];
                if(d1[to] > d1[v] + 1) {
                    d1[to] = d1[v] + 1;
                    if(!in[to]) {
                        in[to] = 1;
                        q.push(to);
                    }
                }
            }
        }

        d[start] = d1;
    }

    if(d[s1][t1] > l1 || d[s2][t2] > l2) return 0;
    else return 1;
}

bool solve()
{
    cin >> n >> m;

    g.resize(n);
    
    for(int u, v, i(0);i < m;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i(0);i < n;i++) {
        g[i].push_back(i);
        sort(ALL(g[i]));
        g[i].resize(unique(ALL(g[i])) - g[i].begin());
    }

    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;

    s1--, t1--, s2--, t2--;

    if(!check()) {
        puts("-1");
        return true;
    }

    int ans = m + 1;

    ans = d[s1][t1] + d[s2][t2];

    for(int x(0);x < n;x++) {
        for(int y(0);y < n;y++) {
            int d1, d2;
            d1 = d[s1][x] + d[x][y] + d[y][t1];
            d2 = d[s2][x] + d[x][y] + d[y][t2];
            if(d1 > l1 || d2 > l2) continue;
            ans = min(ans, d1 + d2 - d[x][y]);
        }
    }

    swap(s2, t2);

    for(int x(0);x < n;x++) {
        for(int y(0);y < n;y++) {
            int d1, d2;
            d1 = d[s1][x] + d[x][y] + d[y][t1];
            d2 = d[s2][x] + d[x][y] + d[y][t2];
            if(d1 > l1 || d2 > l2) continue;
            ans = min(ans, d1 + d2 - d[x][y]);
        }
    }

    cout << m - ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}