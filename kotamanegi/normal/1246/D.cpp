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
vector<int> vertexs[200000];
int depth[200000];
int find_depth(int now) {
	depth[now] = 1;
	REP(i, vertexs[now].size()) {
		find_depth(vertexs[now][i]);
		depth[now] = max(depth[now], depth[vertexs[now][i]] + 1);
	}
	return 0;
}
vector<int> ans;
int color[200000];
int now_itr = 0;
int dfs(int now) {
	color[now_itr] = now;
	now_itr++;
	int max_depth = 0;
	REP(i, vertexs[now].size()) {
		max_depth = max(max_depth, depth[vertexs[now][i]]);
	}
	REP(i, vertexs[now].size()) {
		if (max_depth != depth[vertexs[now][i]]) {
			dfs(vertexs[now][i]);
		}
	}
	int hoge = now_itr;
	REP(i, vertexs[now].size()) {
		if (max_depth == depth[vertexs[now][i]]) {
			hoge = dfs(vertexs[now][i]);
		}
	}
	ans.push_back(hoge);
	return hoge;
}
int main() {
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	REP(i, n-1) {
		int a;
		cin >> a;
		vertexs[a].push_back(i + 1);
	}
	find_depth(0);
	dfs(0);
	REP(i, depth[0]) {
		ans.pop_back();
	}
	REP(i, n) {
		cout << color[i] << " ";
	}
	cout << endl;
	cout << ans.size() << endl;
	REP(i, ans.size()) {
		cout << color[ans[i]] << " ";
	}
	cout << endl;
}