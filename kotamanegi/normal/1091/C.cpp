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
#define seg_size 65536*2
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin >> n;
	vector<long long> anss;
	vector<pair<long long,long long>> insuu;
	long long copy_n = n;
	long long geko = 1;
	for(long long i = 2;i <= sqrt(n);++i){
		int cnt = 0;
		while (copy_n % i == 0) {
			cnt++;
			copy_n /= i;
		}
		if (cnt != 0) {
			insuu.push_back(make_pair(i, cnt));
			geko *= (cnt+1LL);
		}
	}
	if (copy_n != 1) {
		insuu.push_back(make_pair(copy_n, 1));
		geko *= 2LL;
	}
	for (long long i = 0; i < geko; ++i) {
		long long bai = 1;
		long long nya = i;
		for (int q = 0; nya != 0; ++q) {
			long long geko = nya % (insuu[q].second+1LL);
			nya /= (insuu[q].second+1LL);
			REP(j, geko) {
				bai *= insuu[q].first;
			}
		}
		long long kou = n / bai - 1;
		long long ans = kou+1LL;
		ans += bai * kou * (kou * 1 + 1LL) / 2LL;
		anss.push_back(ans);
	}
	sort(anss.begin(), anss.end());
	REP(i, anss.size()) {
		cout << anss[i] << " ";
	}
	cout << endl;
	return 0;
}