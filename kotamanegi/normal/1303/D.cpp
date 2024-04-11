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
int cnt[200];
void solve(){
	REP(j, 200) {
		cnt[j] = 0;
	}
	ll n, m;
	cin >> n >> m;
	vector<ll> inputs;
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		int cnter = -1;
		while (a != 0) {
			a /= 2LL;
			cnter++;
		}
		cnt[cnter]++;
	}
	int ans = 0;
	for (int i = 0; i < 63; ++i) {
		int hoge = (1LL << (long long)i);
		if (hoge & n) {
			cnt[i]--;
		}
	}
	for (int q = 0; q < 62; ++q) {
		if (cnt[q] == -1) {
			for (int j = q + 1; j <= 64; ++j) {
				if (cnt[j] > 0) {
					for (int t = j; t > q; --t) {
						cnt[t]--;
						cnt[t - 1] += 2LL;
						ans++;
					}
					break;
				}
			}
			if (cnt[q] == -1) {
				ans = -1;
				break;
			}
		}
		cnt[q + 1] += cnt[q] / 2LL;
	}
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