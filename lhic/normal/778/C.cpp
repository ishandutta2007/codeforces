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

const ll M1 = 1e9 + 7;
const ll M2 = 1e9 + 9;

struct hsh {
	ll a, b;
	hsh(ll A = 0) {
		a = A % M1;
		b = A % M2;
	}
	hsh(ll A, ll B) {
		a = A % M1;
		b = B % M2;
	}
	hsh operator*(hsh x) {
		return hsh(a * x.a, b * x.b);
	}
	hsh operator+(hsh x) {
		return hsh(a + x.a, b + x.b);
	}
	hsh operator-(hsh x) {
		return hsh(a - x.a + M1, b - x.b + M2);
	}
};
bool operator<(hsh y, hsh x) {
	return make_pair(y.a, y.b) < make_pair(x.a, x.b);
}

ll pw(ll a, ll b, ll MOD) {
	ll ans = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	}
	return ans;
}

const ll P = 23917;
const hsh BP = hsh(pw(P, M1 - 2, M1), pw(P, M2 - 2, M2));
const int MAXN = 310000;
int go[MAXN][30];

int sz[MAXN];
void dfs1(int v) {
	sz[v] = 1;
	for (int i = 0; i < 26; ++i)
		if (go[v][i])
			dfs1(go[v][i]), sz[v] += sz[go[v][i]];
}

struct st {
	set<hsh> *ss;
	hsh mlt;
	hsh bmlt;
	hsh add;
	st() {
		ss = new set<hsh>;
		mlt = 1;
		bmlt = 1;
		add = 0;
	}
	void sh(int x) {
		mlt = mlt * P;
		bmlt = bmlt * BP;
		add = add * P;
		add = add + 'a' + x;
	}
};

int prof[MAXN];

st dfs2(int v, int h) {
	int mx = -1;
	for (int i = 0; i < 26; ++i) {
		if (go[v][i] == 0)
			continue;
		if (mx == -1 || sz[go[v][i]] > sz[go[v][mx]])
			mx = i;
	}
	if (mx == -1) {
		st now;
		now.ss->insert(0);
		return now;
	}
	st now = dfs2(go[v][mx], h + 1);
	set<hsh> ss1;
	set<hsh> ss2;
	ss2.insert(0);
	for (int i = 0; i < 26; ++i) {
		if (go[v][i] == 0 || i == mx)
			continue;
		st tmp = dfs2(go[v][i], h + 1);
		for (hsh x: *(tmp.ss)) {
			ss1.insert(x * tmp.mlt + tmp.add);
		}
		tmp.sh(i);
		for (hsh x: *(tmp.ss)) {
			ss2.insert(x * tmp.mlt + tmp.add);
		}
	}
	int prs = sz[v];
	int nws = now.ss->size();
	for (hsh x: ss1) {
		x = (x - now.add) * now.bmlt;
		if (!now.ss->count(x))
			++nws;
	}
	prof[h + 1] += prs - nws;
	now.sh(mx);
	for (hsh x: ss2) {
		x = (x - now.add) * now.bmlt;
		now.ss->insert(x);
	}
	return now;
}

int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		char c;
		scanf("%d%d %c", &a, &b, &c);
		--a, --b;
		c -= 'a';
		go[a][(int)c] = b;
	}
	dfs1(0);
	dfs2(0, 0);
	int bst = 0;
	for (int i = 1; i < MAXN; ++i) {
		if (prof[i] > prof[bst])
			bst = i;
	}
	cout << n - prof[bst] << "\n" << bst << "\n";
	return 0;
}