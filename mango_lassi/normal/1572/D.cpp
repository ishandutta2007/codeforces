#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)1e9 + 7;

pair<int, int> getBest(int i, int h, const vector<int>& as, const vector<int>& match) {
	pair<int, int> res = {-INF, -1};
	for (int j = 0; j < h; ++j) {
		int t = i ^ (1 << j);
		if (match[t] != -1) continue;

		pair<int, int> off = {as[t] + as[i], t};
		res = max(res, off);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, k;
	cin >> h >> k;
	int n = 1 << h;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	vector<int> match(n, -1), pre(n, -1), val(n, -INF);

	vector<pair<int, int>> bests(n);
	set<pair<int, int>> best_ord;
	for (int i = 0; i < n; ++i) {
		if (__builtin_popcount(i) & 1) {
			bests[i] = getBest(i, h, as, match);
			best_ord.emplace(bests[i].first, i);
		}
	}

	int res = 0;
	vector<int> matches, seen;
	vector<pair<int, int>> ord;
	for (int it = 0; it < k; ++it) {
		pair<int, int> found = {-INF, -1};
		if (! best_ord.empty()) {
			auto it = best_ord.end();
			--it;
			found = max(found, *it);

			int i = (*it).second;
			seen.push_back(i);
			val[i] = bests[i].first - as[i];
		}

		for (int i : matches) {
			if (bests[i].first > -INF) {
				val[i] = as[bests[i].second];
				seen.push_back(i);
				ord.emplace_back(val[i], i);
			}
		}
		sort(ord.begin(), ord.end());

		
		while(! ord.empty()) {
			int v = ord.back().first;
			int i = ord.back().second;
			ord.pop_back();
			
			if (val[i] != v) continue;


			for (int j = 0; j < h; ++j) {
				int t = match[i] ^ (1 << j);
				if (val[t] >= v) continue;
				if (val[t] == -INF) seen.push_back(t);

				val[t] = v;
				pre[t] = i;

				if (match[t] == -1) {
					pair<int, int> off = {as[t] + val[t], t};
					found = max(found, off);
				} else {
					ord.emplace_back(val[t], t);
				}
			}
		}

		if (found.first <= -INF) {
			break;
		}

		res += found.first;
		
		int i = found.second;
		matches.push_back(i);
		best_ord.erase(make_pair(bests[i].first, i));

		while(pre[i] != -1) {
			match[i] = match[pre[i]];
			match[match[i]] = i;
			i = pre[i];
		}
		match[i] = bests[i].second;
		match[match[i]] = i;

		for (int j = 0; j < h; ++j) {
			int t = match[i] ^ (1 << j);
			if (bests[t].second == match[i]) {
				if (match[t] == -1) best_ord.erase(make_pair(bests[t].first, t));
				bests[t] = getBest(t, h, as, match);
				if (match[t] == -1) best_ord.emplace(bests[t].first, t);
			}
		}
		
		for (int i : seen) {
			val[i] = -INF;
			pre[i] = -1;
		}
		seen.clear();
	}
	cout << res << '\n';
}