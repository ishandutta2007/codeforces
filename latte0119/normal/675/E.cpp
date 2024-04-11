#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<bitset>
#include<numeric>
using namespace std;

typedef long long ll;

template<int N,typename T,T INF>
struct segment_tree_rmq {
	vector<pair<T, int>>mini, maxi;
	segment_tree_rmq() :mini(1 << (N + 1)), maxi(1 << (N + 1)) {
		for (int i = 0; i < 1 << N; i++) {
			mini[i + (1 << N) - 1] = { INF,i };
			maxi[i + (1 << N) - 1] = { -INF,i };
		}
		for (int i = (1 << N) - 2; i >= 0; i--) {
			mini[i] = min(mini[i * 2 + 1], mini[i * 2 + 2]);
			maxi[i] = max(maxi[i * 2 + 1], maxi[i * 2 + 2]);
		}
	}
	void update(int k, T x) {
		k += (1 << N) - 1;
		mini[k].first = maxi[k].first = x;
		while (k) {
			k = (k - 1) / 2;
			mini[k] = min(mini[k * 2 + 1], mini[k * 2 + 2]);
			maxi[k] = max(maxi[k * 2 + 1], maxi[k * 2 + 2]);
		}
	}

	pair<T, int>get_min(int a, int b, int k = 0, int l = 0, int r = 1 << N) {
		if (r <= a || b <= l)return{ INF,-1 };
		if (a <= l&&r <= b)return mini[k];
		return min(get_min(a, b, k * 2 + 1, l, (l + r) / 2), get_min(a, b, k * 2 + 2, (l + r) / 2, r));
	}

	pair<T, int>get_max(int a, int b, int k = 0, int l = 0, int r = 1 << N) {
		if (r <= a || b <= l)return{ -INF,-1 };
		if (a <= l&&r <= b)return maxi[k];
		return max(get_max(a, b, k * 2 + 1, l, (l + r) / 2), get_max(a, b, k * 2 + 2, (l + r) / 2, r));
	}

	T get_min_val(int a, int b) { return get_min(a, b).first; }
	T get_max_val(int a, int b) { return get_max(a, b).first; }
	int get_min_idx(int a, int b) { return get_min(a, b).second; }
	int get_max_idx(int a, int b) { return get_max(a, b).second; }
};


int main() {
	int n;
	cin >> n;
	vector<int>r(n);
	for (int i = 0; i < n - 1; i++)cin >> r[i];
	r[n - 1] = n;

	segment_tree_rmq<17, int, 1001001001>seg;
	for (int i = 0; i < n; i++)seg.update(i, r[i]);

	vector<ll>dp(n);
	for (int i = n - 2; i >= 0; i--) {
		int j = seg.get_max_idx(i + 1, r[i]);
		dp[i] = dp[j] + (n - 1 - i) - (r[i] - j - 1);
	}

	cout << accumulate(dp.begin(), dp.end(), 0ll) << endl;
	return 0;
}