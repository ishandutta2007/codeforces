#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int n, m, vis[MAXN], val[MAXN], ans;
vector<int> adj[MAXN];

int par[MAXN];
struct data {
    set<int>* st;
    int add;
} dat[MAXN];

data merge(data d1, data d2) {
    if (d1.st->size() > d2.st->size()) swap(d1, d2);
    for (typeof(d1.st->begin()) it=d1.st->begin(); it!=d1.st->end(); it++) {
        val[*it] += d1.add-d2.add;
        d2.st->insert(*it);
    }
    return d2;
}

int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }
void merge(int a, int b) {
    a = getpar(a), b = getpar(b);
    if (a == b) return;
    par[a] = b;
    dat[b] = merge(dat[a], dat[b]);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

void dfs(int cur) {
    vis[cur] = 1;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (vis[nxt]) {
            if (getpar(nxt) != getpar(cur)) {
                dat[getpar(nxt)].add = val[cur]+dat[getpar(cur)].add+1-val[nxt];
                merge(nxt, cur);
            } else ans = gcd(ans, abs(val[cur]+1-val[nxt]));
        } else {
            val[nxt] = val[cur]+1;
            dat[nxt].add = dat[getpar(cur)].add;
            merge(cur, nxt);
            dfs(nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }

    for (int i=0; i<n; i++)
        par[i] = i, dat[i].st = new set<int>(), dat[i].st->insert(i), dat[i].add = 0;

    for (int i=0; i<n; i++)
        if (!vis[i])
            dfs(i);

    if (ans == 0) cout << n << '\n';
    else cout << ans << '\n';
    return 0;
}