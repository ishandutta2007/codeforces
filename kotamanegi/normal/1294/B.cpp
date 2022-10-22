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
void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> inputs;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		inputs.push_back(mp(a, b));
	}
	sort(ALL(inputs));
	pair<int, int> now = mp(0, 0);
	string ans;
	REP(i, inputs.size()) {
		while (inputs[i].first > now.first) {
			now.first++;
			ans.push_back('R');
		}
		while (inputs[i].second > now.second) {
			now.second++;
			ans.push_back('U');
		}
		if (now != inputs[i]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	cout << ans << endl;
}
#undef int
int main() {
	init();
	int t;
	cin >> t;
	REP(tea,t)
	solve();
}