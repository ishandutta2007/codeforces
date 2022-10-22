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
	int n;
	cin >> n;
	if (n <= 2) {
		cout << -1 << endl;
		return;
	}
	string s = "1";
	while (s.length() < n-1) {
		s.push_back('0');
	}
	s.push_back('0');
	for (int i = 0;; ++i) {
		int ok = 1;
		int a = 0;
		int b = 0;
		REP(q, s.length()) {
			a *= 10;
			b *= 10;
			a += s[q] - '0';
			b += s[q] - '0';
			a %= 3;
			b %= 7;
		}
		if (a == 0 && b == 0) {
			cout << s << endl;
			return;
		}
		s[s.length() - 2]++;
		for (int q = s.length() - 2; q >= 0; --q) {
			if (s[q] == '0' + 10) {
				s[q] = '0';
				s[q - 1]++;
			}
		}
	}
}

#undef int
int main() {
	init();
	solve();
}