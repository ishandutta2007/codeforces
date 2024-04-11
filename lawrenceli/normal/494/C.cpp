#include <bits/stdc++.h>

using namespace std;

typedef double ld;

const int MAXN = 100100;
const int MAXLG = 17;
const int MAXQ = 5005;

int n, q, ar[MAXN];
int tab[MAXN][MAXLG]; //rmq

void init() {
    for (int i=0; i<n; i++)
        tab[i][0] = ar[i];
    for (int k=0; k<MAXLG-1; k++)
        for (int i=0; i<n; i++) {
            tab[i][k+1] = tab[i][k];
            if (i+(1<<k) < n)
                tab[i][k+1] = max(tab[i][k+1], tab[i+(1<<k)][k]);
        }
}

int rmq(int l, int r) {
    int ret = -1e9;
    for (int k=MAXLG-1; k>=0; k--)
        if (l+(1<<k)<=r)
            ret = max(ret, tab[l][k]), l += 1<<k;
    return ret;
}

struct data {
    int l, r;
    ld p;
    bool operator<(const data& d) const {
        return r-l != d.r-d.l ? r-l > d.r-d.l : p < d.p;
    }
} queries[MAXQ];

vector<int> adj[MAXQ];

bool in(data small, data big) {
    return small.l >= big.l && small.r <= big.r;
}

int maxa;
ld dp[MAXQ][2*MAXQ], tmp[2*MAXQ], pre[MAXQ];

bool cmp(int a, int b) {
    return queries[a].l < queries[b].l;
}

void dfs(int cur, int p=-1) {
    int m = -1e9;
    if (!adj[cur].empty()) {
        m = max(m, rmq(queries[cur].l, queries[adj[cur][0]].l));
        m = max(m, rmq(queries[adj[cur].back()].r, queries[cur].r));
    } else m = max(m, rmq(queries[cur].l, queries[cur].r));
    for (int i=0; i<adj[cur].size(); i++) {
        if (i+1<adj[cur].size()) {
            //assert(queries[adj[cur][i]].r <= queries[adj[cur][i+1]].l);
            m = max(m, rmq(queries[adj[cur][i]].r, queries[adj[cur][i+1]].l));
        }

        int nxt = adj[cur][i];
        dfs(nxt, cur);
    }

    ld prec = 0;
    for (int i=2*MAXQ-1; i>=0; i--) {
        if (i-MAXQ+maxa == m) prec++;
        tmp[i] = 1-prec;
        for (int j=0; j<adj[cur].size(); j++) {
            int nxt = adj[cur][j];
            pre[nxt] += dp[nxt][i];
            tmp[i] *= 1-pre[nxt];
        }
        tmp[i] = 1-tmp[i];
        if (i<2*MAXQ-1) dp[cur][i] = tmp[i]-tmp[i+1];
    }
    for (int i=2*MAXQ-1; i>=0; i--) {
        if (i<2*MAXQ-1) dp[cur][i+1] += dp[cur][i]*queries[cur].p;
        dp[cur][i] *= 1-queries[cur].p;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> q;
    for (int i=0; i<n; i++) cin >> ar[i];
    init();

    for (int i=0; i<q; i++) {
        cin >> queries[i].l >> queries[i].r >> queries[i].p;
        queries[i].l--;
    }
    queries[q].l = 0, queries[q].r = n, queries[q].p = 0;
    q++;

    sort(queries, queries+q);
    for (int i=0; i<q; i++) {
        for (int j=i-1; j>=0; j--)
            if (in(queries[i], queries[j])) {
                adj[j].push_back(i);
                break;
            }
    }

    for (int i=0; i<q; i++)
        sort(adj[i].begin(), adj[i].end(), cmp);
/*
    for (int i=0; i<q; i++)
        cout << queries[i].l << ' ' << queries[i].r << ' ' << queries[i].p << endl;
*/
    maxa = rmq(0, n);
    dp[0][0] = 1;
    dfs(0);

    ld ans = 0;
    for (int i=MAXQ; i<2*MAXQ; i++)
        ans += ld(i-MAXQ)*dp[0][i];
    cout << fixed << setprecision(10) << ans+maxa << '\n';
    return 0;
}