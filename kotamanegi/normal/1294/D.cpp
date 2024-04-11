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
int cnt[500000] = {};
void solve(){
	int query, x;
	cin >> query >> x;
	int ans = 0;
	vector<int> go;
	REP(i, query) {
		int a;
		cin >> a;
		cnt[a % x]++;
		while (cnt[ans % x] >= ans/x + 1) {
			ans++;
		}
		go.push_back(ans);
	}
	REP(i, go.size()) {
		cout << go[i] << endl;
	}
}
#undef int
int main() {
	init();
	solve();
}