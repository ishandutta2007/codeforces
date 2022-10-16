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

const int N = 2e5 + 5, L = 18;

int n, a[N], du[N], dfn[N], dfncnt, pre[N], cnt, d[N], t, sz[N], fa[N][L], dep[N], f[N];

PII e[N];

vector<int> g[N];

LL ans;

void dfs(int u, int la) {
    dfn[u] = ++dfncnt;
    sz[u] = 1;
    pre[dfn[u]] = u;
    for (int i = 1; i < L; i++)
    	fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v: g[u]) {
    	if (v == la) continue;
    	fa[v][0] = u, dep[v] = dep[u] + 1;
    	dfs(v, u);
    	sz[u] += sz[v];
	}
}

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

set<int> s;
int inline lca(int x, int y) {
     if (dep[x] < dep[y]) swap(x, y);
     for (int i = L - 1; ~i; i--)
         if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
     if (x == y) return x;
     for (int i = L - 1; ~i; i--)
         if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
     return fa[x][0];
}

int inline get(int x) {
	if (!x) return 0;
	int c = 0;
	bool o = 0;
	if (*s.begin() < dfn[x]) o = 1;
	if (*--s.end() >= dfn[x] + sz[x]) o = 1;
	if (o) c++;
	auto it = s.upper_bound(dfn[x]);
	if (it != s.end() && *it < dfn[x] + sz[x]) {
		c++;
		int A = *it;
		it = s.lower_bound(dfn[x] + sz[x]);
		//if (it != s.begin()) {
			it--;
			int B = *it;
			if (lca(pre[A], pre[B]) == x) c++; 
		//}
	}
	return c < 2 ? 1 : 0;
}

void inline del(int x) {
//	cout << x << " ..del\n";
	int A = 0, B = 0, C = 0;
//	cout << C << "wtf\n";
	auto it = s.upper_bound(dfn[x]);
	if (it != s.end()) A = *it;
	it = s.lower_bound(dfn[x]);
	if (it != s.begin()) --it, B = *it;
//	cout << cnt << " qc\n";
	int fst = pre[*s.begin()];
	cnt -= get(pre[A]) + get(pre[B]) + get(x);
//	cout << get(pre[A]) << "for"<< pre[A] << endl;
//	cout << get(pre[B]) << "for"<< pre[B] << endl;
	//cout << get(x) << "for"<< x << endl;
	//cout << cnt << " nono\n";
	if (C != pre[A] && C != pre[B]) cnt -= get(C);//, cout << get(C) << " " << cnt << " here\n";
//	cout<<fst<<" "<<" " <<get(fst)<< " "<<cnt<<"why"<<"ns\n";
	if (fst != pre[A] &&fst != pre[B] &&fst != C) cnt -= get(fst);//, cout << " join" << cnt<<endl;
	//cout << pre[B] << " aa" << get(x) << " " << get(C) << " " << get(pre[A]) << " " << get(pre[B]) << " " << cnt << " " << "aiaiai\n";
	s.erase(dfn[x]);
	//cout << pre[A] << " why?" << get(pre[A]) << " " << get(pre[B]) << " " << get(C) << " mmp" << endl;
	cnt += get(pre[A]) + get(pre[B]);
	//cout<<cnt<<"nst\n";
	if (C != pre[A] && C != pre[B]) cnt += get(C);
	//cout<<fst<<" "<<" " <<get(fst)<< " "<<cnt<<"why"<<"ns\n";
	if (fst != pre[A] &&fst != pre[B] &&fst != C) cnt += get(fst);
	//cout<<cnt<<"ns\n";
	f[x] = fa[x][0];
}

int main() {
//	freopen("a.in", "r", stdin);
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), f[i] = i, s.insert(i), d[++t] = a[i], e[i] = mp(a[i], i);
    for (int i = 1, u, v; i < n; i++) {
        read(u), read(v);
        g[u].pb(v), g[v].pb(u);
        du[u]++, du[v]++;
    }
    
    dfs(1, 0);
    for (int i = 1; i <= n; i++) if (du[i] == 1) cnt++;
    sort(d + 1, d + 1 + t);
    sort(e + 1, e + 1 + n);
    t = unique(d + 1, d + 1 + t) - d - 1;
    for (int i = 1, j = 1; i <= t; i++) {
    	while (j <= n && e[j].fi < d[i]) {
    		del(e[j++].se);
		}
		//cout << cnt << "..." << d[i] << " " << d[i - 1] << endl;
		ans += (LL)(d[i] - d[i - 1]) * max(cnt, 2);
	//	cout << cnt << " na;a;a\n";
	}
    printf("%lld\n", ans);
    //cout <<dfn[2]<<"???"<<dfn[3]<<endl;
    return 0;
}