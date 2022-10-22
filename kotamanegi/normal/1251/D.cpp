//J^!w

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
vector<pair<long long, long long>> colors;
long long n, s;
bool solve(long long now) {
	long long cnt = 0;
	long long money = s;
	for (int q = 0; q < colors.size(); ++q) {
		if (colors[q].second < now) {
			cnt++;
			money -= colors[q].first;
		}
	}
	if (cnt > n / 2) return 0;
	long long remaining = 0;
	for (int q = 0; q < colors.size(); ++q) {
		if (colors[q].second >= now) {
			if (colors[q].first >= now) {
				money -= colors[q].first;
			}
			else {
				if (cnt != n / 2) {
					cnt++;
					money -= colors[q].first;
				}
				else {
					remaining++;
				}
			}
		}
	}
	money -= now * remaining;
	if (money >= 0) return 1;
	return 0;
}
int main() {
	iostream::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	REP(qte, test_case) {
		colors.clear();
		cin >> n >> s;
		REP(i, n) {
			long long a, b;
			cin >> a >> b;
			colors.push_back(make_pair(a, b));
		}
		sort(colors.begin(), colors.end());
		long long bot = 0;
		long long top = 1e9+1;
		while (top - bot > 1) {
			long long mid = (top + bot) / 2;
			if (solve(mid) == 1) {
				bot = mid;
			}
			else {
				top = mid;
			}
		}
		cout << bot << endl;
	}
}