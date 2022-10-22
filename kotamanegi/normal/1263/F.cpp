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
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
int kazu[2] = {};
int calc[2000][2000];
vector<int> vertexs[3000];
int connected[3000];
tuple<int,int,int> dfs(int now, int back) {
	tuple<int, int, int> ans = make_tuple(1, 1e9, -1e9);
	if (connected[now] != -1) {
		ans = make_tuple(1, connected[now], connected[now]);
	}
	REP(q, vertexs[now].size()) {
		int next = vertexs[now][q];
		if (next == back) continue;
		tuple<int, int, int> neko = dfs(next, now);
		get<0>(ans) += get<0>(neko);
		get<1>(ans) = min(get<1>(ans), get<1>(neko));
		get<2>(ans) = max(get<2>(ans), get<2>(neko));
	}
	if (now != 1) {
		calc[get<1>(ans)][get<2>(ans)] = max(calc[get<1>(ans)][get<2>(ans)], get<0>(ans));
	}
	return ans;
}
int dp[3000];
int main() {
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	REP(tea, 2) {
		cin >> kazu[tea];
		calc[0][n - 1] = max(kazu[tea]-1,calc[0][n-1]);
		REP(q, 3000) {
			connected[q] = -1;
		}
		REP(q, kazu[tea] - 1) {
			int a;
			cin >> a;
			vertexs[a].push_back(q + 2);
			vertexs[q + 2].push_back(a);
		}
		REP(q, n) {
			int a;
			cin >> a;
			connected[a] = q;
		}
		dfs(1, -1);
		for (int q = 0; q < 3000; ++q) {
			vertexs[q].clear();
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int q = 0; q < n - i + 1; ++q) {
			if (q != 0) {
				calc[q - 1][q + i - 1] = max(calc[q - 1][q + i - 1], calc[q][q + i - 1]);
			}
			if (q != n - i) {
				calc[q][q + i] = max(calc[q][q + i], calc[q][q + i - 1]);
			}
		}
	}
	for (int q = 0; q < n; ++q) {
		for (int j = q; j < n; ++j) {
			dp[j + 1] = max(dp[j + 1], dp[q] + calc[q][j]);
		}
	}
	cout << dp[n] << endl;
}