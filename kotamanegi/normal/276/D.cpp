#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#pragma comment (linker, "/STACK:526000000")

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

void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}

#define int ll
void solve(){
	ll l, r;
	cin >> l >> r;
	for (int i = 62; i >= 0; --i) {
		int a = 1LL << i;
		if ((a & l) != (a & r)) {
			cout << (1LL << (i+1)) - 1LL << endl;
			return;
		}
		if ((a & l)) {
			l -= a;
			r -= a;
		}
	}
	cout << 0 << endl;
}

#undef int
int main() {
	init();
	solve();
}