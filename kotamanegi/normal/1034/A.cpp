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
int inputs[400000];
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &inputs[i]);
	}
	int ans = n;
	for (int i = 2; i <= sqrt(15000000); ++i) {
		int ok = 1;
		for (int q = 2; q * q <= i; ++q) {
			if (i % q == 0) ok = 0;
		}
		if (ok == 0) continue;
		int now = 32;
		int cnt = 0;
		REP(q, n) {
			int tmp = 0;
			while (inputs[q] % i == 0) {
				inputs[q] /= i;
				tmp++;
			}
			if (now == tmp) {
				cnt++;
			}
			else if (now > tmp) {
				now = tmp;
				cnt = 1;
			}
		}
		ans = min(ans, cnt);
	}
	map<int, int> hoge;
	REP(i, n) {
		if (inputs[i] == 1) continue;
		hoge[inputs[i]]++;
	}
	for (auto i = hoge.begin(); i != hoge.end(); ++i) {
		if(i ->second != n)
		ans = min(ans, n - i->second);
	}
	if (ans == n) ans = -1;
	printf("%d\n", ans);
}