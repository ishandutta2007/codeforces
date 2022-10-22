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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 30000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(a,b) for(long long a = 0;a < b;++a)
vector<long long> vertexs[300000];
long long solve(long long now, long long back) {
	long long ans = 1;
	long long already_taken = 1;
	REP(i, vertexs[now].size()) {
		if (vertexs[now][i] != back) {
			already_taken++;
			ans *= solve(vertexs[now][i], now);
			ans %= MOD;
		}
	}
	if (now == 1) {
		already_taken--;
	}
	for (long long q = 2; q <= already_taken; ++q) {
		ans *= q;
		ans %= MOD;
	}
	return ans;
}
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	REP(i, n-1) {
		int a, b;
		cin >> a >> b;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	long long ans = solve(1, -1);
	ans *= n;
	ans %= MOD;
	cout << ans << endl;
	return 0;
}