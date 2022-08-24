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


const ll MOD = 1e9 + 7;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
const int MAXN = 10000;

int R;
ll p[4];
vector<pair<int, int> > vv;

map<pair<int, int>, int> mm;
vector<pair<int, int>> a[MAXN];
ll b[MAXN];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

vector<pair<int, int> > tmp;
int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> R;
	ll sum = 0;
	for (int i = 0; i < 4; ++i)
		cin >> p[i], sum += p[i];
	sum = pw(sum, MOD - 2);
	for (int i = 0; i < 4; ++i)
		p[i] = (p[i] * sum) % MOD;
	for (int x = -R; x <= R; ++x)
		for (int y = -R; y <= R; ++y)
			if (x * x + y * y <= R * R) {
				vv.emplace_back(x, y);
			}
	sort(vv.begin(), vv.end(), [] (pair<int, int> x, pair<int, int> y) -> bool {
			return abs(x.first) + abs(x.second) > abs(y.first) + abs(y.second);
			});
	for (int i = 0; i < vv.size(); ++i)
		mm[vv[i]] = i;
	for (int i = 0; i < vv.size(); ++i) {
		int x, y;
		tie(x, y) = vv[i];
		a[i].emplace_back(i, 1);
		b[i] = 1;
		for (int j = 0; j < 4; ++j) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (mm.count({nx, ny})) {
				a[i].emplace_back(mm[{nx, ny}], (MOD - p[j]) % MOD);
			}
		}
		sort(a[i].begin(), a[i].end());
	}
	int now = 0;
	for (int i = 0; i < vv.size(); ++i) {
		int fl = 0;
		for (int j = now; j < vv.size(); ++j) {
			if (!a[j].empty() && a[j][0].first == i) {
				fl = 1;
				swap(a[now], a[j]);
				swap(b[now], b[j]);
				break;
			}
		}
		assert(fl);
		ll go = pw(a[now][0].second, MOD - 2);
		for (int j = 0; j < a[now].size(); ++j)
			a[now][j].second = (a[now][j].second * go) % MOD;
		b[now] = b[now] * go % MOD;
		for (int j = now + 1; j < vv.size(); ++j) {
			if (a[j].empty() || a[j][0].first != i)
				continue;
			tmp.clear();
			ll mul = (MOD - a[j][0].second) % MOD;
			int cx = 0;
			int cy = 0;
			auto &x = a[now];
			auto &y = a[j];
			while (cx < x.size() || cy < y.size()) {
				if (cx < x.size() && cy < y.size()) {
					if (x[cx].first == y[cy].first) {
						int nw = (y[cy].second + mul * x[cx].second) % MOD;
						if (nw != 0)
							tmp.emplace_back(x[cx].first, nw);
						++cx;
						++cy;
					}
					else if (x[cx].first < y[cy].first) {
						tmp.emplace_back(x[cx].first, x[cx].second * mul % MOD);
						++cx;
					}
					else {
						tmp.push_back(y[cy++]);
					}
				}
				else if (cx < x.size()) {
					tmp.emplace_back(x[cx].first, x[cx].second * mul % MOD);
					++cx;
				}
				else {
					tmp.push_back(y[cy++]);
				}
			}
			a[j] = tmp;
			b[j] = (b[j] + b[now] * mul) % MOD;
		}
		++now;
	}
	cout << b[vv.size() - 1] << "\n";
	return 0;
}