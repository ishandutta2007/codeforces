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
ll M;
ll BK;
ll ans = 0;

ll pw(ll a, ll b) {
	ll ans = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = (a * a) % M;
		--b;
		ans = (ans * a) % M;
	}
	return ans;
}

struct st {
	map<ll, int> s1;
	map<ll, int> s2;
	ll d1, m1;
	ll d2, m2;
	ll m1b, m2b;
	st() {
		d1 = d2 = 0;
		m1 = m2 = 1;
		m1b = m2b = 1;
	}
	void add(ll x) {
		d1 = (d1 + (M - x) * m1b) % M;
		m1 = (m1 * BK) % M;
		m1b = (m1b * 10) % M;
		m2 = (m2 * 10) % M;
		m2b = (m2b * BK) % M;
		d2 = (d2 + x * m2b) % M;
	}
};


st *merge(st *a, st *b) {
	if (a->s1.size() < b->s1.size())
		swap(a, b);
	for (pair<ll, int> x: b->s1) {
		ll go = (x.first + b->d1) * (b->m1) % M;
		go = ((go * a->m2b) + (M - a->d2)) % M;
		ans += (ll)x.second * (a->s2[go]);
	}
	for (pair<ll, int> x: b->s2) {
		ll go = (x.first + b->d2) * (b->m2) % M;
		go = ((go * a->m1b) + (M - a->d1)) % M;
		ans += (ll)x.second * (a->s1[go]);
	}
	for (pair<ll, int> x: b->s1) {
		ll go = (x.first + b->d1) * (b->m1) % M;
		go = ((go * a->m1b) + (M - a->d1)) % M;
		a->s1[go] += x.second;
	}
	for (pair<ll, int> x: b->s2) {
		ll go = (x.first + b->d2) * (b->m2) % M;
		go = ((go * a->m2b) + (M - a->d2)) % M;
		a->s2[go] += x.second;
	}
	return a;
}

const int MAXN = 120000;
int was[MAXN];
int n;
vector<pair<int, int> > eds[MAXN];

st *dfs1(int v) {
	was[v] = 1;
	st *now = new st();
	now->s1[0] = 1;
	now->s2[0] = 1;
	for (pair<int, int> e: eds[v]) {
		int u = e.first;
		if (was[u])
			continue;
		st *tmp = dfs1(u);
		tmp->add(e.second);
		now = merge(now, tmp);
	}
	return now;
}


int main() {
	scanf("%d%lld", &n, &M);
	if (M == 1) {
		ans = (ll)n * (n - 1);
		cout << ans << "\n";
		return 0;
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		eds[a].push_back(make_pair(b, c));
		eds[b].push_back(make_pair(a, c));
	}
	ll phi = 1;
	ll tmp = M;
	for (ll i = 2; i * i <= tmp; ++i) {
		if (tmp % i != 0)
			continue;
		tmp /= i;
		ll now = i - 1;
		while (tmp % i == 0)
			tmp /= i, now *= i;
		phi *= now;
	}
	if (tmp != 1)
		phi *= (tmp - 1);
	BK = pw(10, phi - 1);

	dfs1(0);

	cout << ans << "\n";
	return 0;
}