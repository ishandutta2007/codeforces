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
	int n, g, b;
	cin >> n >> g >> b;
	int ans = 0;
	int hoge = (n + 1) / 2LL;
	int tmp = (hoge - 1) / g;
	ans = tmp * (g + b);
	hoge -= g * tmp;
	ans += hoge;
	ans = max(ans, n);
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