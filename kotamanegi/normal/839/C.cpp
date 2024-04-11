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
using namespace std;
#define eps 0.00000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
vector<int> vertex[200000];
long long dp[200000] = {};
double nowing(long long now, long long back) {
	double cnt = 0;
	for (int i = 0;i < vertex[now].size();++i) {
		if (back != vertex[now][i]) {
			cnt++;
		}
	}
	cnt = 1.0 / cnt;
	double ans = 0;
	for (int i = 0;i < vertex[now].size();++i) {
		if (back != vertex[now][i]) {
			ans += nowing(vertex[now][i], now) * cnt;
		}
	}
	ans++;
	return ans;
}
int main() {
	int n;
	cin >> n;
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		vertex[a].push_back(b);
		vertex[b].push_back(a);
	}
	cout << fixed << setprecision(20) << nowing(1, -1) - 1.0 << endl;
	return 0;
}