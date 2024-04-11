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
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int main(){
#define int long long
	int n;
	cin >> n;
	long long l;
	cin >> l;
	vector<long long> mew;
	for (int i = 0;i < n;++i) {
		long long a;
		cin >> a;
		mew.push_back(a);
	}
	for (int i = 0;i < n - 1;++i) {
		if (mew[i] * 2 < mew[i + 1]) {
			mew[i + 1] = mew[i] * 2;
		}
	}
	long long how = (1 << (n-1));
	long long ans = (long long)((l+how-1)/how) * mew[n-1];
	long long now = (l / how) * mew[n-1];
	l %= how;
	for (int i = n-1;i >= 0;--i) {
		long long litter = (1 << i);
		if (litter <= l) {
			l -= litter;
			now += mew[i];
		}
		if (l == 0) {
			ans = min(ans, now);
			break;
		}
		if (litter >= l) {
			ans = min(ans, now + mew[i]);
		}
	}
	cout << ans << endl;
	return 0;
}