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
vector<pair<long double,long double>> input;
long double calculate(long double c) {
	long double ans = 0;
	REP(i, input.size()) {
		long double hoge = input[i].first - c;
		hoge *= hoge;
		hoge += input[i].second*input[i].second;
		hoge /= (long double)2.000000000000 * input[i].second;
		ans = max(ans, hoge);
	}
	return ans;
}
int main() {
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	REP(i, n) {
		long double a, b;
		cin >> a >> b;
		input.push_back(make_pair(a, b));
	}
	REP(i, n) {
		if (input[i].second * input[0].second < 0) {
			cout << "-1" << endl;
			return 0;
		}
	}
	if (input[0].second < 0) {
		REP(i, n) {
			input[i].second *= -1;;
		}
	}
	long double bot = -10000001;
	long double top = 10000001;
	REP(i, 150) {
		long double left_mid = (top + bot + bot) / (long double)3.000;
		long double right_mid = (top + top + bot) / (long double)3.000;
		long double left_value = calculate(left_mid);
		long double right_value = calculate(right_mid);
		if (left_value > right_value) {
			bot = left_mid;
		}
		else {
			top = right_mid;
		}
	}
	cout <<fixed << setprecision(15) << calculate(bot) << endl;
	return 0;
}