
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
	int n;
	cin >> n;
	vector<int> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(a);
	}
	vector<int> dists;
	REP(i, inputs.size()) {
		if (inputs[i] == -1) {
			if (i+1 < inputs.size()&&inputs[i + 1] != -1) {
				dists.push_back(inputs[i + 1]);
			}
			if (i - 1 >= 0 && inputs[i - 1] != -1) {
				dists.push_back(inputs[i - 1]);
			}
		}
	}
	if (dists.size() == 0) {
		cout << "0 1" << endl;
		return;
	}
	sort(ALL(dists));
	int hoge = dists.back() + dists[0];
	hoge /= 2LL;
	int ans = 0;
	REP(i, inputs.size()) {
		if (inputs[i] == -1) {
			inputs[i] = hoge;
		}
		if (i >= 1) {
			ans = max(ans, llabs(inputs[i] - inputs[i - 1]));
		}
	}
	cout << ans << " " << hoge << endl;
}
#undef int

int main() {
	init();
	int t;
	cin >> t;
	REP(te,t)
	solve();
}