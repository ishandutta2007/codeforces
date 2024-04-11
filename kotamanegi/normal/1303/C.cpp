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
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}
#define int ll
void solve(){
	string s;
	cin >> s;
	string ans;
	ans.push_back(s[0]);
	int now = 0;
	for (int q = 1; q < s.length(); ++q) {
		if (now != 0 && ans[now - 1] == s[q]) {
			now--;
		}
		else if (now != ans.length() - 1 && ans[now + 1] == s[q]) {
			now++;
		}
		else {
			if (now == 0) {
				ans.insert(ans.begin(), s[q]);
			}
			else if (now == ans.length() - 1) {
				ans.push_back(s[q]);
				now++;
			}
			else {
				cout << "NO" << endl;
				return;
			}
		}
	}
	REP(i, ans.size()) {
		for (int q = i + 1; q < ans.length(); ++q) {
			if (ans[i] == ans[q]) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
	for (char i = 'a'; i <= 'z'; ++i) {
		int ok = 1;
		REP(q, ans.size()) {
			if (ans[q] == i) {
				ok = 0;
			}
		}
		if (ok == 1) {
			ans.push_back(i);
		}
	}
	cout << ans << endl;
}
#undef int
int main() {
	init();
	int t;
	cin >> t;
	REP(te,t)
	solve();
}