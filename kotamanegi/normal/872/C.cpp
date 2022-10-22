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
#define eps 0.00000000000000000000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)                                                                             
#define seg_size 524288
long long cnt[10000] = {};
int main() {
#define int long long
	int query;
	cin >> query;
	cnt[0] = 0;
	for (int i = 1;i <= 100;++i) {
		cnt[i] = -1;
	}
	for (int i = 4;i <= 99;++i) {
		for (int q = 2;q <= sqrt(i);++q) {
			if (i % q == 0) {
				for (int j = 100;j >= i;--j) {
					if (cnt[j - i] != -1) {
						cnt[j] = max(cnt[j], cnt[j - i] + 1);
					}
				}
				break;
			}
		}
	}
	REP(que, query) {
		long long tmp;
		cin >> tmp;
		long long ans = tmp / 4+1;
		long long geko = tmp % 4;
		long long nya = -1;
		for (int i = 0;i * 4 + geko <= 100&&i*4+geko <= tmp;++i) {
			ans--;
			if (cnt[i * 4 + geko] != -1) {
				nya = max(nya, cnt[i * 4 + geko] + ans);
			}
		}
		cout << nya << endl;
	}
	return 0;
}