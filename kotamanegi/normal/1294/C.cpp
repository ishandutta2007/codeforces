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

#define int ll
pair<int,int> solve(int a,int start) {
	for (int q = start + 1; q * q < a; ++q) {
		if (a % q == 0) {
			if (a / q > q) {
				return mp(q, a / q);
			}
		}
	}
	return mp(-1, -1);
}
void solve() {
	int n;
	cin >> n;
	for (int i = 2; i * i * i <= n; ++i) {
		if (n % i == 0) {
			pair<int, int> now = solve(n / i, i);
			if (now.first != -1) {
				cout << "YES" << endl;
				cout << i << " " << now.first << " " << now.second << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
	return;
}
#undef int
int main() {
	init();
	int t;
	cin >> t;
	REP(tea,t)
	solve();
}