#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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
#include <map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.0000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000009LL//1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
using namespace std;
vector<int> vertexs[300000];
int cnt[300000] = {};
vector<int> answer;
int visited[300000] = {};
int failed = 0;

int moving_dfs(int now, int back) {
	visited[now] = 1;
	answer.push_back(now);
	if (cnt[now] % 2 == 1) failed = 1;
	for (int i = 0; i < vertexs[now].size(); ++i) {
		if (vertexs[now][i] != back) {
			cnt[vertexs[now][i]]--;
		}
	}
	for (int i = 0; i < vertexs[now].size(); ++i) {
		if (vertexs[now][i] != back) {
			if (visited[vertexs[now][i]] == 0) {
				moving_dfs(vertexs[now][i], now);
			}
		}
	}
	return 0;
}
int dfs_finding(int now, int back) {
	for (int i = 0; i < vertexs[now].size(); ++i) {
		if (vertexs[now][i] != back) {
			dfs_finding(vertexs[now][i], now);
		}
	}
	if (cnt[now] % 2 == 0) {
		if (back != -1) {
			cnt[back]--;
		}
		moving_dfs(now, back);
	}
	return 0;
}
int main(){
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	REP(i, n) {
		int a;
		cin >> a;
		if (a != 0) {
			vertexs[a].push_back(i + 1);
			vertexs[i + 1].push_back(a);
			cnt[a]++;
			cnt[i + 1]++;
		}
	}
	dfs_finding(1, -1);
	for (int i = 1; i <= n; ++i) {
		if (visited[i] == 0) failed = 1;
	}
	if (failed == 1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << endl;
	}
	return 0;
}