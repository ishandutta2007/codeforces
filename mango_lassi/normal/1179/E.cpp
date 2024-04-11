#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
const ll H = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}

map<pair<int, ll>, ll> memo;

// Get f_{i}(x)
ll ask(int i, ll x) {
	pair<int, ll> pr = {i, x};
	if (memo.find(pr) != memo.end()) return memo[pr];
	cout << "? " << i+1 << ' ' << x << endl;
	ll r;
	cin >> r;
	memo[pr] = r;
	return r;
}

// Get min x where ask(i, x) >= t
ll getInd(int i, ll t) {
	ll low = 0;
	ll high = H;
	while(low != high) {
		ll mid = (low + high) >> 1;
		if (ask(i, mid) >= t) high = mid;
		else low = mid + 1;
	}
	return low;
}

// Sort intervals in act to positions in range [a, b]
vector<int> recSort(ll t, vector<int> act, int orig_k = 0) {
	// Do quicksort
	int n = act.size();
	if (n == 1) return act;

	int le_tc = (n+1)/2;
	int ri_tc = n/2;
	int k = orig_k + le_tc;
	ll v = k*t;

	vector<int> le, ri;
	while(! act.empty()) {
		// Do one pivot step of finding the j'th
		int m = act.size();
		int i = rand(0, m - 1);
		ll x = getInd(act[i], v);

		vector<ll> offs(m, 0); // -1 less, 0 equal, 1 more
		offs[i] = 0;
		int lesses = 0;
		int mores = 0;
		for (int j = 0; j < m; ++j) {
			if (j == i) continue;

			ll cou = ask(act[j], x-1);
			if (cou >= v) offs[j] = -1;
			else if (cou < v-1) offs[j] = 1;
			else {
				ll cou2 = ask(act[j], x);
				if (cou2 == v-1) offs[j] = 1;
			}
			if (offs[j] < 0) ++lesses;
			if (offs[j] > 0) ++mores;
		}

		if (le.size() + lesses <= le_tc && ri.size() + mores <= ri_tc) {
			int add_le = le_tc - lesses - le.size();
			for (int j = 0; j < m; ++j) {
				if (offs[j] == -1) le.push_back(act[j]);
				else if (offs[j] == 1) ri.push_back(act[j]);
				else {
					if (add_le > 0) {
						le.push_back(act[j]);
						--add_le;
					} else {
						ri.push_back(act[j]);
					}
				}
			}
			act.clear();
		} else if (le.size() + lesses <= le_tc) {
			vector<int> nxt_act;
			for (int j = 0; j < m; ++j) {
				if (offs[j] <= 0) le.push_back(act[j]);
				else nxt_act.push_back(act[j]);
			}
			act = nxt_act;
		} else {
			vector<int> nxt_act;
			for (int j = 0; j < m; ++j) {
				if (offs[j] >= 0) ri.push_back(act[j]);
				else nxt_act.push_back(act[j]);
			}
			act = nxt_act;
		}
	}

	vector<int> le_sorted = recSort(t, le, orig_k);
	vector<int> ri_sorted = recSort(t, ri, orig_k + le_tc);
	vector<int> res;
	for (auto i : le_sorted) res.push_back(i);
	for (auto i : ri_sorted) res.push_back(i);
	return res;
}

int main() {
	int n;
	ll v;
	cin >> n >> v;
	ll t = v/n;

	vector<int> inds(n);
	for (int i = 0; i < n; ++i) inds[i] = i;
	vector<int> ord = recSort(t, inds);

	ll pre = 0;
	vector<pair<ll, ll>> ints(n);
	for (int j = 0; j < n; ++j) {
		int i = ord[j];
		ll x = getInd(i, t*(j+1));
		ints[i] = {pre, x};
		pre = x;
	}

	cout << "!" << endl;
	for (int i = 0; i < n; ++i) {
		cout << ints[i].first << ' ' << ints[i].second << endl;
	}
}