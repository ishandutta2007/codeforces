#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
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
#define LONG_INF 10000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353LL
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
unordered_map<long long,long long> can_go;
long long cnt[600000] = {};
long long random;
long long xoring(long long x) {
	return x ^ random;
}
int main() {
#define int long long
	random = time(NULL);
	iostream::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	map<int, int> gogo;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		gogo[tmp] = i + 1;
	}
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a = gogo[a];
		b = gogo[b];
		if (a < b) {
			long long geko = b * 400000LL + a;
			can_go[xoring(geko)] = 1;
		}
	}
	int ans = 0;
	vector<int> comparison;
	for (int q = n - 1; q >= 0; --q) {
		if (can_go.find(xoring(n * 400000LL + q)) != can_go.end()) {
			//connected
			int plus = 1;
			for (int j = 0; j < comparison.size(); ++j) {
				if (can_go.find(xoring(comparison[j] * 400000LL + q)) == can_go.end()) {
					plus = 0;
					break;
				}
			}
			ans += plus;
			if (plus == 0) {
				comparison.push_back(q);
			}
		}
		else {
			comparison.push_back(q);
		}
	}
	cout << ans << endl;
	return 0;
}