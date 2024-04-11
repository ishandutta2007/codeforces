#include "bits/stdc++.h"
#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS

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
	string s;
	cin >> s;
	int cnt[26] = {};
	int ans = 0;
	REP(i, s.length()) {
		cnt[s[i] - 'a']++;
	}
	REP(i, 26) {
		ans = max(ans, cnt[i]);
		ans = max(ans, cnt[i] * (cnt[i] - 1LL) / 2LL);
	}
	for (int i = 0; i < 26; ++i) {
		for (int q = 0; q < 26; ++q) {
			if (i == q) continue;
			int tmp = 0;
			int cnt = 0;
			REP(j, s.length()) {
				if (s[j] - 'a' == q) cnt++;
			}
			REP(j, s.length()) {
				if (s[j] - 'a' == i) {
					tmp += cnt;
				}
				else if (s[j] - 'a' == q) {
					cnt--;
				}
			}
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
}

#undef int
int main() {
	init();
	solve();
}