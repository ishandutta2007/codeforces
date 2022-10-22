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
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> input;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		input.push_back(make_pair(a, b));
	}
	int k = 0;
	cin >> k;
	for (int i = 0; i < input.size(); ++i) {
		if (input[i].first <= k && k <= input[i].second) {
			cout << input.size() - i << endl;
			return 0;
		}
	}
}