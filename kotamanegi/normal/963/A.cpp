#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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
#include <map>
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
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.0000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000009LL//1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
using namespace std;
long long multi(long long a, long long b) {
	long long ans = 1;
	while (b != 0) {
		if (b % 2 == 1) {
			ans *= a;
			ans %= MAX_MOD;
		}
		a *= a;
		a %= MAX_MOD;
		b /= 2;
	}
	return ans;
}
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	string s;
	cin >> s;
	long long begin_sum = 0;
	long long hoge = multi(a, n);
	hoge %= MAX_MOD;
	long long bobo = multi(a, MAX_MOD - 2);
	for (int i = 0; i < k; ++i) {
		if (s[i] == '+') {
			begin_sum += hoge;
		}
		else {
			begin_sum -= hoge;
		}
		begin_sum += MAX_MOD;
		begin_sum %= MAX_MOD;
		hoge *= bobo;
		hoge %= MAX_MOD;
		hoge *= b;
		hoge %= MAX_MOD;
	}
	long long geko = multi(bobo,k);
	geko *= multi(b, k);
	geko %= MAX_MOD;
	if (geko == 1) {
		long long ans = ((n+1LL) / k);
		ans *= begin_sum;
		ans %= MAX_MOD;
		ans += (long long)(abs(ans) / MAX_MOD + 1LL) * MAX_MOD;
		ans %= MAX_MOD;
		cout << ans << endl;
		return 0;
	}
	else {
		long long bunbo = geko - 1LL;
		bunbo += MAX_MOD;
		bunbo %= MAX_MOD;
		long long bunsi = multi(geko, (n+1) / k) - 1LL;
		bunsi += MAX_MOD;
		bunsi %= MAX_MOD;
		bunsi *= begin_sum;
		bunsi %= MAX_MOD;
		long long ans = bunsi * multi(bunbo, MAX_MOD - 2);
		ans %= MAX_MOD;
		cout << ans << endl;
		return 0;
	}
	return 0;
}