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
	vector<int> inputs;
	REP(i, 3) {
		int a;
		cin >> a;
		inputs.push_back(a);
	}
	int ans = 0;
	REP(i, 3) {
		if (inputs[i]) {
			inputs[i]--;
			ans++;
		}
	}
	vector<int> repair = inputs;
	int maxi = 0;
	REP(t, 3) {
		int now = 0;
		for (int i = 0; i < 3; ++i) {
			if (inputs[(i + 1 + t) % 3] != 0 && inputs[(i + 2 + t) % 3] != 0) {
				inputs[(i + 1 + t) % 3]--;
				inputs[(i + 2 + t) % 3]--;
				now++;
			}
		}
		if (inputs[0] != 0 && inputs[1] != 0 && inputs[2] != 0) {
			now++;
		}
		maxi = max(maxi, now);
		inputs = repair;
	}
	cout << ans+maxi << endl;
}
#undef int
int main() {
	init();
	int t;
	cin >> t;
	REP(tea,t)
	solve();
}