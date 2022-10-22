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
int minimum[400000];
int maximum[400000];
int taken[400000];
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int query;
	cin >> query;
	long long sizing = 0;
	REP(i, 400000) {
		minimum[i] = 1e8;
		maximum[i] = -1;
	}
	REP(tea, query) {
		int n;
		cin >> n;
		vector<int> inputs;
		REP(i, n) {
			int hoge;
			cin >> hoge;
			inputs.push_back(hoge);
		}
		for (int i = 0; i < n;++i) {
			minimum[inputs[i]] = min(minimum[inputs[i]], i);
			maximum[inputs[i]] = i;
		}
		vector<tuple<int, int, int>> going;
		for (int i = 0; i < n; ++i) {
			if (maximum[inputs[i]] != -1) {
				going.push_back(make_tuple(inputs[i], minimum[inputs[i]], maximum[inputs[i]]));
				minimum[inputs[i]] = 1e8;
				maximum[inputs[i]] = -1;
			}
		}
		sort(going.begin(), going.end());
		int ans = 1;
		int back = 0;
		for (int i = 1; i < going.size(); ++i) {
			if (get<1>(going[i]) < get<2>(going[i - 1])) {
				//bad
				ans = max(ans, i - back);
				back = i;
			}
		}
		ans = max(ans, (int)going.size() - back);
		cout << (int)going.size() - ans << endl;
	}
}