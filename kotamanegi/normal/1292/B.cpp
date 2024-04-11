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
void solve(){
	vector<pair<int, int>> inputs;
	pair<int, int> now;
	cin >> now.first >> now.second;
	inputs.push_back(now);
	int A[2] = {};
	int B[2] = {};
	REP(i, 2) {
		cin >> A[i];
	}
	REP(i, 2) {
		cin >> B[i];
	}
	pair<int, int> s;
	cin >> s.first >> s.second;
	int t;
	cin >> t;
	while (inputs.back().first <= 5e17 / A[0]&&inputs.back().second <= 5e17 / A[1]) {
		pair<int, int> next;
		next.first = A[0] * inputs.back().first + B[0];
		next.second = A[1] * inputs.back().second + B[1];
		inputs.push_back(next);
	}
	int ans = 0;
	for (int i = 0; i < inputs.size(); ++i) {
		for (int q = i; q < inputs.size(); ++q) {
			int cost = 0;
			for (int j = i + 1; j <= q; ++j) {
				cost += inputs[j].first - inputs[j - 1].first;
				cost += inputs[j].second - inputs[j - 1].second;
			}
			cost += min(llabs(s.first - inputs[i].first) + llabs(s.second - inputs[i].second), llabs(s.first - inputs[q].first) + llabs(s.second - inputs[q].second));
			if (cost <= t) {
				ans = max(ans, q - i + 1);
			}
		}
	}
	cout << ans << endl;
	return;
}

#undef int
int main() {
	init();
	solve();
}