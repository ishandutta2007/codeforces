#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	vector<pair<int, int>> as(n), bs(n), diffs(2*n);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		diffs[i] = {a-1, 1};
		as[i] = {a-1, i};
	}
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		diffs[i+n] = {b-1, -1};
		bs[i] = {b-1, i};
	}
	sort(diffs.begin(), diffs.end());
	sort(as.begin(), as.end());
	sort(bs.begin(), bs.end());

	ll cur = 0;
	ll cur_add = 0;

	ll px = diffs.back().first - m;
	int pd = 0;
	vector<pair<int, ll>> evs(2*n);
	for (int i = 0; i < 2*n; ++i) {
		ll cx = diffs[i].first;
		ll dist = cx - px;

		cur += abs(pd - n) * dist;
		cur_add -= dist;
		evs[i] = {-pd, 2*dist};

		px = cx;
		pd += diffs[i].second;
	}

	pd = -n;
	sort(evs.begin(), evs.end());
	for (int j = 0; cur_add < 0; ++j) {
		int td = evs[j].first;
		cur += (td - pd) * cur_add;
		cur_add += evs[j].second;
		pd = td;
	}

	cout << cur << '\n';
	vector<int> res(n);
	if (pd < 0) {
		int j = 0;
		for (int i = n+pd; i < n; ++i, ++j) res[as[j].second] = bs[i].second;
		for (int i = 0; i < n+pd; ++i, ++j) res[as[j].second] = bs[i].second;
	} else {
		int j = 0;
		for (int i = pd; i < n; ++i, ++j) res[as[j].second] = bs[i].second;
		for (int i = 0; i < pd; ++i, ++j) res[as[j].second] = bs[i].second;
	}
	for (auto t : res) cout << t+1 << ' '; cout << '\n';
}