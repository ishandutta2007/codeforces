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
#include <random>
#define EVAL 1
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 1048576
#define PI 3.1415926535
int main() {
	long long k, d, t;
	cin >> k >> d >> t;
	t *= 2;
	long long ans = 0;
	long long muda = d - (k%d);
	if (muda == d) {
		muda = 0;
	}
	long long timing = ((k + d - 1) / d) * d;
	long long each = 2 * (((k-1) / d)*d + d - muda) + muda;
	long long required_set = t / each;
	ans += (required_set * timing);
	t -= required_set * each;
	if (t <= 2 * k) {
		ans += (t / 2);
		cout << ans;
		if (t % 2 == 1) {
			cout << ".5"; 
		}
		cout << endl;
		return 0;
	}
	else {
		t -= 2*k;
		ans += (k + t);
		cout << ans << endl;
		return 0;
	}
}