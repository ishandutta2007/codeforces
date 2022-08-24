#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 120000;
const int SQ = 330;

int len[MAXN * 2];
int sf[MAXN * 2];
ll pr[MAXN];
int cc = 0;
int tm = 0;
int tin[MAXN];
int tout[MAXN];
ll ff[MAXN];
int was[MAXN * 2];
int go[MAXN * 3][26];
int lb[MAXN];
int rb[MAXN];
int kb[MAXN];
int n, q;
int dp[MAXN * 3];
int pp[MAXN];
int pc[MAXN];
int pl[MAXN];
queue<int> qu;
char buf[MAXN];
string s[MAXN];
vector<int> gg[MAXN];
vector<int> gg2[MAXN];
map<pair<int, int>, ll> mm;
vector<int> eds[MAXN];
int fl[MAXN * 2];

void clear() {
	cc = 1;
	sf[0] = -1;
	for (int i = 0; i < 26; ++i)
		go[0][i] = -1;
	len[0] = 0;
	fl[0] = 0;
}

int newn(int l) {
	fl[cc] = 0;
	len[cc] = l;
	for (int i = 0; i < 26; ++i)
		go[cc][i] = -1;
	sf[cc] = -1;
	was[cc] = 0;
	return cc++;
}

void dfs1(int v) {
	was[v] = 1;
	dp[v] = fl[v];
	for (int i = 0; i < 26; ++i) {
		int u = go[v][i];
		if (u != -1) {
			if (!was[u])
				dfs1(u);
			dp[v] += dp[u];
		}
	}
}

void build_sa(const string &s) {
	clear();
	int lst = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		int nn = newn(i + 1);
		int c = s[i] - 'a';
		int now = lst;
		while (now != -1 && go[now][c] == -1)
			go[now][c] = nn, now = sf[now];
		if (now == -1) {
			sf[nn] = 0;
			lst = nn;
			continue;
		}
		int p = go[now][c];
		if (len[p] == len[now] + 1) {
			sf[nn] = p;
			lst = nn;
		}
		else {
			int q = newn(len[now] + 1);
			sf[q] = sf[p];
			memcpy(go[q], go[p], sizeof(go[p]));
			sf[p] = q;
			sf[nn] = q;
			while (now != -1 && go[now][c] == p)
				go[now][c] = q, now = sf[now];
			lst = nn;
		}
	}
	while (lst != -1)
		fl[lst] = 1, lst = sf[lst];
	dfs1(0);
}

ll getf(int x) {
	ll ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		ans += ff[x];
	return ans;
}

void addf(int x, int d) {
	for (; x < tm; x |= (x + 1))
		ff[x] += d;
}


void clear2() {
	sf[0] = 0;
	for (int i = 0; i < 26; ++i)
		go[0][i] = -1;
	cc = 1;
}

int newn2(int p, int c) {
	pp[cc] = p;
	pc[cc] = c;
	for (int i = 0; i < 26; ++i)
		go[cc][i] = -1;
	sf[cc] = -1;
	return cc++;
}

void add(const string &s, int k) {
	int now = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		int c = s[i] - 'a';
		if (go[now][c] != -1)
			now = go[now][c];
		else
			now = go[now][c] = newn2(now, c);
	}
	pl[k] = now;
}


void dfs2(int v) {
	tin[v] = tm++;
	for (int i: eds[v])
		dfs2(i);
	tout[v] = tm;
}

void calc(int x) {
	for (int i = 0; i < 26; ++i)
		if (go[x][i] != -1)
			qu.push(go[x][i]);
	if (x == 0) {
		sf[x] = 0;
		for (int i = 0; i < 26; ++i)
			if (go[x][i] == -1)
				go[x][i] = 0;
		return;
	}
	if (pp[x] == 0)
		sf[x] = 0;
	else
		sf[x] = go[sf[pp[x]]][pc[x]];
	eds[sf[x]].push_back(x);
	for (int i = 0; i < 26; ++i)
		if (go[x][i] == -1)
			go[x][i] = go[sf[x]][i];
}


void build_ak() {
	qu.push(0);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		calc(x);
	}
	dfs2(0);
}



int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf(" %s", buf);
		s[i] = buf;
	}
	for (int i = 0; i < q; ++i) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		--l;
		--k;
		lb[i] = l;
		rb[i] = r;
		kb[i] = k;
		gg[k].push_back(l);
		gg[k].push_back(r);
		gg2[l].push_back(k);
		gg2[r].push_back(k);
	}
	for (int i = 0; i < n; ++i) {
		if ((int)s[i].size() < SQ)
			continue;
		build_sa(s[i]);
		pr[0] = 0;
		for (int j = 0; j < n; ++j) {
			int now = 0;
			for (int k = 0; k < (int)s[j].size() && now != -1; ++k)
				now = go[now][s[j][k] - 'a'];
			pr[j + 1] = pr[j] + (now != -1 ? dp[now] : 0);
		}
		for (int j: gg[i])
			mm[make_pair(i, j)] = pr[j];
	}
	clear2();
	for (int i = 0; i < n; ++i) {
		if ((int)s[i].size() < SQ)
			add(s[i], i);
	}
	build_ak();
	for (int i = 0; i <= n; ++i) {
		for (int j: gg2[i]) {
			if ((int)s[j].size() >= SQ)
				continue;
			int now = pl[j];
			ll ans = 0;
			while (now != 0) {
				ans += getf(tin[now]);
				now = pp[now];
			}
			mm[make_pair(j, i)] = ans;
		}
		if (i == n || (int)s[i].size() >= SQ)
			continue;
		int x = pl[i];
		addf(tin[x], 1);
		addf(tout[x], -1);
	}
	for (int i = 0; i < q; ++i)
		printf("%lld\n", mm[make_pair(kb[i], rb[i])] - mm[make_pair(kb[i], lb[i])]);
	return 0;
}