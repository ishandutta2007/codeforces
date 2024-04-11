#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;

const int M = 1<<18;
ll seg1[2*M]; // Sum of count of actives below
ll seg2[2*M]; // Sum of cost * count of actives below

int lef[M];
int rig[M];
ll cost[M];
ll cou[M];
int ind[M];

void upd(int i) {
	seg1[i] = seg1[2*i] + seg1[2*i+1];
	seg2[i] = seg2[2*i] + seg2[2*i+1];
}

void set(int x, int j) {
	int i = x + M;
	if (j == -1) {
		seg1[i] = 0;
		seg2[i] = 0;
	} else {
		seg1[i] = cou[j];
		seg2[i] = (ll)cou[j] * cost[j];
	}

	while(i > 1) {
		i >>= 1;
		upd(i);
	}
}

// Returns first index with prefix sum of count >= k, and how much the prefix sum overflows
pair<int, ll> find(ll k, int i = 1, int ia = 0, int ib = M-1) {
	if (ia == ib) return {ia, seg1[i] - k };

	int mid = (ia + ib) >> 1;
	ll ls = seg1[2*i];
	if (ls >= k) return find(k, 2*i, ia, mid);
	else return find(k - ls, 2*i+1, mid+1, ib);
}

ll get(int a, int b, int i = 1, int ia = 0, int ib = M-1) {
	if (ib < a || b < ia) return 0;
	if (a <= ia && ib <= b) return seg2[i];
	int mid = (ia + ib) >> 1;
	return get(a, b, 2*i, ia, mid) + get(a, b, 2*i+1, mid+1, ib);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k, m;
	cin >> n >> k >> m;

	
	vector<pair<int, int>> srt(m);
	vector<pair<int, int>> evs(2*m);
	for (int i = 0; i < m; ++i) {
		cin >> lef[i] >> rig[i] >> cou[i] >> cost[i];
		srt[i] = {cost[i], i};
		evs[2*i] = {lef[i], i+1};
		evs[2*i+1] = {rig[i]+1, -i-1};
	}

	sort(srt.begin(), srt.end());
	for (int i = 0; i < m; ++i) ind[srt[i].second] = i;

	sort(evs.begin(), evs.end());

	ll res = 0;
	int j = 0;
	for (int d = 1; d <= n; ++d) {
		while((j < evs.size()) && (evs[j].first == d)) {
			int i = evs[j].second;
			int t = (i < 0 ? -1 : 1);
			i = (i * t) - 1;

			if (t == -1) {
				set(ind[i], -1);
			} else {
				set(ind[i], i);
			}

			++j;
		}
		auto sub = find(k);
		int x = sub.first;
		ll ovr = sub.second;

		if (ovr > 0) {
			res -= ovr * cost[srt[x].second];
		}
		res += get(0, x);
	}

	cout << res << '\n';
}