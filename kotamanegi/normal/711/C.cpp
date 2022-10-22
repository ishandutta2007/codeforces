#define _CRT_SECURE_NO_WARNINGS
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
#include<map>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <iomanip>
#include <malloc.h>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
long long dp[200][200][200] = {};
long long need[1000][1000] = {};
#define INF 1000000000000000000
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> dis;
	REP(i, n) {
		int a;
		cin >> a;
		dis.push_back(a);
	}
	REP(i, n) {
		REP(q, m) {
			cin >> need[i][q];
		}
	}
	REP(i, 200) {
		REP(q, 200) {
			REP(j, 200) {
					dp[i][q][j] = INF;
			}
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0;i < n;++i) {
		if (dis[i] == 0) {
			for (int q = 0;q <= n;++q) {
				for (int j = 0;j <= m;++j) {
					for (int p = 1;p <= m;++p) {
						if (j != p) {
							dp[i + 1][q + 1][p] = min(dp[i + 1][q + 1][p], dp[i][q][j] +need[i][p-1]);
						}
						else {
							dp[i + 1][q][p] = min(dp[i + 1][q][p], dp[i][q][j] + need[i][p-1]);
						}
					}
				}
			}
		}
		else {
			for (int q = 0;q <= n;++q) {
				for (int j = 0;j <= m;++j) {
					if (j != dis[i]) {
						dp[i + 1][q + 1][dis[i]] = min(dp[i + 1][q + 1][dis[i]], dp[i][q][j]);
					}
					else {
						dp[i + 1][q][dis[i]] = min(dp[i + 1][q][dis[i]], dp[i][q][j]);
					}
				}
			}
		}
	}
	long long ans = INF;
	for (int i = 0;i <= m;++i) {
		if (dp[n][k][i] != INF) {
			ans = min(ans, dp[n][k][i]);
		}
	}
	if (ans != INF) {
		cout << ans << endl;
	}
	else {
		cout << "-1" << endl;
	}
	return 0;
}