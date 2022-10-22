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
	int n;
	cin >> n;
	int ok = 0;
	REP(i, n) {
		int a;
		cin >> a;
		if (a % 2 == 1) {
			ok++;
		}
	}
	if (ok > 0) {
		if (ok != n || n % 2 == 1) {
			ok = 1;
		}
		else {
			ok = 0;
		}
	}
	string s[2] = { "NO","YES" };
	cout << s[ok] << endl;
}

int main() {
	init();
	int t;
	cin >> t;
	REP(te,t)
	solve();
}