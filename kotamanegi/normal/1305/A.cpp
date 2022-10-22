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
void solve(){
	int n;
	cin >> n;
	vector<int> a, b;
	REP(i, n) {
		int c;
		cin >> c;
		a.push_back(c);
	}
	REP(i, n) {
		int c;
		cin >> c;
		b.push_back(c);
	}
	sort(ALL(a));
	sort(ALL(b));
	REP(i, a.size()) {
		cout << a[i] << " ";
	}
	cout << endl;
	REP(i, b.size()) {
		cout << b[i] << " ";
	}
	cout << endl;
}

#undef int

int main() {
	init();
	int t;
	cin >> t;
	REP(tea,t)
	solve();
}