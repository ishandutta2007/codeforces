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

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	if (x > y) swap(x, y);
	int kill = x + y - 2LL;
	kill -= max(0LL, min(x - 1, n - y - 1LL));
	kill -= max(0LL, min(y - 1, n - x - 1LL));
	pair<int, int> ans = mp((kill+3) / 2,x+y-1);
	ans.first = max(1LL, ans.first);
	ans.second = min(n, ans.second);
	cout << ans.first << " " << ans.second << endl;
}
#undef int
int main() {
	init();
	int t;
	cin >> t;
	REP(tea,t)
	solve();
}