#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <set>
#include <stack>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 2005;
const int MAXV = 4000100;

int n, m, dr[200], dc[200];
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN], cyc[MAXN][MAXN];

void dfs(int str, int stc) {
    vector<pii> v;
    int r = str, c = stc;
    while (1) {
        if (cyc[r][c]) {
            cout << "-1\n";
            exit(0);
        }

        if (vis[r][c]) break;
        vis[r][c] = 1;
        if (mat[r][c] == '#') break;

        cyc[r][c] = 1;
        v.push_back(pii(r, c));
        int nr = r + dr[mat[r][c]], nc = c + dc[mat[r][c]];
        r = nr, c = nc;
    }

    for (int i=0; i<v.size(); i++)
        cyc[v[i].fi][v[i].se] = 0;
}

int id[MAXN][MAXN], cnt;
int adj[MAXV][4];
int sze[MAXV];
int dep[MAXV];

pii merge(pii p1, pii p2) {
    pii ret = pii(max(max(p1.fi, p1.se), max(p2.fi, p2.se)), 0);
    if (p1.fi != ret.fi) ret.se = max(ret.se, p1.fi);
    if (p1.se != ret.fi) ret.se = max(ret.se, p1.se);
    if (p2.fi != ret.fi) ret.se = max(ret.se, p2.fi);
    if (p2.se != ret.fi) ret.se = max(ret.se, p2.se);
    return ret;
}

struct data {
    int cur, par;
    bool end;
    data() {}
    data(int cur, int par, bool end) : cur(cur), par(par), end(end) {}
};

//stack<data> stk;
data stk[MAXV];
int stksze;
pii stuff[MAXV];

void push(data d) { stk[stksze++] = d; }
void pop() { stksze--; }
data top() { return stk[stksze-1]; }

pii ans;

void go(int st) {
    stksze = 0;
    push(data(st, -1, 0));

    pii x = pii(0, 0);

    while (stksze) {
        data d = top(); pop();
        if (d.end) {
            stuff[d.par] = merge(stuff[d.par], stuff[d.cur]);
            if (d.par == st) {
                pii p = stuff[d.cur];
                if (p.fi > x.fi) {
                    x.se = max(x.se, x.fi);
                    x.fi = p.fi;
                } else x.se = max(x.se, p.fi);
                if (p.se > x.fi) {
                    x.se = max(x.se, x.fi);
                    x.fi = p.se;
                } else x.se = max(x.se, p.se);
            }
            continue;
        }

        stuff[d.cur] = pii(dep[d.cur], 0);
        push(data(d.cur, d.par, 1));

        for (int i=0; i<sze[d.cur]; i++) {
            int nxt = adj[d.cur][i];
            dep[nxt] = dep[d.cur] + 1;
            push(data(nxt, d.cur, 0));
        }
    }

    if (x.fi > ans.fi) {
        ans.se = max(ans.se, ans.fi);
        ans.fi = x.fi;
    } else ans.se = max(ans.se, x.fi);
    if (x.se > ans.fi) {
        ans.se = max(ans.se, ans.fi);
        ans.fi = x.se;
    } else ans.se = max(ans.se, x.se);
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    dc['<'] = -1;
    dc['>'] = 1;
    dr['^'] = -1;
    dr['v'] = 1;

    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> mat[i][j];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (!vis[i][j]) dfs(i, j);

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            id[i][j] = cnt++;

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (mat[i][j] != '#') {
                int nr = i + dr[mat[i][j]], nc = j + dc[mat[i][j]];
                adj[id[nr][nc]][sze[id[nr][nc]]++] = id[i][j];
            }

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (mat[i][j] == '#')
                go(id[i][j]);

    cout << ans.fi + ans.se << '\n';
    return 0;
}