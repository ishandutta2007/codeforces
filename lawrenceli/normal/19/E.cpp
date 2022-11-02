#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 10010;

int n, m, par[MAXN], dep[MAXN], ent[MAXN], exi[MAXN], cnt;
int bit[2][2*MAXN];
int u[MAXN], v[MAXN];
vector<pii> adj[MAXN];
bool vis[MAXN], col[MAXN];
vector<int> back, back2;

void dfs(int cur, int p=-1) {
    vis[cur] = 1;
    par[cur] = p;
    dep[cur] = p == -1 ? 0 : dep[p] + 1;
    ent[cur] = cnt++;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i].fi;
        if (!vis[nxt]) {
            col[nxt] = col[cur]^1;
            dfs(nxt, cur);
        } else if (nxt != p && dep[nxt] < dep[cur]) {
            if (col[nxt] == col[cur])
                back.push_back(adj[cur][i].se);
            else
                back2.push_back(adj[cur][i].se);
        }
    }
    exi[cur] = cnt++;
}

void update(int c, int i, int v) {
    for (i++; i<2*MAXN; i+=i&-i) bit[c][i] += v;
}

int query(int c, int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[c][i];
    return ret;
}

void tupdate(int c, int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    update(c, exi[a], 1);
    update(c, exi[b], -1);
}

int tquery(int c, int a) {
    return query(c, ent[a])-query(c, exi[a]);
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }

    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &u[i], &v[i]);
        u[i]--, v[i]--;
        adj[u[i]].push_back(pii(v[i], i));
        adj[v[i]].push_back(pii(u[i], i));
    }

    for (int i=0; i<n; i++)
        if (!vis[i])
            dfs(i);

    if (back.empty()) {
        printf("%d\n", m);
        for (int i=0; i<m; i++) printf("%d ", i+1);
    } else {
        vector<int> ans;
        if (back.size() == 1)
            ans.push_back(back[0]+1);
        for (int i=0; i<back.size(); i++)
            tupdate(0, u[back[i]], v[back[i]]);
        for (int i=0; i<back2.size(); i++)
            tupdate(1, u[back2[i]], v[back2[i]]);
        for (int i=0; i<m; i++) {
            int a = u[i], b = v[i];
            if (dep[a] > dep[b]) swap(a, b);
            if (par[b] != a) continue; //back edge
            if (tquery(0, b) == back.size() && !tquery(1, b))
                ans.push_back(i+1);
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for (int i=0; i<ans.size(); i++)
            printf("%d ", ans[i]);
    }

    return 0;
}