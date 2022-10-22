#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144*2LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = time(NULL);
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}

#define int ll
pair<int,int> seg_tree[seg_size * 2];
pair<int,int> seg_find(int now, int n_l, int n_r, int w_l, int w_r) {
	if (w_l <= n_l && n_r <= w_r) return seg_tree[now];
	if (w_r <= n_l || n_r < w_l) return mp(0,0);
	pair<int, int> a = seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r);
	pair<int,int> b = seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r);
	b.first += a.first;
	b.second += a.second;
	return b;
}
void seg_set(int now) {
	pair<int, int> a = seg_tree[now * 2];
	pair<int, int> b = seg_tree[now * 2 + 1];
	a.first += b.first;
	a.second += b.second;
	seg_tree[now] = a;
	if (now > 1) seg_set(now / 2);
}
void refresh() {
	REP(i, seg_size * 2) {
		seg_tree[i] = mp(0, 0);
	}
}
void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(mp(a, -1));
	}
	REP(i, n) {
		cin >> inputs[i].second;
	}
	sort(ALL(inputs));
	int cnt = 0;
	int tmp = 0;
	int ans = 0;
	REP(i, n) {
		if (inputs[i].second == 0) {
			cnt++;
			tmp += inputs[i].first;
			ans -= cnt * inputs[i].first - tmp;
		}
	}
	vector<pair<int, int>> gogo;
	REP(i, n) {
		if (inputs[i].second <= 0) {
			gogo.push_back(mp(inputs[i].second, i));
		}
	}
	sort(ALL(gogo));
	refresh();
	REP(i, gogo.size()) {
		seg_tree[gogo[i].second + seg_size] = mp(inputs[gogo[i].second].first, 1);
		seg_set((gogo[i].second + seg_size) / 2);
		pair<int, int> now = seg_find(1, 0, seg_size, 0, gogo[i].second);
		ans += now.second * inputs[gogo[i].second].first - now.first;
	}

	refresh();
	gogo.clear();
	REP(i, n) {
		if (inputs[i].second >= 0) {
			gogo.push_back(mp(inputs[i].second, i));
		}
	}
	sort(ALL(gogo));
	REP(i, gogo.size()) {
		seg_tree[gogo[i].second + seg_size] = mp(inputs[gogo[i].second].first, 1);
		seg_set((gogo[i].second + seg_size) / 2);
		pair<int, int> now = seg_find(1, 0, seg_size, 0, gogo[i].second);
		ans += now.second * inputs[gogo[i].second].first - now.first;
	}

	refresh();
	gogo.clear();
	REP(i, n) {
		if (inputs[i].second != 0) {
			gogo.push_back(mp(inputs[i].second, i));
		}
	}

	sort(ALL(gogo));
	REP(i, gogo.size()) {
		if (gogo[i].first > 0) {
			pair<int, int> now = seg_find(1, 0, seg_size, 0, gogo[i].second);
			ans += now.second * inputs[gogo[i].second].first - now.first;
		}
		else {
			seg_tree[gogo[i].second + seg_size] = mp(inputs[gogo[i].second].first, 1);
			seg_set((gogo[i].second + seg_size) / 2);
		}
	}
	cout << ans << endl;
}

#undef int
int main() {
	init();
		solve();
}