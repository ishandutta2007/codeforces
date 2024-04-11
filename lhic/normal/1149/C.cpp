#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

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

const int N = 2 * 100100;


int n, q;
string s;

const int INF = 1e9;

struct st {
	int bst[2][2];
	int gl[2];
	int gr[2];
	st(){
		for (int i = 0; i < 2; ++i) {
			gl[i] = gr[i] = -INF;
			for (int j = 0; j < 2; ++j)
				bst[i][j] = -INF;
		}
	}
	st(char c) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				bst[i][j] = 1;
			}
		if (c == '(') {
			gr[0] = gr[1] = 1;
			gl[0] = 0;
			gl[1] = -1;
		}
		else {
			gl[0] = gl[1] = 1;
			gr[0] = 0;
			gr[1] = -1;
		}
	}
};

st merge(st a, st b) {
	st ans;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			ans.bst[i][0] = max(ans.bst[i][0], a.bst[i][j]);
			if (j) {
				for (int k = 0; k < 2; ++k) {
					ans.bst[i][k] = max(ans.bst[i][k], a.bst[i][j] + b.gr[k]);
				}
			}
		}
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			ans.bst[0][i] = max(ans.bst[0][i], b.bst[j][i]);
			if (j) {
				for (int k = 0; k < 2; ++k) {
					ans.bst[k][i] = max(ans.bst[k][i], b.bst[j][i] + a.gl[k]);
				}
			}
		}
	}
	ans.gl[0] = max(b.gl[0], b.gl[1] + a.gl[0]);
	ans.gl[1] = b.gl[1] + a.gl[1];
	ans.gr[0] = max(a.gr[0], a.gr[1] + b.gr[0]);
	ans.gr[1] = a.gr[1] + b.gr[1];
	ans.gl[0] = max(ans.gl[0], ans.gl[1]);
	ans.gr[0] = max(ans.gr[0], ans.gr[1]);
	ans.bst[0][1] = max(ans.bst[0][1], ans.bst[1][1]);
	ans.bst[1][0] = max(ans.bst[1][0], ans.bst[1][1]);
	ans.bst[0][0] = max(ans.bst[0][0], ans.bst[0][1]);
	ans.bst[0][0] = max(ans.bst[0][0], ans.bst[1][0]);
	return ans;
}

void out(st x) {
	cout << x.bst[0][0] << "\n";
}



st rmq[N * 4];


void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v] = st(s[tl]);
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void upd(int v, int tl, int tr, int x) {
	if (tl + 1 == tr) {
		rmq[v] = st(s[tl]);
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		upd(v * 2 + 1, tl, m, x);
	else
		upd(v * 2 + 2, m, tr, x);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}


int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	cin >> s;
	build(0, 0, s.size());
	out(rmq[0]);
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		swap(s[a], s[b]);
		upd(0, 0, s.size(), a);
		upd(0, 0, s.size(), b);
		out(rmq[0]);
	}
	return 0;
}