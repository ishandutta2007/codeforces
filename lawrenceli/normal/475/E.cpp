#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2005;

int n, m, ent[MAXN], exi[MAXN], dep[MAXN], cnt, bit[2*MAXN], dad[MAXN], par[MAXN], sze[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN], adj2[MAXN];
vector<int> st, nd;
ll ans, sum;

int query(int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[i];
    return ret;
}

void update(int i, int v) {
    for (i++; i<2*MAXN; i+=i&-i) bit[i] += v;
}

int getpar(int a) { return a == par[a] ? a : par[a] = getpar(par[a]); }

void merge(int a, int b) { par[getpar(a)] = getpar(b); }

void dfs(int cur, int p=-1) {
    dad[cur] = p;
    dep[cur] = p == -1 ? 0 : dep[p] + 1;
    vis[cur] = 1;
    ent[cur] = cnt++;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        if (vis[nxt]) {
            if (dep[nxt] < dep[cur])
                nd.push_back(nxt), st.push_back(cur);
        } else {
            dfs(nxt, cur);
        }
    }
    exi[cur] = cnt++;
}

int dfs2(int cur, int p=-1) {
    vector<int> v;
    if (p == -1) v.resize(adj2[cur].size());
    int s = sze[cur];
    for (int i=0; i<adj2[cur].size(); i++) {
        int nxt = adj2[cur][i];
        if (nxt == p) continue;
        int res = dfs2(nxt, cur);
        s += res;
        if (p == -1) v[i] = res;
    }
    sum += s*sze[cur];

    if (p == -1) {
        bool b = 0;
        int x = n-sze[cur];
        for (int i=0; i<v.size(); i++) {
            if (v[i] >= x/2) {
                sum += ll(v[i])*(x-v[i]);
                b = 1;
                break;
            }
        }
        if (!b) {
            vector<bool> dp(n+1, 0);
            dp[0] = 1;
            for (int i=0; i<v.size(); i++)
                for (int j=n; j>=0; j--)
                    if (dp[j]) {
                        if (j+v[i]<=n) dp[j+v[i]] = 1;
                    }
            for (int i=x/2; i>=0; i--)
                if (dp[i]) {
                    sum += ll(i)*(x-i);
                    break;
                }
        }
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);
    for (int i=0; i<st.size(); i++) {
        update(ent[st[i]], 1);
        update(ent[nd[i]], -1);
    }

    for (int i=0; i<n; i++) par[i] = i;
    for (int i=1; i<n; i++)
        if (query(exi[i])-query(ent[i]-1)>0)
            merge(i, dad[i]);
    for (int i=0; i<n; i++)
        sze[getpar(i)]++;

    for (int i=0; i<n; i++)
        for (int j=0; j<adj[i].size(); j++) {
            int k = adj[i][j];
            if (getpar(i) != getpar(k))
                adj2[getpar(i)].push_back(getpar(k));
        }

    for (int i=0; i<n; i++) {
        sort(adj2[i].begin(), adj2[i].end());
        adj2[i].resize(unique(adj2[i].begin(), adj2[i].end())-adj2[i].begin());
    }

    for (int i=0; i<n; i++)
        if (i == getpar(i)) {
            sum = 0;
            dfs2(i);
            ans = max(ans, sum);
        }

    cout << ans << '\n';
    return 0;
}