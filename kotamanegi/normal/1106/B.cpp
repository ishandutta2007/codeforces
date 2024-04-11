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
long long remaining[1000000] = {};
long long cost[1000000] = {};
int main() {
#define int long long
	int n, m;
	cin >> n >> m;
	vector<pair<long long, long long>> nexting;
	REP(i, n) {
		cin >> remaining[i];
	}
	REP(i, n) {
		cin >> cost[i];
		nexting.push_back(make_pair(cost[i], i));
	}
	sort(nexting.begin(), nexting.end());
	long long itr = 0;
	REP(i, m) {
		long long a, b;
		cin >> a >> b;
		long long ans = 0;
		a--;
		if (remaining[a] >= b) {
			ans = cost[a] * b;
			remaining[a] -= b;
		}
		else {
			ans = cost[a] * remaining[a];
			b -= remaining[a];
			remaining[a] = 0;
			while (b != 0&&itr != nexting.size()) {
				if (remaining[nexting[itr].second] >= b) {
					ans += cost[nexting[itr].second] * b;
					remaining[nexting[itr].second] -= b;
					b = 0;
				}
				else {
					ans += cost[nexting[itr].second] * remaining[nexting[itr].second];
					b -= remaining[nexting[itr].second];
					remaining[nexting[itr].second] = 0;
					itr++;
				}
			}
			if (b != 0) ans = 0;
		}
		cout << ans << endl;
	}
	return 0;
}