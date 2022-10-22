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
const LL base = inf * 1000ll + 17;
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

bool solve()
{
    int n, m;

    scanf("%d %d", &n, &m);

    vec< vec< pair< pair<int, int>, int> > > g(n);
    vec<int> e(m);

    for(int i(0);i < m;i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        g[u].push_back(mp(mp(v, w), i));
        g[v].push_back(mp(mp(u, w), i));
        e[i] = w;
    }

    vec<LL> dist(n, inf64);
    vec<int> par(n, -1);

    int s;
    scanf("%d", &s);
    s--;

    dist[s] = 0;

    set< pair<LL, int> > h;

    for(int i(0);i < n;i++) {
        h.insert(mp(dist[i], i));
    }

    LL answer = 0;
    vec<int> ans;

    while(!h.empty()) {
        int v = h.begin()->second;
        h.erase(h.begin());

        for(int i(0);i < (int)g[v].size();i++) {
            int to = g[v][i].first.first;
            LL len = g[v][i].first.second;
            int id = g[v][i].second;

            if(dist[to] > dist[v] + len) {
                h.erase(mp(dist[to], to));
                dist[to] = dist[v] +  len;
                h.insert(mp(dist[to], to));
                par[to] = id;
            }else if(dist[to] == dist[v] + len && par[to] != -1 && len < e[par[to]]){
                par[to] = id;
            }
        }
    }

    for(int i(0);i < n;i++) {
        if(par[i] == -1) continue;
        ans.push_back(par[i]);
    }

    sort(ALL(ans));
    ans.resize(unique(ALL(ans)) - ans.begin());

    for(int i(0);i < (int)ans.size();i++) {
        answer += e[ans[i]];
    }

    printf("%I64d\n", answer);

    for(int i(0);i < (int)ans.size();i++) {
        int x = ans[i];
        printf("%d ", x + 1);
    }

    puts("");

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}