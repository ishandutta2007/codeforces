#define _CRT_SECUintRE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
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
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*2
#define REP(i,n) for(long long i = 0;i < n;++i)
unsigned long xor128(void)
{
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t;
	t = (x ^ (x << 11)); x = y; y = z; z = w; return(w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
int main() {
	long long n;
	cin >> n;
	vector<long long> input;
	long long nya = 0;
	REP(i, n) {
		long long tmp;
		cin >> tmp;
		nya += tmp;
		input.push_back(tmp);
	}
	long long cnt = 0;
	long long bobo = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (input[i] / 2LL <= nya - input[i] / 2LL * 2LL) {
			//ok to go
			cnt += input[i] / 2LL;
			nya -= input[i] / 2LL * 2LL;
			nya -= input[i] / 2LL;
			if (input[i] % 2 == 1) {
				if (bobo == cnt) {
					nya--;
				}
				else {
					bobo++;
				}
			}
		}
		else {
			//not allowed!
			cnt += nya / 3LL;
			cout << cnt << endl;
			return 0;
		}
	}
	cout << cnt << endl;
	return 0;
}