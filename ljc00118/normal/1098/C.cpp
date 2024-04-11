#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

queue <int> q;
vector <int> adj[N];
int fa[N], dep[N], son[N], ans[N];
ll sum, s;
int n, deg, tot;

void build(int d) {
	dep[1] = 1; sum = 1;
	for(register int i = 2; i <= n; i++) {
		fa[i] = (i + d - 2) / d;
		dep[i] = dep[fa[i]] + 1;
		sum += dep[i];
	}
}

int calc_min() {
	int l = 2, r = n, ans = -1;
	while(l <= r) {
		int mid = (l + r) >> 1; build(mid);
		if(sum <= s) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

void dfs(int u, int fa) {
	ans[++tot] = fa; int now = tot;
	for(register int i = 0; i < (int)adj[u].size(); i++) { int v = adj[u][i]; dfs(v, now); }
}

int main() {
	read(n); read(s);
	if(s < 2 * n - 1 || s > (ll)n * (n + 1) / 2) { cout << "No" << endl; return 0; }
	cout << "Yes" << endl;
	if(s == (ll)n * (n + 1) / 2) {
		for(register int i = 2; i <= n; i++) print(i - 1, i == n ? '\n' : ' ');
		return 0;
	}
	deg = calc_min(); build(deg); int x = n;
	while(x >= 1 && dep[x] == dep[n]) x--; x++;
	for(register int i = 2; i <= n; i++) son[fa[i]]++;
	int now = x; while(now) {
		son[now] = (1 << 30);
		now = fa[now];
	}
	for(register int i = n; i >= 1; i--) if(son[i] == 0) q.push(i);
	int last = -1;
	while(sum < s) {
		int u = q.front(); q.pop();
		if(sum + dep[x] + 1 - dep[u] > s) { last = u; break; }
		son[fa[u]]--; if(!son[fa[u]]) q.push(fa[u]);
		sum += (dep[x] + 1 - dep[u]); dep[u] = dep[x] + 1; fa[u] = x; x = u;
	}
	if(sum < s) {
		int now = x;
		while(sum + dep[now] + 1 - dep[last] != s) now = fa[now];
		fa[last] = now;
	}
	for(register int i = 2; i <= n; i++) adj[fa[i]].push_back(i);
	dfs(1, 0);
	for(register int i = 2; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
	return 0;
} // fake