#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
using namespace std;
#define eps 0.000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*16
#define REP(i,n) for(long long i = 0;i < n;++i)
vector<int> vertexs[200000];
int visited[200000];
int main() {
	iostream::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	REP(i, m) {
		long long a, b;
		cin >> a >> b;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	vector<int> ans;
	priority_queue<long long, vector<long long>, greater<long long>> next;
	next.push(1);
	visited[1] = 1;
	while (next.empty() == false) {
		long long now = next.top();
		next.pop();
		ans.push_back(now);
		for (int q = 0; q < vertexs[now].size(); ++q) {
			if (visited[vertexs[now][q]] == 0) {
				visited[vertexs[now][q]] = 1;
				next.push(vertexs[now][q]);
			}
		}
	}
	cout << ans[0];
	for (int i = 1; i < ans.size(); ++i) {
		cout << " " << ans[i];
	}
	cout << endl;
	return 0;
}