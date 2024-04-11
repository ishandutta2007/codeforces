#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 25;
const int MAXV = 1000;

int n, m, n1, n2;
char mat[MAXN][MAXN];
int r0, c0, t0, rs[MAXV], cs[MAXV], ts[MAXV];
bool v[MAXV][MAXN][MAXN], cap[2*MAXV][2*MAXV], vis[2*MAXV];
int from[2*MAXV];
int vs = 2*MAXV-2, vt = 2*MAXV-1;

int id(int r, int c) { return (r-1) * m + (c-1); }

bool dfs(int i) {
    if (vis[i]) return 0;
    vis[i] = 1;
    if (i == vt) return 1;
    for (int j=0; j<2*MAXV; j++)
        if (cap[i][j] && dfs(j)) {
            from[j] = i;
            return 1;
        }
    return 0;
}

bool check(ll mid) {
    memset(v, 0, sizeof(v));
    memset(cap, 0, sizeof(cap));
    for (int i=0; i<n1+n2; i++) {
        ll t = mid / ts[i];
        queue<pii> que;
        que.push(pii(rs[i], cs[i]));
        for (int j=0; j<=t && !que.empty(); j++) {
            int sze = que.size();
            for (int k=0; k<sze; k++) {
                int r = que.front().fi, c = que.front().se;
                que.pop();
                if (v[i][r][c]) continue;
                v[i][r][c] = 1;
                if (i<n1) cap[i][id(r, c)+2*n1] = 1;
                else cap[id(r, c)+2*n1+500][i] = 1;

                for (int dr=-1; dr<=1; dr++)
                    for (int dc=-1; dc<=1; dc++)
                        if ((dr == 0) != (dc == 0)) {
                            int nr = r+dr, nc = c+dc;
                            if (mat[nr][nc] == '.' && !v[i][nr][nc])
                                que.push(pii(nr, nc));
                        }
            }
        }
    }

    for (int i=0; i<n1; i++) cap[vs][i] = 1;
    for (int i=n1; i<n1+n2; i++) cap[i][vt] = 1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cap[id(i, j)+2*n1][id(i, j)+2*n1+500] = 1;

    for (int i=0; i<n1; i++) {
        memset(vis, 0, sizeof(vis));
        if (!dfs(vs)) return 0;
        int cur = vt;
        while (cur != vs) {
            int nxt = from[cur];
            cap[nxt][cur] = 0;
            cap[cur][nxt] = 1;
            cur = nxt;
        }
    }
    return 1;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> n1 >> n2;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> mat[i][j];

    cin >> r0 >> c0 >> t0;
    if (abs(n1-n2) != 1) {
        cout << -1;
        return 0;
    }

    memset(rs, -1, sizeof(rs));
    if (n1 < n2) rs[n1] = r0, cs[n1] = c0, ts[n1] = t0, n1++;
    else rs[n1+n2] = r0, cs[n1+n2] = c0, ts[n1+n2] = t0, n2++;

    for (int i=0; i<n1+n2; i++)
        if (rs[i] == -1)
            cin >> rs[i] >> cs[i] >> ts[i];

    ll lo = 0, hi = 1e12;
    while (lo < hi) {
        ll mid = lo+(hi-lo)/2;
        if (check(mid)) hi = mid;
        else lo = mid+1;
    }
    if (check(lo)) cout << lo;
    else cout << -1;
}