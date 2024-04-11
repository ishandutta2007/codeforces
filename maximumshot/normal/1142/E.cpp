#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef pair<long double, long double> pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

map<pii, int> mem;

int ask(int fr, int to) {
    if (mem.count({fr, to})) {
        return mem[make_pair(fr, to)];
    }
    if (mem.count({to, fr})) {
        return !mem[make_pair(to, fr)];
    }
    cout << "? " << fr << " " << to << endl;
    int res;
    cin >> res;
    mem[make_pair(fr, to)] = res;
    return res;
}

const int N = 1e5 + 5;

int n, m;
vector<int> g[N], gr[N], h[N];
vector<int> tops;
int used[N];
int color[N], curColor = 0;

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    tops.push_back(v);
}

void mark(int v) {
    used[v] = 1;
    color[v] = curColor;
    for (int to : gr[v]) {
        if (!used[to]) {
            mark(to);
        }
    }
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    for (int v = 1; v <= n; v++) {
        if (!used[v]) {
            dfs(v);
        }
    }

    reverse(tops.begin(), tops.end());

    fill(used + 1, used + n + 1, 0);

    for (int v : tops) {
        if (!used[v]) {
            mark(v);
            curColor++;
        }
    }

    vector<vector<int>> comps(curColor);
    vector<int> din(curColor);

    for (int v = 1; v <= n; v++) {
        comps[color[v]].push_back(v);
        for (int to : g[v]) {
            if (color[v] == color[to]) continue;
            h[color[v]].push_back(color[to]);
        }
    }

    for (int cv = 0; cv < curColor; cv++) {
        sort(h[cv].begin(), h[cv].end());
        h[cv].erase(unique(h[cv].begin(), h[cv].end()), h[cv].end());
    }

    for (int cv = 0; cv < curColor; cv++) {
        for (int cto : h[cv]) {
            din[cto]++;
        }
    }

    vector<int> topComps;

    for (int cv = 0; cv < curColor; cv++) {
        if (din[cv] == 0) {
            topComps.push_back(cv);
        }
    }

    int TOP = comps[topComps.back()].back();

    while ((int)topComps.size() > 1) {
        int i = (int)topComps.size() - 2;
        int I = topComps[i];
        int j = i + 1;
        int J = topComps[j];
        int q = comps[I].back();
        if (!ask(TOP, q)) {
            TOP = q;
            swap(topComps[i], topComps[j]);
            continue;
        }
        comps[I].pop_back();
        if (!comps[I].empty()) {
            continue;
        }
        swap(topComps[i], topComps[j]);
        topComps.pop_back();
        for (int cto : h[I]) {
            if (!--din[cto]) {
                topComps.push_back(cto);
                int sz = (int)topComps.size();
                swap(topComps[sz - 2], topComps[sz - 1]);
            }
        }
    }

    cout << "! " << TOP << "\n";

    return 0;
}