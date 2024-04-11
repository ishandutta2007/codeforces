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
	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << "NO" << endl;
		return;
	}
	vector<pair<int, int>> inputs;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		inputs.push_back(mp(a, b));
	}
	for (int i = 0; i < n/2; ++i) {
		pair<int, int> next_go = mp(inputs[i + 1].first - inputs[i].first, inputs[i + 1].second - inputs[i].second);
		int target = n / 2 + i;
		pair<int, int> now_go = mp(inputs[(target + 1)%n].first - inputs[target].first, inputs[(target + 1)%n].second - inputs[target].second);
		if (now_go.first != 0) {
			int hoge = next_go.first / now_go.first;
			now_go.first *= hoge;
			now_go.second *= hoge;
		}
		else if (now_go.second != 0) {
			int hoge = next_go.second / now_go.second;
			now_go.first *= hoge;
			now_go.second *= hoge;
		}
		if (next_go != now_go) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}
#undef int
int main() {
	init();
	solve();
}