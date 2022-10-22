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
long long cnt[100];
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	REP(i, test_case) {
		long long k;
		cin >> k;
		int itring = 0;
		REP(i, 100) {
			cnt[i] = 0;
		}
		while (k != 0) {
			itring++;
			cnt[k % (itring + 1)]++;
			k /= (itring + 1);
		}
		long long ans = 1;
		long long cnter = 0;
		for (int i = itring; i >= 1; --i) {
			cnter++;
			REP(q, cnt[i]) {
				ans *= cnter;
				ans /= (q + 1);
				cnter--;
			}
		}
		cnter = -1;
		long long pre_ans = 1;
		for (int i = itring; i >= 1; --i) {
			cnter++;
			REP(q, cnt[i]) {
				pre_ans *= cnter;
				pre_ans /= (q + 1);
				cnter--;
			}
		}
		cout << ans-1LL - pre_ans<< endl;
	}

}