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


int dp[300000][(1 << 8)];
vector<pair<int, int>> bit_info[300000];
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> inputs;
	map<int, int> compress;
	vector<int> unzip;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		b++;
		compress[a] = 1;
		compress[b] = 1;
		inputs.push_back(mp(a, b));
	}
	int cnt = 0;
	for (auto x = compress.begin(); x != compress.end(); ++x) {
		x->second = cnt;
		cnt++;
		unzip.push_back(x->first);
	}
	REP(i, inputs.size()) {
		inputs[i].first = compress[inputs[i].first];
		inputs[i].second = compress[inputs[i].second];
	}
	REP(i, inputs.size()) {
		bit_info[inputs[i].first].push_back(mp(i, 1));
		for (int q = inputs[i].first+1; q < inputs[i].second; ++q) {
			bit_info[q].push_back(mp(i, 0));
		}
	}
	for (int i = 1; i < unzip.size(); ++i) {
		vector<pair<int, int>> next_transfer;
		int masking = (1 << bit_info[i].size()) - 1;
		for (int q = 0; q < bit_info[i - 1].size(); ++q) {
			REP(j, bit_info[i].size()) {
				if (bit_info[i][j].first == bit_info[i - 1][q].first) {
					next_transfer.push_back(mp(q, j));
					masking -= (1 << j);
				}
			}
		}
		REP(q, (1 << bit_info[i - 1].size())) {
			int target = 0;
			int cnt = 0;
			REP(j, next_transfer.size()) {
				if ((1 << next_transfer[j].first) & q) {
					target += 1 << next_transfer[j].second;
				}
			}
			int now = dp[i - 1][q];
			REP(j, bit_info[i - 1].size()) {
				if (q & (1 << j)) cnt++;
			}
			if (cnt % 2 == 1) {
				now += unzip[i] - unzip[i - 1];
			}
			dp[i][target] = max(dp[i][target], now);
		}
		vector<int> can_do;
		REP(q, bit_info[i].size()) {
			if (bit_info[i][q].second == 1) {
				can_do.push_back(q);
			}
		}
		REP(j, (1 << bit_info[i].size())) {
			if (masking & j) continue;
			REP(p, 1 << can_do.size()) {
				int now = p;
				int target = j;
				for (int t = 0; now != 0; ++t) {
					if (now % 2) {
						target += 1 << can_do[t];
					}
					now /= 2;
				}
				dp[i][target] = max(dp[i][target], dp[i][j]);
			}
		}
	}
	cout << dp[unzip.size()-1][0] << endl;
}
#undef int
int main() {
	init();
	solve();
}