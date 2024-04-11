#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
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

#define int ll
void solve(){
	string s;
	cin >> s;
	int ans = 0;
	REP(t, 2) {
		while (s.empty() == false && s.back() == '0') {
			s.pop_back();
		}
		reverse(ALL(s));
	}
	REP(i, s.length()) {
		if (s[i] == '0') {
			ans++;
		}
	}
	cout << ans << endl;
}
#undef int
int main() {
	//init();
	int t;
	cin >> t;
	REP(te,t)
	solve();
}