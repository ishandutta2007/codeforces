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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans[4] = {};
	if (b or c) {
		ans[1] = 1;
	}
	if (a or d) {
		ans[0] = 1;
	}
	if ((a + b) % 2 == 0) {
		swap(ans[0], ans[3]);
		swap(ans[1], ans[2]);
	}
	string geko[2] = { "Tidak","Ya" };
	REP(q, 4) {
		if (q != 0) cout << " ";
		cout << geko[ans[q]];
	}
	cout << endl;
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