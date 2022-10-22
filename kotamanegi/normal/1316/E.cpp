#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144 * 4LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = time(NULL);
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}

#define int ll
int dp[100003][(1 << 7)];
void solve() {
	int n, p, k;
	cin >> n >> p >> k;
	vector<vector<int>> inputs(n);
	REP(i, n) {
		int a;
		cin >> a;
		inputs[i].push_back(a);
	}
	REP(i, n) {
		REP(q, p) {
			int a;
			cin >> a;
			inputs[i].push_back(a);
		}
	}
	sort(ALL(inputs));
	reverse(ALL(inputs));
	int base_ans = 0;
	REP(i, k) {
		base_ans += inputs[i][0];
	}
	REP(i, n+2) {
		REP(q, (1 << 7)) {
			dp[i][q] = -1e18;
		}
	}
	dp[0][0] = 0;
	REP(i, n) {
		REP(q, (1 << p)) {
			dp[i + 1][q] = max(dp[i+1][q], dp[i][q]);
			int cnt = 0;
			REP(j, p) {
				if (q & (1 << j)) cnt++;
			}
			if (cnt == p) continue;
			int cost = 0;
			if (cnt + k > i) {
				cost -= inputs[i][0];
				cost += inputs[cnt + k][0];
			}
			REP(j, p) {
				if (!(q & (1 << j))) {
					dp[i + 1][q + (1 << j)] = max(dp[i + 1][q + (1 << j)], dp[i][q] + cost + inputs[i][j+1]);
				}
			}
		}
	}
	cout << base_ans + dp[n][(1 << p) - 1] << endl;
}
#undef int

int main() {
	init();
	solve();
}