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
	string s;
	cin >> s;
	map<pair<int, int>, int> left;
	pair<int, int> now = mp(0, 0);
	left[now] = 1;
	pair<int, int> ans = mp(-1, 1e9);
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'L') {
			now.first++;
		}
		else if (s[i] == 'R') {
			now.first--;
		}
		else if (s[i] == 'U') {
			now.second++;
		}
		else {
			now.second--;
		}
		if (left.find(now) == left.end()) {
		}
		else {
			pair<int, int> go = mp(left[now], i + 1);
			if (go.second - go.first < ans.second - ans.first) {
				ans = go;
			}
		}
		left[now] = i + 2;
	}
	if (ans.first == -1) {
		cout << -1 << endl;
		return;
	}
	cout << ans.first << " " << ans.second << endl;
	return;
 }

int main() {
	init();
	int t;
	cin >> t;
	REP(te,t)
	solve();
}