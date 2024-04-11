#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

mt19937_64 rnd(123);
const int MAXN = 120000;
const ll MOD = 100000000000000003ll;
int was[MAXN];
int sz[MAXN];
int p[MAXN];
vector<int> eds[MAXN];
int n;

void dfs1(int v) {
	was[v] = 1;
	sz[v] = 1;
	for (int u: eds[v]) {
		if (!was[u]) {
			p[u] = v;
			dfs1(u);
			sz[v] += sz[u];
		}
	}
}

ll mul(ll a, ll b) {
	ll q = ll(ld(a) * ld(b) / ld(MOD));
	ll r = a * b - q * MOD;
	return (r + 6 * MOD) % MOD;
}

struct hsh {
	ll a;
	hsh(ll x = 0) {
		a = x % MOD;
	}
	hsh operator+(hsh x) {
		return hsh(a + x.a);
	}
	hsh operator-(hsh x) {
		return hsh(a - x.a + MOD);
	}
	hsh operator*(hsh x) {
		return mul(a, x.a);
	}
};

bool operator<(hsh a, hsh b) {
	return a.a < b.a;
}

hsh rn[MAXN];

hsh pw(hsh a, ll b) {
	hsh ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a);
		ans = (ans * a), --b;
	} return ans;
}

hsh bck(hsh x) {
	assert(x.a != 0);
	return pw(x, MOD - 2);
}

struct st {
	set<hsh> *ss;
	hsh df;
	hsh ml;
	hsh ad;
	st() {
		ss = new set<hsh>;
		df = 0;
		ad = 0;
		ml = 1;
	}
};

st merge(st a, st b) {
	if (a.ss->size() < b.ss->size())
		swap(a, b);
	hsh d1 = (a.df * a.ml) + a.ad;
	hsh d2 = (b.df * b.ml) + b.ad;
	a.ml = a.ml * d2;
	a.ad = a.ad * d2;
	b.ml = b.ml * d1;
	b.ad = b.ad * d1;
	hsh bc = bck(a.ml);
	for (auto x: *b.ss) {
		x = x * b.ml + b.ad;
		x = (x - a.ad) * bc;
		a.ss->insert(x);
	}
	return a;
}

st dfs2(int v, int h) {
	was[v] = 1;
	st now;
	now.df = 1;
	if (eds[v].size() < 4)
		now.ss->insert(hsh(rn[h] + 1));
	for (int u: eds[v]) {
		if (was[u])
			continue;
		st tmp = dfs2(u, h + 1);
		tmp.ad = tmp.ad + rn[h];
		now = merge(now, tmp);
	}

	return now;
}

int gfl = 0;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0);
	int bst = -1;
	for (int i = 0; i < n; ++i)
		if (sz[i] * 2 >= n && (bst == -1 || sz[i] < sz[bst]))
			bst = i;
	if (sz[bst] * 2 == n) {
		int a = bst;
		int b = p[a];
		for (int i = 0; i < eds[a].size(); ++i) {
			if (eds[a][i] == b) {
				eds[a].erase(eds[a].begin() + i);
				break;
			}
		}
		for (int i = 0; i < eds[b].size(); ++i) {
			if (eds[b][i] == a) {
				eds[b].erase(eds[b].begin() + i);
				break;
			}
		}
		eds[a].push_back(n);
		eds[b].push_back(n);
		eds[n].push_back(a);
		eds[n].push_back(b);
		++n;
		gfl = 1;
		bst = n - 1;
	}
	memset(was, 0, sizeof(was));
	for (int i = 0; i < n; ++i) {
		rn[i] = hsh(rnd() % MOD);
	}
	int ans = dfs2(bst, 0).ss->size() - gfl;
	cout << ans << "\n";
	return 0;
}