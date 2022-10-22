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

const int N = 5e5 + 5;
char buffer[N];

inline void readString(string &s) {
    scanf("%s", buffer);
    s = buffer;
    s = "?" + s;
}

const char *WHITE = "White";
const char *BLACK = "Black";
const char *DRAW = "Draw";

inline bool meq2bits(int x) {
    return x > 0 && (x & (x - 1));
}

bool check(const vector< int > &g, int mask) {
    for (int v = 0; v < (int)g.size(); v++) {
        if ((1 << v) & mask) {
            if (meq2bits(g[v] & mask)) {
                return true;
            }
        }
    }
    return false;
}

int game(const vector< int > &g, int whiteMask, int blackMask, int xod) {
    if (check(g, whiteMask)) return 1; // white
    if ((1 << g.size()) == 1 + whiteMask + blackMask) return 0; // draw
    if (xod == 0) { // white
        for (int i = 0; i < (int)g.size(); i++) {
            if ((1 << i) & whiteMask) continue;
            if ((1 << i) & blackMask) continue;
            if (game(g, whiteMask | (1 << i), blackMask, xod ^ 1) == 1) {
                return 1;
            }
        }
        return 0;
    } else { // black
        for (int i = 0; i < (int)g.size(); i++) {
            if ((1 << i) & whiteMask) continue;
            if ((1 << i) & blackMask) continue;
            if (game(g, whiteMask, blackMask | (1 << i), xod ^ 1) == 0) {
                return 0;
            }
        }
        return 1;
    }
}

bool check(vector< int > vs, vector< pii > es, string colors)  {
    sort(vs.begin(), vs.end());
    for (pii &p : es) {
        p.first = lower_bound(vs.begin(), vs.end(), p.first) - vs.begin();
        p.second = lower_bound(vs.begin(), vs.end(), p.second) - vs.begin();
    }
    int n = (int)vs.size();
    vector< int > g(n);
    for (pii p : es) {
        g[p.first] |= 1 << p.second;
        g[p.second] |= 1 << p.first;
    }
    int whiteMask = 0;
    for (int i = 0; i < (int)vs.size(); i++) {
        if (colors[vs[i]] == 'W') {
            whiteMask |= (1 << i);
        }
    }
    return game(g, whiteMask, 0, 0);
}

int bfs(int s, int t, const vector< vector< int > > &g) {
    int n = (int)g.size();
    vector< int > dist(n + 1, inf);
    dist[s] = 0;
    queue< int > q;
    q.push(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    return dist[t] % 2;
}

void solve(bool print = false) {
    int n;
    scanf("%d", &n);
    print &= (n != 12);
    if (print) {
        cout << "n=" << n << ",";
    }
    vector< vector< int > > g(n + 1);
    vector< pii > es;
    es.reserve(n - 1);
    for (int u, v, i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        if (print) {
            cout << "(" << u << "," << v << ");";
        }
        g[u].push_back(v);
        g[v].push_back(u);
        es.push_back({u, v});
    }
    string colors;
    readString(colors);
    if (print) cout << colors << " ";
    if (n <= 2) {
        puts(DRAW);
        return;
    }
    for (pii ed : es) {
        if (colors[ed.first] == colors[ed.second] && colors[ed.first] == 'W') {
            puts(WHITE);
            return;
        }
    }
    for (int v = 1; v <= n; v++) {
        int ok = colors[v] == 'W';
        int cntWhiteNeighs = ok;
        for (int to : g[v]) {
            if (colors[to] == 'W') {
                ok = 1;
                cntWhiteNeighs++;
            }
        }
        if (ok && (int)g[v].size() >= 3 || cntWhiteNeighs >= 2) {
            puts(WHITE);
            return;
        }
        if ((int)g[v].size() >= 4) {
            puts(WHITE);
            return;
        }
    }
    for (int v = 1; v <= n; v++) {
        int cnt = 0;
        for (int to : g[v]) {
            if ((int)g[to].size() >= 3) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            puts(WHITE);
            return;
        }
    }
    if (n <= 5) {
        vector< int > vs(n);
        for (int i = 0; i < n; i++) {
            vs[i] = i + 1;
        }
        if (check(vs, es, colors)) {
            puts(WHITE);
        } else {
            puts(DRAW);
        }
        return;
    }
    for (int v = 1; v <= n; v++) {
        if (colors[v] == 'W' && (int)g[v].size() >= 2) {
            puts(WHITE);
            return;
        }
    }
    for (int v = 1; v <= n; v++) {
        if ((int)g[v].size() < 3) continue;
        int cn = 0;
        for (int to : g[v]) {
            if ((int)g[to].size() >= 2) {
                cn++;
            }
        }
        if (cn >= 2) {
            puts(WHITE);
            return;
        }
    }
    int cnt3 = 0;
    int cntw = 0;
    for (int v = 1; v <= n; v++) {
        if ((int)g[v].size() >= 3) {
            cnt3++;
        }
        if (colors[v] == 'W') {
            cntw++;
        }
    }
    if (cnt3 + cntw >= 3) {
        puts(WHITE);
        return;
    }
    if (cnt3 + cntw <= 1) {
        puts(DRAW);
        return;
    }
    assert(cntw + cnt3 == 2);
    int s = -1;
    int t = -1;
    int need = 1;
    for (int v = 1; v <= n; v++) {
        if ((int)g[v].size() < 3 && colors[v] != 'W') continue;
        if (colors[v] == 'W') {
            need ^= 1;
        }
        if (s == -1) {
            s = v;
        } else {
            t = v;
        }
    }
    puts(bfs(s, t, g) == need ? DRAW : WHITE);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int tt;

    scanf("%d", &tt);

    for (int ti = 0; ti < tt; ti++) {
//        solve(ti + 1 == 449 && tt == 40000);
        solve();
    }

    return 0;
}