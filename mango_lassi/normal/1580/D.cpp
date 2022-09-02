#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
const int N = 4000;
vector<ll> vals[N + 1];
int pre[N];
int nxt[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	vector<pair<ll, int>> ord(n);
	for (int i = 0; i < n; ++i) {
		ord[i] = {as[i], i};
		pre[i] = i;
	}
	sort(ord.rbegin(), ord.rend());
	
	for (auto pr : ord) {
		int i = pr.second;

		vector<ll> le, ri;
	
		int lf = i, rf = i;
		if (i > 0 && as[i-1] > as[i]) {
			swap(le, vals[pre[i-1]]);
			lf = pre[i-1];
		} else {
			le.push_back(0);
		}

		if (i+1 < n && as[i+1] > as[i]) {
			swap(ri, vals[i+1]);
			rf = nxt[i+1];
		} else {
			ri.push_back(0);
		}

		pre[rf] = lf;
		nxt[lf] = rf;

		vals[lf].resize((int)le.size() + (int)ri.size(), -INF);
		for (int x = 0; x < le.size(); ++x) {
			for (int y = 0; y < ri.size(); ++y) {
				ll off0 = le[x] + ri[y] - 2*x*y*as[i];
				ll off1 = le[x] + ri[y] + as[i] * (m - 2*x*y - 2*x - 2*y - 1);
				
				vals[lf][x + y] = max(vals[lf][x + y], off0);
				vals[lf][x + y + 1] = max(vals[lf][x + y + 1], off1);
			}
		}

		// cerr << "Update interval " << lf << ' ' << rf << ": ";
		// for (auto v : vals[lf]) cerr << v << ' '; cerr << '\n';
	}
	cout << vals[0][m] << '\n';
}