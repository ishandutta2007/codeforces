#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

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

int a[30][30];
int n, m;
int bl[30][30];
int nd[30][30];
pair<int, int> pl[1000];
int gg[10];
vector<vector<int>> ans;
vector<vector<int>> ans2;

void add(vector<int> x) {
	ans.push_back(x);
	vector<pair<int, int>> uu;
	for (int i = 0; i < x.size(); ++i)
		uu.push_back(pl[x[i]]);
	for (int i = x.size() - 2; i >= 0; --i)
		swap(a[uu[i].first][uu[i].second], a[uu[i + 1].first][uu[i + 1].second]);
	for (auto p: uu)
		pl[a[p.first][p.second]] = p;
}

int nm(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	if (bl[x][y])
		return 0;
	return 1;
}

void mvl(int x, int y) {
	if (nm(x + 1, y) && nm(x + 1, y - 1)) {
		add({a[x][y], a[x][y - 1], a[x + 1][y - 1], a[x + 1][y]});
	}
	else {
		add({a[x][y], a[x][y - 1], a[x - 1][y - 1], a[x - 1][y]});
	}
}

void mvr(int x, int y) {
	if (nm(x + 1, y) && nm(x + 1, y + 1)) {
		add({a[x][y], a[x][y + 1], a[x + 1][y + 1], a[x + 1][y]});
	}
	else {
		add({a[x][y], a[x][y + 1], a[x - 1][y + 1], a[x - 1][y]});
	}
}

void mvd(int x, int y) {
	if (nm(x, y + 1) && nm(x + 1, y + 1)) {
		add({a[x][y], a[x + 1][y], a[x + 1][y + 1], a[x][y + 1]});
	}
	else {
		add({a[x][y], a[x + 1][y], a[x + 1][y - 1], a[x][y - 1]});
	}
}

void mvu(int x, int y) {
	if (nm(x, y + 1) && nm(x - 1, y + 1)) {
		add({a[x][y], a[x - 1][y], a[x - 1][y + 1], a[x][y + 1]});
	}
	else {
		add({a[x][y], a[x - 1][y], a[x - 1][y - 1], a[x][y - 1]});
	}
}


void combo(int a1, int a2, int a3, int a4, int a5, int a6) {
	add({a1, a2, a5, a4});
	add({a1, a4, a5, a2, a6, a3});
	add({a5, a3, a6, a2});
}

ull geths(const vector<int> &vv) {
	ull hs = 0;
	for (int i = 0; i < vv.size(); ++i)
		hs = hs * 10 + vv[i];
	return hs;
}


vector<int> get(vector<int> vv, int a, int b, int c, int d) {
	swap(vv[a], vv[b]);
	swap(vv[b], vv[c]);
	swap(vv[c], vv[d]);
	return vv;
}

queue<vector<int>> qu;
map<ull, pair<ull, int>> mm;

void add2(vector<int> vv, ull hs, int d) {
	ull h = geths(vv);
	if (!mm.count(h)) {
		mm[h] = {hs, d};
		qu.push(vv);
	}
}

vector<int> get2(vector<int> vv, int a, int b, int c, int d) {
	ans2.push_back({gg[vv[a]], gg[vv[b]], gg[vv[c]], gg[vv[d]]});
	swap(vv[a], vv[b]);
	swap(vv[b], vv[c]);
	swap(vv[c], vv[d]);
	return vv;
}


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> a[i][j], --a[i][j], pl[a[i][j]] = {i, j};
	}
	int cc = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			nd[i][j] = cc++;
	}
	for (int i = n - 1; i >= 3; --i) {
		vector<int> vv;
		for (int j = 0; j < m; ++j)
			vv.push_back(j);
		swap(vv[m - 2], vv[m - 1]);
		for (int j: vv) {
			if (a[i][j] == nd[i][j]) {
				bl[i][j] = 1;
				continue;
			}
			while (pl[nd[i][j]].second < j)
				mvr(pl[nd[i][j]].first, pl[nd[i][j]].second);
			while (pl[nd[i][j]].second > j)
				mvl(pl[nd[i][j]].first, pl[nd[i][j]].second);
			while (pl[nd[i][j]].first < i - 1)
				mvd(pl[nd[i][j]].first, pl[nd[i][j]].second);
			if (j == vv.back()) {
				combo(a[i - 1][j - 1], a[i - 1][j], a[i - 1][j + 1], a[i][j - 1], a[i][j], a[i][j + 1]);
			}
			else {
				while (pl[nd[i][j]].first < i)
					mvd(pl[nd[i][j]].first, pl[nd[i][j]].second);
			}
			bl[i][j] = 1;
		}
	}
	for (int j = m - 1; j >= 3; --j) {
		vector<int> vv;
		for (int j = 0; j < 3; ++j)
			vv.push_back(j);
		swap(vv[3 - 2], vv[3 - 1]);
		for (int i: vv) {
			if (a[i][j] == nd[i][j]) {
				bl[i][j] = 1;
				continue;
			}
			while (pl[nd[i][j]].first < i)
				mvd(pl[nd[i][j]].first, pl[nd[i][j]].second);
			while (pl[nd[i][j]].first > i)
				mvu(pl[nd[i][j]].first, pl[nd[i][j]].second);
			while (pl[nd[i][j]].second < j - 1)
				mvr(pl[nd[i][j]].first, pl[nd[i][j]].second);
			if (i == vv.back()) {
				combo(a[i + 1][j - 1], a[i][j - 1], a[i - 1][j - 1], a[i + 1][j], a[i][j], a[i - 1][j]);
			}
			else {
				while (pl[nd[i][j]].second < j)
					mvr(pl[nd[i][j]].first, pl[nd[i][j]].second);
			}
			bl[i][j] = 1;
		}
	}
	vector<int> vv;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			int x = a[i][j] / m;
			int y = a[i][j] % m;
			gg[x * 3 + y] = a[i][j];
			vv.push_back(x * 3 + y);
		}
	vector<int> start = vv;
	vector<int> want;
	for (int i = 0; i < 9; ++i)
		want.push_back(i);
	mm[geths(vv)] = {0, -1};
	qu.push(vv);
	while (true) {
		vector<int> vv = qu.front();
		qu.pop();
		ull hs = geths(vv);
		if (vv == want) {
			while (vv != start) {
				int d = mm[geths(vv)].second;
				if (d == 0)
					vv = get2(vv, 3, 4, 1, 0);
				if (d == 1)
					vv = get2(vv, 4, 5, 2, 1);
				if (d == 2)
					vv = get2(vv, 6, 7, 4, 3);
				if (d == 3)
					vv = get2(vv, 7, 8, 5, 4);
			}
			reverse(ans2.begin(), ans2.end());
			for (auto x: ans2)
				ans.push_back(x);
			cout << ans.size() << "\n";
			for (auto x: ans) {
				cout << x.size() << " ";
				for (int i: x)
					cout << i + 1 << " ";
				cout << "\n";
			}
			return 0;
		}

		vector<int> vv2 = get(vv, 0, 1, 4, 3);
		add2(vv2, hs, 0);
		vv2 = get(vv, 1, 2, 5, 4);
		add2(vv2, hs, 1);
		vv2 = get(vv, 3, 4, 7, 6);
		add2(vv2, hs, 2);
		vv2 = get(vv, 4, 5, 8, 7);
		add2(vv2, hs, 3);
	}
	return 0;
}