#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(100);
}

void solve() {
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	vector<int> inputs;
	REP(i, n) {
		int c;
		cin >> c;
		c %= (a + b);
		if (c == 0) {
			c += a + b;
		}
		inputs.push_back((c-a + a - 1) / a);
	}
	sort(ALL(inputs));
	REP(i, inputs.size()) {
		k -= inputs[i];
		if (k < 0) {
			cout << i << endl;
			return;
		}
	}
	cout << n << endl;
	return;
 }

int main() {
	init();
	solve();
}