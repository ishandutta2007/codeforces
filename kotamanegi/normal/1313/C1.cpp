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
	cout << fixed << setprecision(10);
}

#define int ll
pair<int, int> seg_tree[seg_size * 4];
pair<int, int> seg_find(int now, int n_l, int n_r, int w_l, int w_r) {
	if (w_l <= n_l && n_r <= w_r) {
		return seg_tree[now];
	}
	if (w_r <= n_l || n_r <= w_l) return mp(1e18, -1);
	pair<int, int> a = seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r);
	pair<int, int> b = seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r);
	if (a.first < b.first) return a;
	return b;
}
void seg_set(int now) {
	if (seg_tree[now * 2].first < seg_tree[now * 2 + 1].first) {
		seg_tree[now] = seg_tree[now * 2];
	}
	else {
		seg_tree[now] = seg_tree[now * 2 + 1];
	}
	if (now > 1) seg_set(now / 2);
}

int ans[600000];
ll solve(int left, int right,int basing) {
	if (left == right) return 0;
	pair<int, int> now_min = seg_find(1, 0, seg_size, left, right);
	ll bases = (right - left) * (now_min.first - basing);
	int L = solve(left, now_min.second, now_min.first);
	int R = solve(now_min.second + 1, right, now_min.first);
	if (L < R) {
		//left
		while (now_min.second >= left) {
			ans[now_min.second] = now_min.first;
			now_min.second--;
		}
	}
	else {
		//right
		while (now_min.second < right) {
			ans[now_min.second] = now_min.first;
			now_min.second++;
		}
	}
	return bases + max(L, R);
}
void solve() {
	int n;
	cin >> n;
	REP(i, seg_size * 4) {
		seg_tree[i] = mp(1e18, -1);
	}
	REP(i, n) {
		int a;
		cin >> a;
		seg_tree[(i + seg_size)] = mp(a, i);
		seg_set((i + seg_size) / 2);
	}
	solve(0, n,0);
	REP(i, n) {
		if (i != 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
#undef int
int main() {
	init();
	solve();
}