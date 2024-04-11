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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
int main() {
#define int long long
	int n, l, a;
	cin >> n >> l >> a;
	vector<pair<long long, long long>> input;
	input.push_back(make_pair(0, 0));
	REP(i, n) {
		long long a, b;
		cin >> a >> b;
		input.push_back(make_pair(a, b));
	}
	input.push_back(make_pair(l, 0));
	long long ans = 0;
	for (int i = 0; i <= n; ++i) {
		long long geko = input[i + 1].first - (input[i].first + input[i].second);
		ans += geko / a;
	}
	cout << ans << endl;
	return 0;
}