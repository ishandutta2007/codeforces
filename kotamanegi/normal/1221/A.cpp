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
int main(){
	int query;
	cin >> query;
	REP(i, query) {
		int n;
		cin >> n;
		int cnt[70] = {};
		REP(q, n) {
			int a;
			cin >> a;
			for (int j = 0; j < 65; ++j) {
				if (1 << j == a) {
					cnt[j]++;
					break;
				}
			}
		}
		for (int j = 0;; ++j) {
			if (1 << j == 2048) {
				if (cnt[j]) {
					cout << "YES" << endl;
				}
				else {
					cout << "NO" << endl;
				}
				break;
			}
			cnt[j + 1] += cnt[j] / 2;
		}
	}
}