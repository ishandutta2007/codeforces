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
#define eps 0.000001
#define LONG_INF 10000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
long long one[6000] = {}, two[6000] = {};
int main(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> paint(m);
	REP(i, m) cin >> paint[i].first >> paint[i].second;
	int imos[6000] = {};
	REP(i, m) {
		imos[paint[i].first]++;
		imos[paint[i].second + 1]--;
	}
	for (int q = 1; q <= 5000; ++q) {
		imos[q] += imos[q - 1];
	}
	long long ans = 0;
	for (int q = 1; q <= 5000; ++q) {
		if (imos[q] == 1) {
			one[q]++;
		}
		else if (imos[q] == 2) {
			two[q]++;
		}
		one[q] += one[q - 1];
		two[q] += two[q - 1];
		if (imos[q] >= 1) ans++;
	}
	sort(paint.begin(), paint.end());
	long long final_ans = 0;
	for (int i = 0; i < m; ++i) {
		for (int q = i + 1; q < m; ++q) {
			int left = max(paint[i].first,paint[q].first);
			int right = min(paint[i].second, paint[q].second);
			long long tere = 0;
			if (left <= right) {
				tere += two[right] - two[left - 1];
			}
			tere += one[paint[i].second] - one[paint[i].first - 1];
			tere += one[paint[q].second] - one[paint[q].first - 1];
			final_ans = max(final_ans, ans - tere);
		}
	}
	cout << final_ans << endl;
	return 0;
}