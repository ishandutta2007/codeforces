#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100100;
const int MAXLG = 18;
const int MOD = 1e9 + 7;

int n, dep[MAXN], dep2[MAXN], sub[MAXN], sub2[MAXN], sub3[MAXN], sum2[MAXN];
int a1[MAXN], a2[MAXN], a3[MAXN];
int jump[MAXN][MAXLG];
vector<pii> adj[MAXN];

void dfs(int cur, int p=-1, int wp=0) {
    dep[cur] = p == -1 ? 0 : dep[p] + 1;
    dep2[cur] = p == -1 ? 0 : (dep2[p]+wp)%MOD;
    sub[cur] = 1;
    jump[cur][0] = p == -1 ? cur : p;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i].fi, w = adj[cur][i].se;
        if (nxt == p) continue;
        dfs(nxt, cur, w);
        sub[cur] += sub[nxt];
        sub2[cur] = ((sub2[cur]+sub2[nxt])%MOD+(ll(w)*sub[nxt])%MOD)%MOD;
        sub3[cur] = (((sub3[cur]+sub3[nxt])%MOD+(ll(2*w)*sub2[nxt])%MOD)%MOD+(ll(sub[nxt])*w%MOD*w%MOD))%MOD;
    }
    sum2[cur] = sub3[cur];
}

//a1 - #, a2 - sum, a3 - sum^2
void dfs2(int cur, int p=-1) {
    sum2[cur] = (sum2[cur]+a3[cur])%MOD;
    int s2 = a2[cur], s3 = a3[cur];
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i].fi, w = adj[cur][i].se;
        if (nxt == p) continue;
        s2 = ((s2+sub2[nxt])%MOD+ll(w)*sub[nxt]%MOD)%MOD;
        s3 = (((s3+sub3[nxt])%MOD+ll(2*w)*sub2[nxt]%MOD)%MOD+ll(sub[nxt])*w%MOD*w%MOD)%MOD;
    }

    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i].fi, w = adj[cur][i].se;
        if (nxt == p) continue;
        a1[nxt] = n-sub[nxt];
        a2[nxt] = ((s2-(sub2[nxt]+ll(w)*sub[nxt]%MOD)%MOD+MOD)%MOD+ll(w)*a1[nxt]%MOD)%MOD;
        a3[nxt] = (((s3-((sub3[nxt]+ll(2*w)*sub2[nxt]%MOD)%MOD+ll(sub[nxt])*w%MOD*w%MOD)%MOD+MOD)%MOD+ll(2*w)*((a2[nxt]-ll(w)*a1[nxt]%MOD+MOD)%MOD)%MOD)%MOD+ll(a1[nxt])*w%MOD*w%MOD)%MOD;
        dfs2(nxt, cur);
    }
}

void initlca() {
    for (int k=1; k<MAXLG; k++)
        for (int i=0; i<n; i++)
            jump[i][k] = jump[jump[i][k-1]][k-1];
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k=MAXLG-1; k>=0; k--)
        if (dep[jump[b][k]] >= dep[a])
            b = jump[b][k];
    if (a == b) return a;
    for (int k=MAXLG-1; k>=0; k--)
        if (jump[a][k] != jump[b][k])
            a = jump[a][k], b = jump[b][k];
    return jump[a][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back(pii(b, c));
        adj[b].push_back(pii(a, c));
    }

    dfs(0);
    dfs2(0);
    initlca();

/*
    for (int i=0; i<n; i++)
        cout << sum2[i] << endl;
*/

    int q; cin >> q;
    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int l = lca(a, b), ans = 0;
        if (l != b) {
            int d = ((dep2[a]+dep2[b])%MOD-(2*dep2[l])%MOD+MOD)%MOD;
            ans = ((sub3[b]+ll(2*d)*sub2[b]%MOD)%MOD+ll(sub[b])*d%MOD*d%MOD)%MOD;
        } else {
            int d = (dep2[a]-dep2[b]+MOD)%MOD;
            ans = ((sub3[a]+a3[a])%MOD-((a3[b]+ll(2*d)*a2[b]%MOD)%MOD+ll(a1[b])*d%MOD*d%MOD)%MOD+MOD)%MOD;
        }
        cout << ((2*ans)%MOD-sum2[a]+MOD)%MOD << '\n';
    }
    return 0;
}