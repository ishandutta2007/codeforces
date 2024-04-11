#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#pragma comment (linker, "/STACK:526000000")

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
int cnt[30];
void solve() {
	int n, k;
	cin >> n >> k;
	cnt[0] = 1;
	for (int i = 1; i < 30; ++i) {
		cnt[i] = cnt[i - 1] * 3LL;
	}
	vector<int> inputs;
	map<int, int> gogo;
	REP(i, n) {
		string s;
		cin >> s;
		vector<int> a;
		REP(i, s.length()) {
			if (s[i] == 'S') a.push_back(0);
			else if (s[i] == 'E') a.push_back(1);
			else a.push_back(2);
		}
		ll cnter = 0;
		REP(i, s.length()) {
			cnter += a[i] * cnt[i];
		}
		inputs.push_back(cnter);
		gogo[cnter]++;
	}
	ll ans = 0;
	for (auto x = gogo.begin(); x != gogo.end(); ++x) {
		ans += (x->second) * (x->second - 1) * (x->second - 2) / 2LL;
		for (auto y = gogo.begin(); y != gogo.end(); ++y) {
			if (x->first <= y->first) continue;
			ll val = 0;
			int geko = 1;
			int a = x->first;
			int b = y->first;
			for (int q = 0; q < k; ++q) {
				if (a % 3 == b % 3) {
					val += geko * (a % 3);
				}
				else {
					int tmp[3] = {};
					tmp[a % 3]++;
					tmp[b % 3]++;
					REP(q, 3) {
						if (tmp[q] == 0) {
							val += q * geko;
							break;
						}
					}
				}
				geko *= 3LL;
				a /= 3LL;
				b /= 3LL;
			}
			if (gogo.find(val) != gogo.end()) {
				ans += x->second * y->second * gogo[val];
			}
		}
	}
	ans /= 3LL;
	cout << ans << endl;
}

#undef int
int main() {
	init();
	solve();
}