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
#include <list>
#include <cstring>

//#include <conio.h>

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
const double pi = acos(-1.0);

using namespace std;

const LL MOD1 = inf + 7;
const LL MOD2 = inf + 9;
const LL MOD3 = inf + 21;

struct type {
    LL val1, val2;
    type() {
        val1 = val2 = 0;
    }
    type(LL x) {
        val1 = x % MOD1;
        val2 = x % MOD2;
    }
    const type & operator = (const type & b) {
        val1 = b.val1 % MOD1;
        val2 = b.val2 % MOD2;
        return *this;
    }
    type operator + (const type & b) {
        type ans;
        ans.val1 = (val1 + b.val1) % MOD1;
        ans.val2 = (val2 + b.val2) % MOD2;
        return ans;
    }
    type operator * (const type & b) {
        type ans;
        ans.val1 = (val1 * b.val1) % MOD1;
        ans.val2 = (val2 * b.val2) % MOD2;
        return ans;
    }
    bool operator == (const type & b) {
        return (val1 == b.val1 && val2 == b.val2);
    }
};

int n, m, s, t;
vec< vec< pair< pair<int, LL>, int> > > g, gt;
// {{to, len}, id}

vec< LL > dist, revdist;
vec< type > dp1, dp2; 
// {to, id}

void getDist() {
    dist.resize(n + 1, inf64);
    dist[s] = 0;
    dp1.resize(n + 1, type(0ll));
    dp1[s] = type(1ll);
    set< pair<LL, int> > q;
    q.insert(mp(0ll, s));
    while(!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for(int i = 0;i < (int)g[v].size();i++) {
            int to = g[v][i].first.first;
            LL len = g[v][i].first.second;
            if(dist[to] > dist[v] + len) {
                q.erase(mp(dist[to], to));
                dist[to] = dist[v] + len;
                q.insert(mp(dist[to], to));
                dp1[to] = dp1[v];
            }else if(dist[to] == dist[v] + len) {
                dp1[to] = dp1[to] + dp1[v];
            }
        }
    }
}

void getRevDist() {
    revdist.resize(n + 1, inf64);
    revdist[t] = 0;
    dp2.resize(n + 1, type(0ll));
    dp2[t] = type(1ll);
    set< pair<LL, int> > q;
    q.insert(mp(0ll, t));
    while(!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for(int i = 0;i < (int)gt[v].size();i++) {
            int to = gt[v][i].first.first;
            LL len = gt[v][i].first.second;
            if(revdist[to] > revdist[v] + len) {
                q.erase(mp(revdist[to], to));
                revdist[to] = revdist[v] + len;
                q.insert(mp(revdist[to], to));
                dp2[to] = dp2[v];
            }else if(revdist[to] == revdist[v] + len) {
                dp2[to] = dp2[to] + dp2[v];
            }
        }
    }
}

vec< bool > yes; 

bool solve()
{       
    scanf("%d %d %d %d", &n, &m, &s, &t);

    g.resize(n + 1);
    gt.resize(n + 1);
    
    for(int i = 0;i < m;i++) {
        int u, v, l;    
        scanf("%d %d %d", &u, &v, &l);
        g[u].push_back(mp(mp(v, l), i));
        gt[v].push_back(mp(mp(u, l), i));
    }

    getDist();
    getRevDist();

    yes.resize(m);

    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < (int)g[i].size();j++) {
            int to = g[i][j].first.first;
            int id = g[i][j].second;
            LL len = g[i][j].first.second;
            // i -> to
            if(dist[i] == inf64 || revdist[to] == inf64) continue;
            if(dist[i] + len + revdist[to] != dist[t]) continue;
            if((dp1[i] * dp2[to]) == dp1[t]) yes[id] = 1;
        }
    }

    vec< LL > ans(m, inf);

    LL etalon = dist[t];

    for(int i = 1;i <= n;i++) {
        int u = i;
        for(int j = 0;j < (int)g[i].size();j++) {
            int v = g[i][j].first.first;
            int id = g[i][j].second;
            LL len = g[i][j].first.second;
            if(dist[u] == inf64 || revdist[v] == inf64) continue;
            if(yes[id]) continue;
            LL x, y;
            x = dist[u];
            y = revdist[v];
            LL value = etalon - x - y - 1;
            if(value > 0) {
                value = len - value;
                ans[id] = min(ans[id], value);
            }
        }
    }

    for(int i = 0;i < m;i++) {
        if(yes[i]) puts("YES");
        else if(ans[i] == inf) puts("NO");
        else printf("CAN %I64d\n", ans[i]);
    }

    return true;
}  

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}