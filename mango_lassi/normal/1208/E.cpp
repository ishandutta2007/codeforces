#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e6;
const int W = 1e6;
vector<ll> pref[N]; // pref[i][j]: Maximum of [j-a, j] for j < m
vector<ll> suff[N]; // suff[i][j]: Maximum of [m-1-j, m-1-j+a] for j < m
ll dp[W+1]; // Sum of maximum elements of all arrays with length at most W

vector<ll> helper(int a, const vector<ll>& vals) {
	int n = vals.size();
	vector<ll> res(n);

	int s = 0;
	vector<pair<ll, int>> sta = {{0ll, -1}};
	for (int j = 0; j < n; ++j) {
		while(sta.size() > s && sta.back().first <= vals[j]) {
			sta.pop_back();
		}
		sta.emplace_back(vals[j], j);
		while(sta[s].second < j-a) ++s;
		res[j] = sta[s].first;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, w;
	cin >> n >> w;
	
	vector<pair<int, int>> segs(n);
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		segs[i] = {m, i};

		vector<ll> vals(m);
		for (int i = 0; i < m; ++i) cin >> vals[i];
		
		int a = w-m;
		pref[i] = helper(a, vals);
		reverse(vals.begin(), vals.end());
		suff[i] = helper(a, vals);

		ll mx = 0;
		for (auto v : vals) mx = max(mx, v);
		dp[m] += mx;
	}

	for (int v = 1; v <= w; ++v) {
		dp[v] += dp[v-1];
	}
	sort(segs.begin(), segs.end());

	for (int x = 0; x < w; ++x) {
		int dl = x;
		int dr = w-1-x;
		int dm = min(dl, dr);
		
		int low = 0;
		int high = n;
		while(low != high) {
			int mid = (low + high) >> 1;
			if (segs[mid].first <= dm) low = mid + 1;
			else high = mid;
		}

		ll res = dp[dm];
		// position t in the seg can take locations [t, t + w-m]
		// for which t do we have x \in [t, t + w-m]?
		// x - (w-m) <= t <= x
		// So we are always only interested in maximums of length a

		// vector<ll> pref[N]; // pref[i][j]: Maximum of [j-a, j] for j < m
		// vector<ll> suff[N]; // suff[i][j]: Maximum of [m-1-j, m-1-j+a] for j < m
		for (int j = low; j < n; ++j) {
			int m = segs[j].first;
			int i = segs[j].second;
			int a = w-m;
			if (dl < m) {
				res += pref[i][dl];
			} else if (dr < m) {
				res += suff[i][dr];
			}
		}
		cout << res << ' ';
	}
	cout << '\n';
}