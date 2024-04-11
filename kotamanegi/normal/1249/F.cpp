//J^!w

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
#define int long long
int win[300];
int sizing[300];
vector<int> vertexs[300];
int dp[300][300];
int pre_dp[300];
int merge_dp[300];
int n, k;

int dfs(int now, int back) {
	sizing[now] = 1;
	for (int q = 0; q < vertexs[now].size(); ++q) {
		int go = vertexs[now][q];
		if (go == back) continue;
		dfs(go, now);
		sizing[now] += sizing[go];
	}
	REP(i, sizing[now] + 1) {
		pre_dp[i] = 0;
	}
	int now_size = 1;
	REP(q, vertexs[now].size()) {
		int go = vertexs[now][q];
		if (go == back) continue;
		for (int t = 0; t < sizing[go]; ++t) {
			merge_dp[t + 1] = dp[go][t];
		}
		for (int j = 0; j < now_size; ++j) {
			for (int t = 1; t <= sizing[go]; ++t) {
				if (j + t >= k) {
					merge_dp[min(j, t)] = max(merge_dp[min(j, t)], pre_dp[j] + dp[go][t - 1]);
				}
			}
		}
		now_size += sizing[go];
		REP(q, now_size) {
			pre_dp[q] = max(merge_dp[q],pre_dp[q]);
			merge_dp[q] = 0;
		}
		for (int q = now_size - 2; q >= 0; --q) {
			pre_dp[q] = max(pre_dp[q], pre_dp[q + 1]);
		}
	}
	REP(i, sizing[now]) {
		dp[now][i] = pre_dp[i];
	}
	dp[now][0] = max(dp[now][0], dp[now][k] + win[now]);
	return 0;
}
#undef int
int main() {
#define int long long
	cin >> n >> k;
	k++;
	REP(i, n) {
		cin >> win[i];
	}
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	int ans = 0;
	REP(i, n) {
		REP(q, n) {
			REP(j, k+1) {
				dp[q][j] = 0;
			}
		}
		dfs(i, -1);
		ans = max(ans, dp[i][0]);
	}
	cout << ans << endl;
}