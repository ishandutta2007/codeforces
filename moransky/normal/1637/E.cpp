// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5;

int n, m, a[N], c[N], idx, d[N], t, val[N];

vector<int> g[N];

map<int, int> M;

vector<PII> b[N];

int inline get(int x) {
    if (M.count(x)) return M[x];
    val[++idx] = x;
    return M[x] = idx;
}

bool ban[N];

int main() {
    int T; read(T);
    while (T--) {
        M.clear(), idx = 0;
        read(n), read(m);
        t = 0;
        for (int i = 1; i <= n; i++) b[i].clear();
        for (int i = 1; i <= n; i++) read(a[i]), c[get(a[i])]++;
        for (auto o: M) {
            b[c[o.se]].pb(mp(o.fi, get(o.fi)));
        }
        for (int i = 1; i <= n; i++)
            if (b[i].size()) d[++t] = i;
        for (int i = 1; i <= n; i++)
            sort(b[i].begin(), b[i].end(), greater<PII>() );
        LL ans = 0;
        while (m--) {
            int x, y; read(x), read(y);
            x = get(x), y = get(y);
            g[x].pb(y), g[y].pb(x);
        }
        for (int i = 1; i <= idx; i++) {
        	ban[i] = 1;
            for (int v: g[i]) ban[v] = 1;
            for (int j = 1; j <= t; j++) {
                int u = d[j];
                for (PII v: b[u]) {
                    if (!ban[v.se]) {
                    	chkMax(ans, 1ll * (val[i] + v.fi) * (u + c[i]));
                    	 break;
					}
                }
            }
            ban[i] = 0;
            for (int v: g[i]) ban[v] = 0;
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= n; i++) g[i].clear(), b[i].clear(), c[i] = 0;
    }
    return 0;
}