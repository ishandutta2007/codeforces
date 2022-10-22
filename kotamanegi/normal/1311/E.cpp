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
void solve() {
	int n, d;
	cin >> n >> d;
	if (d > n* (n - 1) / 2) {
		cout << "NO" << endl;
		return;
	}
	int cnt[10000] = {};
	cnt[0] = 1;
	for (int i = 1; i < n; ++i) {
		cnt[i] = 1;
		d -= i;
	}
	d *= -1;
	for (int i = n - 1; d != 0&&i >= 0; --i) {
		for (int q = 1;q < i; ++q) {
			if (cnt[q - 1] * 2 < cnt[q] + 1) continue;
			int hoge = i - q;
			if (d >= hoge) {
				d -= hoge;
				cnt[i]--;
				cnt[q]++;
				break;
			}
		}
	}
	if (d > 0) {
		cout << "NO" << endl;
		return;
	}
	int ans[10000] = {};
	vector<int> back_info[500];
	back_info[0].push_back(1);
	cout << "YES" << endl;
	int now = 2;
	for (int i = 1; i < 500; ++i) {
		REP(q, cnt[i]) {
			ans[now] = back_info[i - 1][q / 2];
			back_info[i].push_back(now);
			now++;
		}
	}
	for (int i = 2; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

#undef int
int main() {
	init();
	int t;
	cin >> t;
	REP(tea, t)
		solve();
}