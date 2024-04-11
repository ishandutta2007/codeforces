#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma comment (linker, "/STACK:526000000")
#include "bits/stdc++.h"

#define int ll
using namespace std;
typedef string::const_iterator State;
#define eps 1e-8L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
};
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}
#define int ll
void solve() {
	int n;
	cin >> n;
	int turn = 0;
	int ans = 0;
	while (n != 0) {
		if (n % 2 == 1) {
			n--;
			if (turn%2 == 0) ans++;
			turn++;
			continue;
		}
		if (n == 4 or (n / 2) % 2 == 1) {
			if (turn % 2 == 0) {
				ans += n / 2;
			}
			n /= 2;
			turn++;
			continue;
		}
		n--;
		if (turn % 2 == 0) ans++;
		turn++;
		continue;
	}
	cout << ans << endl;
}
#undef int
int main() {
	init();
	int t = 1;
	cin >> t;
	REP(tea, t) {
		solve();
	}
}