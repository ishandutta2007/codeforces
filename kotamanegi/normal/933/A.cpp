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
#include <cstdlib>
#define EVAL 1
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
#define PI 3.1415926535
int pre_ans[10000] = {};
int pre_go[10000] = {};
int main() {
	int n;
	cin >> n;
	vector<int> a;
	srand(time(NULL));
	REP(i, n) {
		int b;
		cin >> b;
		a.push_back(b);
	}
	cout << endl;
	for (int i = 1;i <= a.size();++i) {
		if (a[i-1] == 1) {
			pre_ans[i]++;
		}
		if (i != 0) {
			pre_ans[i] += pre_ans[i - 1];
		}
	}
	for (int i = a.size() - 1;i >= 0;--i) {
		if (a[i] == 2) {
			pre_go[i]++;
		}
		pre_go[i] += pre_go[i + 1];
	}
	long long ans = 0;
	for (int i = 0;i < n;++i) {
		long long basing = pre_ans[i];
		long long cnt = 0;
		long long sure_num_one = 0;
		long long sure_num_two = 0;
		long long num_one = 0;
		long long num_two = 0;
		for (int q = i;q < n;++q) {
			if (a[q] == 1) {
				num_one++;
			}
			else {
				num_two++;
			}
			if (num_two - num_one > cnt) {
				cnt = num_two - num_one;
				sure_num_one = num_one;
				sure_num_two = num_two;
			}
			ans = max(ans, basing + pre_go[q + 1] + sure_num_two + num_one - sure_num_one);
		}
	}
	cout << ans << endl;
	return 0;
}