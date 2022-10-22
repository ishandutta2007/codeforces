#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

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

unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = time(NULL);
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(10);
}

#define int ll
#define MIN -1000000000
int coloring[(1 << 18)];
queue<vector<int>> dp;
void solve() {
	int n, k;
	cin >> n >> k;
	REP(i, k) {
		int a;
		cin >> a;
		a--;
		coloring[a] = 1;
	}
	for (int i = 0; i < (1 <<n); i += 2) {
		if (coloring[i + 1]) swap(coloring[i + 1], coloring[i]);
		if (coloring[i + 1] == 1){
			dp.push(vector<int>{MIN, MIN, MIN, 1});
			continue;
		}
		if (coloring[i] == 0) {
			dp.push(vector<int>{0, MIN, MIN, MIN});
			continue;
		}
		dp.push(vector<int>{MIN, 1, 1, MIN});
		continue;
	}
	while (dp.size() != 1) {
		vector<int> a = dp.front();
		dp.pop();
		vector<int> b = dp.front();
		dp.pop();
		vector<int> next_push{ MIN,MIN,MIN,MIN };
		REP(i, 4) {
			REP(q, 4) {
				int now_val = a[i] + b[q];
				if (now_val < 0) continue;
				int up_cnt = i / 2 + q / 2;
				int down_cnt = i % 2 + q % 2;
				if (down_cnt != 0) {
					now_val++;
				}
				down_cnt = min(down_cnt, 1LL);
				if (up_cnt != 0) {
					now_val++;
				}
				if (up_cnt == 0) {
					if (down_cnt != 0) {
						now_val++;
					}
					next_push[down_cnt] = max(next_push[down_cnt], now_val);
					continue;
				}
				if (up_cnt == 1) {
					if (down_cnt == 1) {
						now_val++;
						next_push[3] = max(next_push[3], now_val);
						continue;
					}
					next_push[1] = max(next_push[1], now_val + 1);
					next_push[2] = max(next_push[2], now_val + 0);
				}
				if (up_cnt == 2) {
					now_val++;
					next_push[3] = max(next_push[3], now_val);
					continue;
				}
			}
		}
		dp.push(next_push);
	}
	int ans = 0;
	vector<int> now = dp.front();
	dp.pop();
	REP(q, now.size()) {
		int hoge = 0;
		if (q != 0) hoge = 1;
		ans = max(ans, now[q] + hoge);
	}
	cout << ans << endl;
}
#undef int
int main() {
	init();
	solve();
}