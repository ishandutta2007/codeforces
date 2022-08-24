#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

struct point {
	ll x, y;
	point() {
		x = y = 0;
	}
	point(ll x, ll y): x(x), y(y) {}
	point operator+(point a) {
		return point(x + a.x, y + a.y);
	}
	point operator-(point a) {
		return point(x - a.x, y - a.y);
	}
	ll len2() {
		return x * x + y * y;
	}
};

const int MAXN = 120000;

const ll MX1 = 1000000ll * 1000000ll;
const ll MX2 = 1500000ll * 1500000ll;


point v[MAXN];
int p[MAXN];
int up[MAXN];
int sz[MAXN];
int n;

int get(int x) {
	if (x == p[x])
		return up[x];
	return up[x] ^ get(p[x]);
}

point tmp[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x >> v[i].y;
		tmp[i] = v[i];
	}
	for (int i = 0; i < n; ++i) {
		p[i] = i, sz[i] = 1;
	}
	vector<int> vv;
	for (int i = 0; i < n; ++i) {
		vv.push_back(i);
		int fl = 0;
		do {
			fl = 0;
			for (int j = 0; j < vv.size() && !fl; ++j)
				for (int k = j + 1; k < vv.size() && !fl; ++k) {
					if ((v[vv[j]] + v[vv[k]]).len2() <= MX1) {
						fl = 1;
						int a = vv[j];
						int b = vv[k];
						if (sz[a] < sz[b])
							swap(a, b), swap(vv[j], vv[k]);
						p[b] = a;
						up[b] = 0;
						sz[a] += sz[b];
						v[a] = v[a] + v[b];
						vv.erase(vv.begin() + k);
						break;
					}
					if ((v[vv[j]] - v[vv[k]]).len2() <= MX1) {
						fl = 1;
						int a = vv[j];
						int b = vv[k];
						if (sz[a] < sz[b])
							swap(a, b), swap(vv[j], vv[k]);
						p[b] = a;
						up[b] = 1;
						sz[a] += sz[b];
						v[a] = v[a] - v[b];
						vv.erase(vv.begin() + k);
						break;
					}
				}
		} while (fl);
	}
	int ans = 0;
	for (int i = 0; i < (1 << vv.size()); ++i) {
		point cur;
		for (int j = 0; j < vv.size(); ++j) {
			if ((i >> j) & 1)
				cur = cur + v[vv[j]];
			else
				cur = cur - v[vv[j]];
		}
		if (cur.len2() <= MX2) {
			ans = 1;
			for(int j = 0; j < vv.size(); ++j)
				if ((i >> j) & 1)
					up[vv[j]] = 0;
				else
					up[vv[j]] = 1;
			break;
		}
	}
	assert(ans);
	point cur;
	for (int i = 0; i < n; ++i) {
		int x = get(i);
		if (x == 0)
			cout << 1 << " ", cur = cur + tmp[i];
		else
			cout << -1 << " ", cur = cur - tmp[i];
	}
	cout << "\n";
	assert(cur.len2() <= MX2);
	return 0;
}