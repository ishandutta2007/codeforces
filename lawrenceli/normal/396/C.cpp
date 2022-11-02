//heavy-light
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>

using namespace std;

typedef long long ll;

const int MAXN = 300100;
const int MOD = 1e9 + 7;

int n;
vector<int> adj[MAXN];
int par[MAXN], sub[MAXN], dep[MAXN];
int head[MAXN], cmp[MAXN], ind[MAXN];
vector<vector<int> > chain, bit[2];

void dfs(int cur, int p) {
    sub[cur] = 1;
    dep[cur] = dep[p] + 1;
    head[cur] = -1;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        dfs(nxt, cur);
        sub[cur] += sub[nxt];
    }
}

void decomp(int cur, int p) {
    if (head[cur] == -1) {
        head[cur] = cur;
        cmp[cur] = chain.size();
        ind[cur] = 0;
        chain.push_back(vector<int>());
        chain[cmp[cur]].push_back(cur);
    }

    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (sub[nxt] > sub[cur] / 2) {
            head[nxt] = head[cur];
            cmp[nxt] = cmp[cur];
            ind[nxt] = ind[cur] + 1;
            chain[cmp[nxt]].push_back(nxt);
        }
        decomp(nxt, cur);
    }
}

void update(int b, int c, int i, int v) {
    for (i++; i<bit[b][c].size(); i+=i&-i)
        bit[b][c][i] = (bit[b][c][i] + v) % MOD;
}

int query(int b, int c, int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i)
        ret = (ret + bit[b][c][i]) % MOD;
    return ret;
}

int qclimb(int v) {
    int cur = v, ret1 = 0, ret2 = 0;
    while (cur != -1) {
        ret1 = (ret1 + query(0, cmp[cur], ind[cur])) % MOD;
        ret2 = (ret2 + query(1, cmp[cur], ind[cur])) % MOD;
        cur = par[head[cur]];
    }
    return (ret1 + ll(ret2) * dep[v]) % MOD;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=1; i<n; i++) {
        cin >> par[i];
        par[i] --;
        adj[par[i]].push_back(i);
    }
    par[0] = -1;

    dfs(0, 0);
    decomp(0, 0);

    for (int i=0; i<2; i++) bit[i].resize(chain.size());
    for (int i=0; i<chain.size(); i++)
        for (int j=0; j<2; j++)
            bit[j][i].resize(chain[i].size()+1);

    int q; cin >> q;
    for (int i=0; i<q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int v, x, k;
            cin >> v >> x >> k;
            v--;
            update(0, cmp[v], ind[v], (x + ll(k) * dep[v]) % MOD);
            update(1, cmp[v], ind[v], (MOD - k) % MOD);
        } else {
            int v; cin >> v;
            v--;
            cout << qclimb(v) << '\n';
        }
    }

    return 0;
}