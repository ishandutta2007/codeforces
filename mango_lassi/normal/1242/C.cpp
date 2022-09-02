#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int K = 15;
const int N = 5000;
const int M = 1<<K;

pair<int, int> dp[M];
int dp2[M];

vector<ll> vals[K];
ll sums[K];
vector<pair<ll, pair<int, int>>> lst;

pair<int, int> bins(ll v) {
	int low = 0;
	int high = (int)lst.size() - 1;
	while(low != high) {
		int mid = (low + high) >> 1;
		if (lst[mid].first < v) low = mid + 1;
		else high = mid;
	}
	if (lst[low].first == v) return lst[low].second;
	else return {-1, -1};
}

vector<pair<ll, pair<int, int>>> getCyc(int i, int s, ll t) {
	ll ini = t - sums[i] + vals[i][s];
	ll cur = ini;
	int pos = i;
	vector<pair<ll, pair<int, int>>> res;
	int m = 0;
	do {
		m |= (1<<pos);
		auto nxt = bins(cur);
		res.push_back({cur, {nxt.first, pos}});

		pos = nxt.first;
		if (pos != -1) cur += t - sums[pos];
	} while (pos != -1 && (!(m & (1<<pos))));

	if (pos == i && cur == ini) return res;
	else return {};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;

	ll sum = 0;
	for (int i = 0; i < k; ++i) {
		int n;
		cin >> n;
		vals[i].resize(n);
		for (int j = 0; j < n; ++j) {
			cin >> vals[i][j];
			sums[i] += vals[i][j];
			lst.push_back({vals[i][j], {i, j}});
		}
		sum += sums[i];
	}

	ll t = sum / k;
	sort(lst.begin(), lst.end());

	for (int j = 0; j <= (1<<k); ++j) {
		dp[j] = {-1, -1};
		dp2[j] = -1;
	}
	for (int i = 0; i < k; ++i) {
		for (int s = 0; s < vals[i].size(); ++s) {
			auto off = getCyc(i, s, t);
			int m = 0;
			for (auto pr : off) m |= 1 << pr.second.first;
			dp[m] = {i, s};
		}
	}
	dp2[0] = 0;
	for (int j = 1; j < (1<<k); ++j) {
		for (int s=j; s; s=(s-1)&j) {
			if (dp2[j^s] != -1 && dp[s].first != -1) dp2[j] = s;
		}
	}
	
	int act = (1<<k) - 1;
	if (dp2[act] == -1) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		vector<pair<int, int>> res(k);
		while(act != 0) {
			int sub = dp2[act];
			auto off = getCyc(dp[sub].first, dp[sub].second, t);
			for (auto pr : off) {
				res[pr.second.first] = {pr.first, pr.second.second + 1};
			}
			act ^= sub;
		}
		for (auto pr : res) cout << pr.first << ' ' << pr.second << '\n';
	}
}