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
	int n, m, k;
	cin >> n >> m >> k;
	if (4 * n * m - 2 * n - 2 * m < k) {
		cout << "NO" << endl;
		return;
	}
	vector<pair<int, char>> inputs;

	//first
	for (int i = 0; i < m-1; ++i) {
		inputs.push_back(mp(1, 'R'));
		if (n - 1 != 0) {
			inputs.push_back(mp(n - 1, 'D'));
			inputs.push_back(mp(n - 1, 'U'));
		}
	}
	//then
	if (m - 1 != 0) {
		inputs.push_back(mp(m - 1, 'L'));
	}
	//finally
	for (int i = 0; i < n - 1; ++i) {
		inputs.push_back(mp(1, 'D'));
		if (m - 1 != 0) {
			inputs.push_back(mp(m - 1, 'R'));
			inputs.push_back(mp(m - 1, 'L'));
		}
	}
	if (n - 1 != 0) {
		inputs.push_back(mp(n - 1, 'U'));
	}
	REP(i, inputs.size()) {
		if (k > inputs[i].first) {
			k -= inputs[i].first;
		}
		else {
			inputs[i].first = k;
			while (inputs.size() != i + 1) {
				inputs.pop_back();
			}
		}
	}
	cout << "YES" << endl;
	cout << inputs.size() << endl;
	REP(i, inputs.size()) {
		cout << inputs[i].first << " " << inputs[i].second << endl;
	}
}
#undef int

int main() {
	init();
	solve();
}