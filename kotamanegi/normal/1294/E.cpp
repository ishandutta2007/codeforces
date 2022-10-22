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
vector<vector<int>> matrixs;
int tmp[3000000];
void solve(){
	int n, m;
	cin >> n >> m;
	REP(i, n) {
		matrixs.push_back(vector<int>{});
		REP(q, m) {
			int a;
			cin >> a;
			matrixs.back().push_back(a);
		}
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int cost = 1e18;
		REP(q, n) {
			tmp[q] = 0;
		}
		for (int q = 0; q < n; ++q) {
			if (matrixs[q][i] > n* m) continue;
			int target = matrixs[q][i] - (i + 1LL);
			if (target % m != 0||target < 0) continue;
			target /= m;
			if (target <= q) {
				tmp[q - target]++;
			}
			else {
				tmp[(q + n) - target]++;
			}
		}
		for (int q = 0; q < n; ++q) {
			cost = min(cost, (n - tmp[q]) + q);
		}
		ans += cost;
	}
	cout << ans << endl;
}
#undef int
int main() {
	init();
	solve();
}