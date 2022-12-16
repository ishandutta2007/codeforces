#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const ll maxn = 1e3 + 10, inf = 1e9;
ll n, m, s, t;
struct Edge {
	ll v, w, nxt;
} e[maxn * maxn * 2];
ll h[maxn], cnt_e = 1;
void add(ll x, ll y, ll z) {
	e[++cnt_e] = {y, z, h[x]}, h[x] = cnt_e;
	e[++cnt_e] = {x, 0, h[y]}, h[y] = cnt_e;
}

ll now[maxn], dep[maxn];
bool bfs() {
	memset(dep, 0, sizeof dep);
	queue <ll> q;
	q.push(s), dep[s] = 1, now[s] = h[s];
	while (!q.empty()) {
		ll u = q.front(); q.pop();
		for (ll j = h[u]; j; j = e[j].nxt) {
			ll v = e[j].v, w = e[j].w;
			if (dep[v] || !w) continue;
			q.push(v), dep[v] = dep[u] + 1, now[v] = h[v];
			if (v == t) return 1;
		}
	}
	return 0;
}

ll dfs(ll u, ll in) {
	if (u == t) return in;
	ll rst = in;
	for (ll &j = now[u]; j; j = e[j].nxt) {
		ll v = e[j].v, w = e[j].w;
		if (dep[v] != dep[u] + 1 || !w) continue;
		ll out = dfs(v, min(rst, w));
		e[j].w -= out, rst -= out, e[j ^ 1].w += out;
		if (!out) dep[v] = 0;
		if (!rst) break;
	}
	return in - rst;
}

vector <ll> L, R;
ll match[maxn];

int main() {
	read(n, m);
	for (ll i = 1; i <= n; ++i) {
		ll x; read(x);
		if (x > m / 3) L.push_back(x);
		else R.push_back(x);
	}
	ll lenl = L.size(), lenr = R.size();
	s = lenl + lenr + 1, t = s + 1;
	for (ll i = 1; i <= lenl; ++i) {
		add(s, i, 1);
		for (ll j = 1; j <= lenr; ++j)
			if (L[i - 1] % R[j - 1] == 0 && 2 * L[i - 1] + R[j - 1] <= m) add(i, j + lenl, 1);
	}
	for (ll i = 1; i <= lenr; ++i) add(lenl + i, t, 1);
	ll maxflow = 0;
	while (bfs()) maxflow += dfs(s, inf);
	if (maxflow < lenl) return write("-1\n"), 0;
	for (ll i = 1; i <= lenl; ++i)
		for (ll j = h[i]; j; j = e[j].nxt) {
			ll v = e[j].v, w = e[j].w;
			if (w || v == s) continue;
			match[v - lenl] = i;
		}
	vector <pii> ans;
	for (ll i = 1; i <= lenr; ++i)
		if (match[i]) ans.push_back({2 * L[match[i] - 1] + R[i - 1], L[match[i] - 1] + R[i - 1]});
		else ans.push_back({R[i - 1] * 3, R[i - 1] * 2});
	write(ans.size(), '\n');
	for (pii p : ans) write(p.fir, ' ', p.sec, '\n');
	return 0;
}