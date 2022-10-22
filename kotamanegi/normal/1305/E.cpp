#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144 * 4LL
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
int cnt[50000];
void solve(){
	int n, m;
	cin >> n >> m;
	if (n == 1) {
		if (m == 0) {
			cout << 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
		return;
	}
	vector<int> ans;
	ans.push_back(1);
	ans.push_back(2);
	cnt[3]++;
	for (int i = 3; i <= n&&m != 0; ++i) {
		for (int q = i;; ++q) {
			if (cnt[q] <= m) {
				m -= cnt[q];
				ans.push_back(q);
				break;
			}
		}
		for (int q = 0; q < ans.size() - 1; ++q) {
			cnt[ans[q] + ans.back()]++;
		}
	}
	if (m != 0) {
		cout << -1 << endl;
		return;
	}
	if (ans.size() != n) {
		if (ans.back() == ans.size()) {
			ans.push_back(2 * ans.size());
		}
		int target = 0;
		for (int i = 0; i < ans.size(); ++i) {
			if (ans[i] != i + 1) {
				target = i + 1;
				break;
			}
		}
		while (ans.size() != n) {
			ans.push_back(ans.back() + target);
			if (ans.back() > 1e9) {
				cout << -1 << endl;
				return;
			}
		}
	}
	if (ans.back() > 1e9) {
		cout << -1 << endl;
		return;
	}

	assert(ans.size() == n);
	REP(i, n) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

#undef int

int main() {
	init();
	solve();
}