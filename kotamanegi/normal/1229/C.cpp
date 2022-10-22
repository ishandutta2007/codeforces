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
#define LONG_INF 1000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
queue<int> vertexs[200000];
long long cnt[200000];
int main() {
#define int long long
	int n,m;
	scanf("%lld%lld", &n, &m);
	REP(i, m) {
		int a, b;
		scanf("%lld%lld", &a, &b);
		if (a > b) swap(a, b);
		cnt[a]++;
		cnt[b]++;
		vertexs[a].push(b);
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] == 0) continue;
		ans += (long long)(vertexs[i].size()) * (cnt[i] - (long long)(vertexs[i].size()));
	}
	printf("%lld\n", ans);
	int query;
	scanf("%lld", &query);
	REP(tea, query) {
		int target;
		scanf("%lld", &target);
		ans -= (long long)(vertexs[target].size()) * (cnt[target] - (long long)(vertexs[target].size()));
		while (vertexs[target].empty() == false) {
			int next_go = vertexs[target].front();
			vertexs[target].pop();
			ans -= (long long)(vertexs[next_go].size()) * (cnt[next_go] - (long long)(vertexs[next_go].size()));
			vertexs[next_go].push(target);
			ans += (long long)(vertexs[next_go].size()) * (cnt[next_go] - (long long)(vertexs[next_go].size()));
		}
		printf("%lld\n", ans);
	}
}