#include <bits/stdc++.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

struct Edge {
    int u, v, w;
    int to(int _v) { return (_v == v?u : v); }
};

int n, m, s, t;
vec< vec< int > > g;
vec< Edge > ed;
map< pii, int > cr;

void read() {
    cin >> n >> m >> s >> t;
    g.resize(n + 1);
    for(int u, v, w, i = 0;i < m;i++) {
        cin >> u >> v >> w;
        if(u > v) swap(u, v);
        cr[{u, v}]++;
        ed.push_back({u, v, w});
        g[u].push_back(i);
        g[v].push_back(i);
    }
}

bool chk(int e) {
    int u, v;
    u = ed[e].u;
    v = ed[e].v;
    if(u > v) swap(u, v);
    return cr[{u, v}] > 1;
}

bool bfs(vec< int > & way, int _e = -1, bool need_way = 1) {
    vec< int > dist(n + 1, inf), par(n + 1, -1);
    queue< int > q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int e : g[v]) {
            if(e == _e) continue;
            int to = ed[e].to(v);
            if(dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                par[to] = e;
                q.push(to);
            }
        }
    }
    if(dist[t] == inf) return 0;
    if(need_way) {
        int u = t;
        do {
            way.push_back(par[u]);
            u = ed[par[u]].to(u);
        } while (u != s);
        reverse(ALL(way));
    }
    return 1;
}

int answer = inf + inf + 1;
vec< int > res_list;

//

vec< int > fup, tin, used;
int timer;

int dfs(int v, int _e, int par = -1) {
    int cnt = v == s || v == t, to_cnt;
    tin[v] = fup[v] = timer++;
    used[v] = 1;
    for(int e : g[v]) {
        if(e == _e) continue;
        int to = ed[e].to(v);
        if(to == par) continue;
        if(used[to]) fup[v] = min(fup[v], tin[to]);
        else {
            to_cnt = dfs(to, _e, v);
            cnt += to_cnt;
            fup[v] = min(fup[v], fup[to]);
            if(to_cnt == 1 && tin[v] < fup[to] && !chk(e)) {
                if(answer > ed[e].w + ed[_e].w) {
                    answer = ed[e].w + ed[_e].w;
                    res_list = {_e, e};
                }
            }
        }
    }
    return cnt;
}

bool solve() {

    read();

    vec< int > way, tmp;

    if(!bfs(way)) {
        cout << 0 << '\n' << 0 << '\n';
        return true;
    }

    fup. resize(n + 1);
    tin. resize(n + 1);
    used.resize(n + 1);

    for(int e : way) {
        if(!bfs(tmp, e, 0)) {
            if(answer > ed[e].w) {
                answer = ed[e].w;
                res_list = {e};
            }
        }else {
            int u, v;
            tie(u, v) = mp(ed[e].u, ed[e].v);
            if(u > v) swap(u, v);
            cr[{u, v}]--;
            timer = 0;
            used.assign(n + 1, 0);
            dfs(s, e);
            cr[{u ,v}]++;
        }
    }

    if(answer == inf + inf + 1) {
        cout << -1 << '\n';
        return true;
    }

    cout << answer << '\n' << (int)res_list.size() << '\n';
    for(int e : res_list) cout << e + 1 << ' ';
    cout << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}