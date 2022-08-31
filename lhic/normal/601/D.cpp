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


typedef long long ll;
typedef long double ld;

using namespace std;

const ll M1 = 1000000007;
const ll M2 = 1000000009;
const ll P = 23917;
const int MAXN = 310000;


struct hsh {
	ll a, b;
	hsh() {
		a = b = 0;
	}
	hsh(ll a, ll b) : a(a), b(b) {
	}
	bool operator==(const hsh& x) {
		return a == x.a && b == x.b;
	}
	hsh operator+(hsh x) {
		hsh xx;
		xx.a = a + x.a;
		if (xx.a >= M1)
			xx.a -= M1;
		xx.b = b + x.b;
		if (xx.b >= M2)
			xx.b -= M2;
		return xx;
	}
	hsh operator-(hsh x) {
		hsh xx;
		xx.a = a - x.a;
		if (xx.a < 0)
			xx.a += M1;
		xx.b = b - x.b;
		if (xx.b < 0)
			xx.b += M2;
		return xx;
	}
	hsh operator*(hsh x) {
		hsh xx;
		xx.a = a;
		xx.b = b;
		xx.a = (xx.a * x.a) % M1;
		xx.b = (xx.b * x.b) % M2;
		return xx;
	}
};

bool operator<(const hsh& a, const hsh& b) {
	return a.a != b.a ? a.a < b.a : a.b < b.b;
}

hsh pw[MAXN];
hsh bpw[MAXN];


struct st {
	set<hsh> ss;
	ll m; //power of p added
	hsh d;
	st() {
		m = 0;
		d = hsh(0, 0);
	}
	void add(hsh k) {
		k = k - d;
		k = k * bpw[m];
		ss.insert(k);
	}
	size_t size() {
		return ss.size();
	}
};

st* merge(st *a, st *b) {
	if (a->size() < b->size())
		swap(a, b);
	for (auto x: b->ss) {
		x = (x * pw[b->m] + b->d);
		a->add(x);
	}
	return a;
}


int was[MAXN];
int n;
vector<int> eds[MAXN];
vector<int> eds2[MAXN];
int c[MAXN];
char s[MAXN];
int mx, mxc;


void dfs0(int v) {
	was[v] = 1;
	for (int i = 0; i < (int)eds2[v].size(); ++i) {
		int u = eds2[v][i];
		if (was[u])
			continue;
		eds[v].push_back(u);
		dfs0(u);
	}
}


st* dfs1(int v) {
	st *now = new st;
	now->d = hsh(0, 0);
	now->m = 0;
	now->add(hsh(s[v], s[v]));
	for (int i = 0 ; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		st *nx = dfs1(u);
		++nx->m;
		nx->d = (nx->d * pw[1]) + hsh(s[v], s[v]);
		now = merge(now, nx);
	}
	int cc = c[v] + now->size();
	if (cc > mx)
		mx = cc, mxc = 0;
	if (cc == mx)
		++mxc;
	return now;
}

ll pow2(ll a, ll b, ll MOD) {
	ll ans = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = (a * a) % MOD;
		--b;
		ans = (ans * a) % MOD;
	}
	return ans;
}

void initHsh() {
	pw[0] = hsh(1, 1);
	pw[1] = hsh(P, P);
	bpw[0] = hsh(1, 1);
	bpw[1] = hsh(pow2(P, M1 - 2, M1), pow2(P, M2 - 2, M2));
	for (int i = 2; i < n + 10; ++i)
		pw[i] = pw[i - 1] * pw[1], bpw[i] = bpw[i - 1] * bpw[1];
}


int main() {
	scanf("%d", &n);
	initHsh();
	for (int i = 0; i < n; ++i)
		scanf("%d", &c[i]);
	scanf(" %s", s);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds2[a].push_back(b);
		eds2[b].push_back(a);
	}
	mx = 0;
	mxc = 0;
	dfs0(0);
	dfs1(0);

	cout << mx << "\n" << mxc << "\n";
	
	return 0;
}