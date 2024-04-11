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
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
long long cnt[200000];
long long sosuu[200000];
int main() {
#define int long long
	sosuu[1] = 1;
	for (int i = 2; i <= 100000; ++i) {
		if (sosuu[i] == 1) continue;
		for (int q = 2; i * q <= 100000; ++q) {
			sosuu[i * q] = 1;
		}
	}
	long long n, k;
	cin >> n >> k;
	long long ans = 0;
	REP(i, n){
		long long a = 0;
		cin >> a;
		for (long long i = 2; i <= 100000; ++i) {
			if (sosuu[i] == 1) continue;
			long long hoge = 1;
			REP(q, k) {
				hoge *= i;
				if (hoge > a) break;
			}
			if (hoge > a) break;
			while (a % hoge == 0) {
				a /= hoge;
			}
		}
		cnt[a]++;
	}
	for (long long i = 1; i <= 100000; ++i) {
		long long target = 1;
		long long now = i;
		for (long long q = 2; q <= sqrt(now); ++q) {
			if (sosuu[q] == 1) continue;
			int cnt = 0;
			while (now % q == 0) {
				now /= q;
				cnt++;
			}
			if (cnt != 0) {
				if (cnt >= k) {
					target = 200000;
					break;
				}
				cnt = k - cnt;
				REP(t, cnt) {
					if (target > 100000) break;
					target *= q;
				}
				if (target > 100000) break;
			}
		}
		if (now != 1) {
			REP(t, k-1) {
				if (target > 100000) break;
				target *= now;
			}
		}
		if (target <= 100000) {
			if (target == i) {
				ans += cnt[i] * (cnt[i] - 1LL);
			}
			else {
				ans += cnt[i] * cnt[target];
			}
		}
	}
	//waru 2
	cout << ans/2LL << endl;
}