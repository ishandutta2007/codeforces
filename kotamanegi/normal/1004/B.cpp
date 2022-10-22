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
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*16
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> input;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		input.push_back(make_pair(a, b));
	}
	for (int i = 0; i < n; ++i) {
		cout << i % 2;
	}
	cout << endl;
	return 0;
}