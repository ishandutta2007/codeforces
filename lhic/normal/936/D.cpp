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
typedef long long llong;
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

vector<ll> vv;
ll t;

int get(int x) {
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin();
}

struct tim {
	int ds;
	int lf;
	tim() {
		ds = lf = 0;
	}
	tim(int ds, int lf): ds(ds), lf(lf){}
};

bool operator<(tim a, tim b) {
	return make_pair(a.ds, a.lf) < make_pair(b.ds, b.lf);
}

tim sh(tim x) {
	if (x.ds)
		return tim(1, 0);
	else
		return tim(0, x.lf);
}

tim ad(tim x, ll a) {
	x.lf += a;
	x.ds += x.lf / t;
	x.lf %= t;
	return x;
}
const int MAXN = 4000000;

char bd[MAXN][2];

tim ans[MAXN][2];

vector<int> bda[2];
char fl[MAXN][2];
char go[MAXN][2];
char go2[MAXN][2];

ll n;
int m1, m2;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m1 >> m2 >> t;
	vv.push_back(0);
	vv.push_back(n + 1);
	for (int i = 0; i < m1; ++i) {
		int x;
		cin >> x;
		bda[0].push_back(x);
		vv.push_back(x - 1);
		vv.push_back(x);
		vv.push_back(x + 1);
	}
	for (int i = 0; i < m2; ++i) {
		int x;
		cin >> x;
		bda[1].push_back(x);
		vv.push_back(x - 1);
		vv.push_back(x);
		vv.push_back(x + 1);
	}
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	for (int i: bda[0])
		bd[get(i)][0] = 1;
	for (int i: bda[1])
		bd[get(i)][1] = 1;
	for (int i = 0; i < 2; ++i)
		ans[0][i] = tim();
	fl[0][0] = fl[0][1] = 1;
	go[0][1] = 1;
	for (int i = 0; i < vv.size() - 1; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (fl[i][j] && !bd[i][1 - j]) {
				if (!fl[i][1 - j] || ans[i][1 - j] < sh(ans[i][j])) {
					ans[i][1 - j] = sh(ans[i][j]);
					fl[i][1 - j] = 1;
					go[i][1 - j] = 1;
				}
			}
		}
		for (int j = 0; j < 2; ++j) {
			if (!fl[i][j])
				continue;
			if (bd[i + 1][j]) {
				if (ans[i][j].ds) {
					fl[i + 1][j] = 1;
					ans[i + 1][j] = ad(ans[i][j], 1);
					--ans[i + 1][j].ds;
				}
			}
			else {
				fl[i + 1][j] = 1;
				ans[i + 1][j] = ad(ans[i][j], vv[i + 1] - vv[i]);
			}
		}
	}
	int st = -1;
	for (int j = 0; j < 2; ++j)
		if (fl[vv.size() - 1][j]) {
			st = j;
			break;
		}
	if (st == -1) {
		cout << "No\n";
		return 0;
	}
	int cur = st;
	go2[vv.size() - 1][st] = -1;
	vector<int> ch;
	for (int i = vv.size() - 1; i >= 0; --i) {
		if (go[i][cur] != 0) {
			ch.push_back(vv[i]);
			cur ^= 1;
			go2[i][cur] = 1;
		}
	}
	sort(ch.begin(), ch.end());
	ll lst = t;
	cur = 0;
	vector<pair<int, int>> shot;
	for (int i = 0; i < vv.size() - 1; ++i) {
		if (go2[i][cur] == 1) {
			cur ^= 1;
			lst = max(lst, vv[i]);
		}
		if (bd[i + 1][cur]) {
			shot.push_back(make_pair(lst, cur + 1));
			lst += t;
		}
	}
	sort(shot.begin(), shot.end());
	cout << "Yes\n";
	cout << ch.size() << "\n";
	for (int i: ch)
		cout << i << " ";
	cout << "\n";
	cout << shot.size() << "\n";
	for (auto i: shot)
		cout << i.first << " " << i.second << "\n";
	cout << "\n";
	return 0;
}