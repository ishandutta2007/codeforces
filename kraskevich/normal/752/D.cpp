#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string reversed(string s) {
	reverse(s.begin(), s.end());
	return s;
}

map<string, vector<ll>> costs;
ll res = 0;

ll solve1(vector<ll> v) {
	ll cur = 0;
	ll best = 0;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i + 1 < v.size(); i += 2) {
		cur += v[i] + v[i + 1];
		best = max(best, cur);
	}
	return best;
}

ll solve3(vector<ll> v) {
	if (v.size() == 0)
		return 0;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	ll cur = v[0];
	ll best = v[0];
	for (int i = 1; i + 1 < v.size(); i += 2) {
		cur += v[i] + v[i + 1];
		best = max(best, cur);
	}
	return best;
}

ll solve2(vector<ll> a, vector<ll> b) {
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	ll cur = 0;
	ll best = 0;
	for (int i = 0; i < min(a.size(), b.size()); i++) {
		cur += a[i] + b[i];
		best = max(best, cur);
	}
	return best;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	int k, n;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;
		int a;
		cin >> a;
		costs[s].push_back(a);
	}
	for (const auto& kv: costs) {
		string s = kv.first;
		string r = reversed(s);
		if (s == r) {
			//cerr << s << endl;
			res += solve1(kv.second);
			//cerr << solve1(kv.second) << endl;
		}
		else if (s < r && costs.find(r) != costs.end()) {
			//cerr << solve2(kv.second, costs[r]) << endl;
			res += solve2(kv.second, costs[r]);
		}
	}
	//cerr << res << endl;
	ll init_res = res;
	for (const auto& kv : costs) {
		string s = kv.first;
		string r = reversed(s);
		ll cur = init_res;
		if (s == r) {
		//	cerr << solve1(kv.second) << endl;
		//	cerr << solve3(kv.second) << endl;
			cur -= solve1(kv.second);
			cur += solve3(kv.second);
		////	cerr << cur << endl << " " << endl;
			res = max(res, cur);
		}
	}
	cout << res << endl;
}