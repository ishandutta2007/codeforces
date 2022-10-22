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
	long long s;
	cin >> s;
	long long t = 0;
	while (s >= 10) {
		ll target = s / 10LL;
		t += target * 10LL;
		s -= target * 9LL;
	}
	t += s;
	cout << t << endl;
}

int main() {
	init();
	int t;
	cin >> t;
	REP(te,t)
	solve();
}