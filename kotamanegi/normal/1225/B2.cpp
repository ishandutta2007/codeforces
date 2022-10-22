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
	int n, k, d;
	cin >> n >> k >> d;
	int ans = 1e18;
	int now = 0;
	vector<int> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(a);
	}
	map<int, int> geko;
	REP(i, n) {
		geko[inputs[i]]++;
		if (geko[inputs[i]] == 1) now++;
		if (i >= d) {
			geko[inputs[i - d]]--;
			if (geko[inputs[i - d]] == 0)now--;
		}
		if (i + 1 >= d) ans = min(ans, now);
	}
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