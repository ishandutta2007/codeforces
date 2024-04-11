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
	int n, r, avg;
	cin >> n >> r >> avg;
	avg *= n;
	vector<pair<int, int>> inputs;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		inputs.push_back(mp(b, r - a));
		avg -= a;
	}
	sort(ALL(inputs));
	int ans = 0;
	avg = max(avg, 0LL);
	REP(i, inputs.size()) {
		if (avg <= inputs[i].second) {
			ans += avg * inputs[i].first;
			avg = 0;
		}
		else {
			ans += inputs[i].second * inputs[i].first;
			avg -= inputs[i].second;
		}
	}
	cout << ans << endl;
}
#undef int
int main() {
	init();
	solve();
}