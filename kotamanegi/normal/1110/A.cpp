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
#define eps 0.000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*16
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int b, k;
	cin >> b >> k;
	long long geko = 0;
	REP(i, k) {
		long long a;
		cin >> a;
		if (i == k - 1) {
			geko += a;
		}
		else {
			if (b % 2 == 1) {
				geko += a;
			}
		}
	}
	if (geko % 2 == 0) {
		cout << "even" << endl;
	}
	else {
		cout << "odd" << endl;
	}

	return 0;
}