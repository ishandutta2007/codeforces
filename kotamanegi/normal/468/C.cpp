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
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
long long a;
long long calc(long long now) {
	long long cnt[20] = {};
	long long te = now;
	for (int i = 19; i >= 0; --i) {
		cnt[i] = te % 10;
		te /= 10;
	}
	long long ans = 0;
	for (int i = 2; i < 20; ++i) {
		long long now_going = 1;
		for (int q = i + 1; q < 20; ++q) {
			now_going *= 10;
		}
		if (cnt[i] != 0) {
			for (long long j = 0; j < cnt[i]; ++j) {
				ans += j * now_going;
				if (ans > a) return ans;
			}
			long long tmp = now_going / 10 * cnt[i];
			for (long long j = i+1; j < 20; ++j) {
				ans += 45LL * tmp;
				if (ans > a) return ans;
			}
		}
		ans += cnt[i] * (now % now_going + 1LL);
		if (ans > a) return ans;
	}
	return ans;
}
long long calc_bo(long long now) {
	long long ans = 0;
	while (now != 0) {
		ans += now % 10;
		now /= 10;
	}
	return ans;
}
int main() {
	cin >> a;
	long long top = a+1;
	long long bot = 1;
	while (llabs(bot - top) > 1) {
		long long mid = (top + bot) / 2;
		if (calc(mid) <= a) {
			bot = mid;
		}
		else {
			top = mid;
		}
	}
	long long tmp_cnt = calc(bot);
	long long back = 1;
	for (long long q = bot + 1;; ++q) {
		while (tmp_cnt > a) {
			tmp_cnt -= calc_bo(back);
			back++;
		}
		if (tmp_cnt == a) {
			cout << back << " " << q-1LL << endl;
			return 0;
		}
		tmp_cnt += calc_bo(q);
	}
}