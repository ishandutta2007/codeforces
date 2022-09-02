#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;


template<class T>
int bins(const vector<T>& vec, T val) {
	int low = -1;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		if (vec[mid] <= val) low = mid;
		else high = mid - 1;
	}
	return low;
}

ll count(int a, int b, const vector<ll>& vals) {
	if (vals[a] > vals[b]) return INF;

	vector<ll> cur(b-a+1, INF);
	for (int i = a+1; i < b; ++i) {
		if (vals[i] < vals[a]) continue;
		int j = bins(cur, vals[i]);
		cur[j+1] = vals[i];
	}
	while(! cur.empty() && cur.back() > vals[b]) cur.pop_back();
	return b-a-1 - (int)cur.size();
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<ll> vals(n+2);
	vals[0] = -INF;
	vals[n+1] = INF;
	for (int i = 1; i <= n; ++i) cin >> vals[i];
	for (int i = 0; i <= n+1; ++i) vals[i] -= i;

	vector<int> bans(k+2);
	bans[0] = 0;
	bans[k+1] = n+1;
	for (int i = 1; i <= k; ++i) cin >> bans[i];
	sort(bans.begin(), bans.end());

	ll res = 0;
	for (int i = 0; i <= k; ++i) {
		res += count(bans[i], bans[i+1], vals);
		if (res > n) break;
	}
	if (res > n) cout << -1 << '\n';
	else cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}