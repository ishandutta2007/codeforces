#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 3e5 + 10, L = 2500, B = 13331, mod = 1e9 + 9;
struct node {
	int c;
	string s;
}a[maxn];
int hs[maxn];
void gethash(int i) {
	hs[i] = 0;
	for (char ch : a[i].s) hs[i] = (1ll * hs[i] * B % mod + ch - 'a' + 101) % mod;
}
struct ACAM {
	int trie[maxn][26], fail[maxn], tot;
	ll sum[maxn];
	vector <int> son[maxn];
	int NEW() {
		sum[++tot] = 0, son[tot].clear();
		for (int c = 0; c < 26; ++c) trie[tot][c] = 0;
		return tot;
	}
	void ins(node p) {
		int nw = 1;
		for (char ch : p.s) {
			int c = ch - 'a';
			if (!trie[nw][c]) trie[nw][c] = NEW();
			nw = trie[nw][c];
		}
		sum[nw] += p.c;
	}
	void dfs(int u) { for (int v : son[u]) sum[v] += sum[u], dfs(v); }
	void build(int lim) {
		tot = 0, NEW();
		for (int i = 1; i <= lim; ++i) ins(a[i]);
		queue <int> q;
		fail[1] = 1;
		for (int c = 0; c < 26; ++c)
			if (trie[1][c]) fail[trie[1][c]] = 1, q.push(trie[1][c]);
			else trie[1][c] = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			son[fail[u]].push_back(u);
			for (int c = 0; c < 26; ++c) {
				if (trie[u][c]) fail[trie[u][c]] = trie[fail[u]][c], q.push(trie[u][c]);
				else trie[u][c] = trie[fail[u]][c];
			}
		}
		dfs(1);
	}
	int query(string s) {
		int nw = 1; ll res = 0;
		for (char ch : s) {
			int c = ch - 'a';
			nw = trie[nw][c];
			res += sum[nw];
		}
		return res;
	}
	void print() {
		for (int i = 1; i <= tot; ++i) {
			printf("#%d : %lld fail : %d\n", i, sum[i], fail[i]);
			for (int c = 0; c < 26; ++c)
				if (trie[i][c]) printf("-%c> %d\n", 'a' + c, trie[i][c]);
		}
	} 
}T;

int n,m,pre[maxn],pw[maxn],lst;
ll query(string s) {
	if (n - lst > L) T.build(lst = n);
	ll res = T.query(s), len = s.size();
	for (int i = 1; i <= len; ++i) pre[i] = (1ll * pre[i - 1] * B % mod + s[i - 1] - 'a' + 101) % mod;
	for (int i = lst + 1; i <= n; ++i) {
		int let = a[i].s.size();
		for (int l = 1, r = let; r <= len; ++l, ++r) {
			int has = (pre[r] - 1ll * pre[l - 1] * pw[r - l + 1] % mod + mod) % mod;
			if (hs[i] == has) res += a[i].c;
		}
	}
	return res;
}

int main() {
//	freopen(".in", "r", stdin), freopen(".out", "w", stdout);
	pw[0] = 1;
	for (int i = 1; i <= 300000; ++i) pw[i] = 1ll * pw[i - 1] * B % mod;
	T.build(0);
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int t; string s;
		cin >> t >> s;
		if (t == 3) cout << query(s) << endl, fflush(stdout);
		else a[++n] = {t == 1 ? 1 : -1, s}, gethash(n);
	}
	return 0;
}