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
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
long long hoge[1000000] = {};
int main() {
#define int long long
	int n;
	cin >> n;
	if (n <= 20) {
		hoge[0] = 1;
		long long ans = 1;
		long long pre_ans = 1;
		for (int i = 0; i < n; ++i) {
			for (int q = 1000000; q >= 0; --q) {
				if (hoge[q] == 1) {
					ans += 1 - hoge[q + 4];
					ans += 1 - hoge[q + 9];
					ans += 1 - hoge[q + 49];
					hoge[q + 4] = 1;
					hoge[q + 9] = 1;
					hoge[q + 49] = 1;
				}
			}
		}
		cout << ans << endl;
	}
	else {
		long long hoge = 390;
		hoge += 49 * (n - 13LL);
		cout << hoge << endl;
	}
	return 0;
}