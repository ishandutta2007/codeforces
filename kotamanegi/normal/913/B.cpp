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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
vector<int> vertexs[2000];
int dfs(int now, int back) {
	int cnt = 0;
	for (int i = 0;i < vertexs[now].size();++i) {
		if (vertexs[now][i] != back) {
			if (vertexs[vertexs[now][i]].size() != 1) {
				int hoge = dfs(vertexs[now][i], now);
				if (hoge == 1) return 1;
			}
			else cnt++;
		}
	}
	if (cnt >= 3) return 0;
	return 1;
}
int main() {
	int n;
	cin >> n;
	REP(i, n-1) {
		int a;
		cin >> a;
		vertexs[a].push_back(i + 2);
		vertexs[i + 2].push_back(a);
	}
	string ans[2] = { "Yes","No" };
	cout << ans[dfs(1, -1)] << endl;
	return 0;
}