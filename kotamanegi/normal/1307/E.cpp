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
}

int gogo[2][5000][5000];
#define int ll
vector<int> cows[5000];
pair<int, int> ans[5004];
void solve() {
	int n, m;
	scanf("%lld%lld", &n, &m);
	vector<int> s;
	REP(i, n) {
		int a;
		scanf("%lld", &a);
		a--;
		s.push_back(a);
	}
	{
		REP(i, n) {
			int cnt = -1;
			REP(q, n) {
				if (s[q] == i) {
					cnt++;
					gogo[0][i][cnt] = q;
				}
			}
			cnt++;
			while (cnt < 5000) {
				gogo[0][i][cnt] = -1;
				cnt++;
			}
		}
		REP(i, n) {
			int cnt = -1;
			for (int q = n - 1; q >= 0; --q) {
				if (s[q] == i) {
					cnt++;
					gogo[1][i][cnt] = q;
				}
			}
			cnt++;
			while (cnt < 5000) {
				gogo[1][i][cnt] = -1;
				cnt++;
			}
		}
	}


	REP(i, m) {
		int a, b;
		scanf("%lld%lld", &a, &b);
		a--; b--;
		cows[a].push_back(b);
	}
	REP(i, n) {
		sort(ALL(cows[i]));
	}
	pair<int, int> now_ans = mp(0, 1);
	for (int i = -1; i < n; ++i) {
		REP(q, 5004) {
			ans[q] = mp(0, 0);
		}
		if (i == -1) {
			ans[0] = mp(1, 1);
		}
		int colored = -1;
		int next_go = 2;
		if (i != -1) {
			REP(j, n) {
				REP(t, cows[j].size()) {
					if (gogo[0][j][cows[j][t]] == -1) continue;
					if (gogo[0][j][cows[j][t]] == i) {
						//color by left
						colored = j;
						ans[1].first = 1;
						ans[1].second += 1;
						int cnt = 0;
						for (int q = 0; q < cows[j].size(); ++q) {
							if (gogo[1][j][cows[j][q]] > i) {
								cnt++;
							}
							else {
								break;
							}
						}
						if (cnt > t) {
							cnt--;
						}
						if (cnt != 0) {
							ans[2].first = 1;
							ans[2].second += cnt;
						}
						break;
					}
				}
				if (colored != -1) {
					break;
				}
			}
			if (colored == -1) continue;
		}
		for (int q = 0; q < n; ++q) {
			if (colored == q) continue;
			//q is sweetness
			pair<int, int> ways = mp(0, 0);
			int right_cnt = 0;
			REP(j, cows[q].size()) {
				if (gogo[1][q][cows[q][j]] == -1) break;
				if (gogo[1][q][cows[q][j]] <= i) break;
				right_cnt++;
			}
			ways.first += right_cnt;
			REP(j, cows[q].size()) {
				if (gogo[0][q][cows[q][j]] == -1) break;
				if (gogo[0][q][cows[q][j]] > i) break;
				ways.first++;
				if (right_cnt > j) {
					ways.second += right_cnt - 1;
				}
				else {
					ways.second += right_cnt;
				}
			}
			for (int q = next_go; q >= 0; --q) {
				if (ans[q].first == 0) continue;
				if (ways.first != 0) {
					ans[q + 1].first = 1;
					ans[q + 1].second += ways.first * ans[q].second;
					ans[q + 1].second %= MAX_MOD;
					next_go = max(next_go, q + 1);
				}
				if (ways.second != 0) {
					ans[q + 2].first = 1;
					ans[q + 2].second += ways.second * ans[q].second;
					ans[q + 2].second %= MAX_MOD;
					next_go = max(next_go, q + 2);
				}
				break;
			}
		}
		for (int q = m; q >= 0; --q) {
			if (ans[q].first == 1) {
				if (now_ans.first > q) break;
				if (now_ans.first < q) {
					now_ans = mp(q, 0);
				}
				now_ans.second += ans[q].second;
				now_ans.second %= MAX_MOD;
				break;
			}
		}
	}
	if (now_ans.first == 0) {
		now_ans.second = 1;
	}
	printf("%lld %lld\n", now_ans.first, now_ans.second);
}

#undef int
int main() {
	init();
	solve();
}