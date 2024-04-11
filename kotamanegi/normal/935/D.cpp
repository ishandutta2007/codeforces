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
#define eps 0.000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 1048576
#define PI 3.1415926535
long long gyaku(long long now) {
	long long ans = 1;
	long long cnt = MAX_MOD - 2;
	while (cnt != 0) {
		if (cnt % 2 == 1) {
			ans *= now;
			ans %= MAX_MOD;
		}
		now *= now;
		now %= MAX_MOD;
		cnt /= 2;
	}
	return ans;
}
int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> a, b;
	long long bunbo = 1;
	REP(i, n) {
		long long tmp;
		cin >> tmp;
		if (tmp == 0) {
			bunbo *= m;
			bunbo %= MAX_MOD;
		}
		a.push_back(tmp);
	}
	REP(i, n) {
		long long tmp;
		cin >> tmp;
		if (tmp == 0) {
			bunbo *= m;
			bunbo %= MAX_MOD;
		}
		b.push_back(tmp);
	}
	long long bunsi = 0;
	long long calc = bunbo;
	for (int i = 0;i < n;++i) {
		if (a[i] == 0 || b[i] == 0) {
			if (a[i] == 0 && b[i] == 0) {
				calc *= gyaku(m);
				calc %= MAX_MOD;
				calc *= gyaku(m);
				calc %= MAX_MOD;
				long long pepe = m*(m - 1LL);
				pepe /= 2LL;
				bunsi += pepe * calc;
				bunsi %= MAX_MOD;
				calc *= m;
				calc %= MAX_MOD;
			}
			else if (a[i] == 0) {
				calc *= gyaku(m);
				calc %= MAX_MOD;
				bunsi += calc * (m - b[i]);
				bunsi %= MAX_MOD;
			}else if(b[i] == 0){
				calc *= gyaku(m);
				calc %= MAX_MOD;
				bunsi += calc*(a[i] - 1LL);
				bunsi %= MAX_MOD;
			}
		}
		else {
			if (a[i] > b[i]) {
				bunsi += calc;
				break;
			}
			else if (a[i] < b[i]) {
				break;
			}
		}
	}
	cout << (bunsi * gyaku(bunbo)) % MAX_MOD << endl;
	return 0;
}