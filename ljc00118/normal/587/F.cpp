#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e5 + 5, B = 350;

struct Q {
	int a, b, c;
	Q (int x = 0, int y = 0, int z = 0) : a(x), b(y), c(z) {}
};

vector <char> str[N];
vector <int> adj[N];
vector <Q> qry[N];
vector <ll> s[N];
queue <int> q;
char c[N];
ll ans[N];
int f[N], ch[N][26], fail[N], id[N], tops[N], siz[N];
int n, m, tot, dfn;

inline int lowbit(int x) { return x & -x; }

inline void add(int x, int y) {
	while (x <= tot + 1) {
		f[x] += y;
		x += lowbit(x);
	}
}

inline int query(int x) {
	int ans = 0;
	while (x) {
		ans += f[x];
		x ^= lowbit(x);
	}
	return ans;
}

void dfs1(int u) {
	tops[u] = ++dfn; siz[u] = 1;
	for (auto v : adj[u]) dfs1(v), siz[u] += siz[v];
}

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", c + 1);
		int len = strlen(c + 1), now = 0;
		for (int j = 1; j <= len; j++) {
			str[i].push_back(c[j]);
			int x = c[j] - 'a';
			if (!ch[now][x]) ch[now][x] = ++tot;
			now = ch[now][x];
		}
		id[i] = now;
	}
	for (int i = 0; i < 26; i++) if (ch[0][i]) q.push(ch[0][i]);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; i++) {
			if (!ch[u][i]) continue;
			int v = ch[u][i], tmp = u;
			while (tmp) {
				tmp = fail[tmp];
				if (ch[tmp][i]) {
					fail[v] = ch[tmp][i];
					break;
				}
			}
			q.push(v);
		}
	}
	for (int i = 1; i <= tot; i++) adj[fail[i]].push_back(i);
	dfs1(0);
	for (int i = 1; i <= n; i++) {
		if (str[i].size() > B) {
			memset(f, 0, sizeof(f));
			s[i].resize(n + 1);
			int now = 0;
			for (int j = 0; j < (int)str[i].size(); j++) {
				now = ch[now][str[i][j] - 'a'];
				// cout << "?" << i << " " << now << " " << tops[now] << endl;
				add(tops[now], 1);
			}
			for (int j = 1; j <= n; j++) {
				s[i][j] = query(tops[id[j]] + siz[id[j]] - 1) - query(tops[id[j]] - 1) + s[i][j - 1];
				// cout << "!" << i << " " << j << " " << s[i][j] - s[i][j - 1] << endl;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		int l, r, k;
		read(l); read(r); read(k);
		if (str[k].size() <= B) qry[l - 1].emplace_back(k, -1, i), qry[r].emplace_back(k, 1, i);
		else ans[i] = s[k][r] - s[k][l - 1];
	}
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++) {
		add(tops[id[i]], 1); add(tops[id[i]] + siz[id[i]], -1);
		for (auto j : qry[i]) {
			int now = 0; ll sum = 0;
			for (int k = 0; k < (int)str[j.a].size(); k++) {
				now = ch[now][str[j.a][k] - 'a'];
				sum += query(tops[now]);
			}
			ans[j.c] += sum * j.b;
		}
	}
	for (int i = 1; i <= m; i++) print(ans[i], '\n');
	return 0;
}