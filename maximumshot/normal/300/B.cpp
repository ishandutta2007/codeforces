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

int n, m;
vec< vec<int> > g;
vec<int> comp;
vec<bool> used;

void dfs(int v) {
    used[v] = 1;
    comp.push_back(v);
    for(int i(0);i < (int)g[v].size();i++) {
        int to = g[v][i];
        if(used[to]) continue;
        dfs(to);
    }
}

bool solve()
{
    scanf("%d %d", &n, &m);

    g.resize(n);
    used.assign(n, false);

    for(int u, v, i(0);i < m;i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vec< pair<int, pair<int, int> > > ans;
    vec< pair<int, int> > a;
    vec<int> b;

    for(int i(0);i < n;i++) {
        if(used[i]) continue;
        comp.clear();
        dfs(i);
        if((int)comp.size() > 3) {
            puts("-1");
            return true;
        }else if((int)comp.size() == 3) {
            ans.push_back(mp(comp[0], mp(comp[1], comp[2])));
        }else if((int)comp.size() == 2) {
            a.push_back(mp(comp[0], comp[1]));
        }else {
            b.push_back(comp[0]);
        }
    }

    if((int)b.size() < (int)a.size()) {
        puts("-1");
        return true;
    }

    int j = 0;

    for(int i(0);i < (int)a.size();i++) {
        ans.push_back(mp(b[j++], a[i]));
    }

    for(j;j < (int)b.size();j += 3) {
        ans.push_back(mp(b[j], mp(b[j + 1], b[j + 2])));
    }

    for(int i(0);i < n / 3;i++) {
        int x, y, z;
        x = ans[i].first + 1;
        y = ans[i].second.first + 1;
        z = ans[i].second.second + 1;
        printf("%d %d %d\n", x, y, z);
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}