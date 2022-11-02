#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>

using namespace std;

const int MAXN = 200100;

int n, m, a[MAXN], sgn[2];
vector<int> adj[MAXN];

int par[MAXN], dep[MAXN], sub[MAXN];
int head[MAXN], cmp[MAXN], ind[MAXN];

void dfs(int cur, int p) {
    par[cur] = p;
    if (cur != 0) dep[cur] = dep[p] + 1;
    sub[cur] = 1;
    head[cur] = cur;

    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        dfs(nxt, cur);
        sub[cur] += sub[nxt];
    }
}

vector<vector<int> > chain, bit;

void decomp(int cur, int p) {
    if (head[cur] == cur) {
        cmp[cur] = chain.size();
        ind[cur] = 0;
        chain.push_back(vector<int>());
        chain[cmp[cur]].push_back(cur);
    }

    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;

        if (sub[nxt] > sub[cur] / 2) {
            head[nxt] = head[cur];
            cmp[nxt] = cmp[cur];
            ind[nxt] = ind[cur] + 1;
            chain[cmp[nxt]].push_back(nxt);
        }

        decomp(nxt, cur);
    }
}

void update(int c, int i, int v) {
    for (i++; i<bit[c].size(); i+=i&-i) bit[c][i] += v;
}

int query(int c, int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[c][i];
    return ret;
}

int go(int cur) {
    int ret = 0;

    while (cur != -1) {
        ret += query(cmp[cur], ind[cur]);
        cur = par[head[cur]];
    }

    return ret;
}

int main() {
    ios :: sync_with_stdio(false);

    sgn[0] = 1; sgn[1] = -1;

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    decomp(0, -1);

    bit.resize(chain.size());
    for (int i=0; i<bit.size(); i++)
        bit[i].resize(chain[i].size() + 1);

    for (int i=0; i<m; i++) {
        int qtype; cin >> qtype;
        if (qtype == 1) {
            int x, v; cin >> x >> v;
            x--;
            v *= sgn[dep[x] & 1];
            update(cmp[x], ind[x], v);
        } else {
            int x; cin >> x;
            x--;
            cout << a[x] + sgn[dep[x] & 1] * go(x) << '\n';
        }
    }

    return 0;
}