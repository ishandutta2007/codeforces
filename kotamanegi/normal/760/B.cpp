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
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 8000000000000000000
long long n, m, k;
long long fomula(long long a, long long b) {
	long long hoge = b*(b + 1);
	hoge /= 2;
	long long tmp = a*(a - 1);
	tmp /= 2;
	hoge -= tmp;
	return hoge;
}
long long solve(long long a) {
	long long hoge = m;
	hoge += a;
	hoge -= fomula(max((long long)0, a - k + 1), a);
	hoge -= fomula(max((long long)0, a - n + k), a);
	if (hoge >= 0) return true;
	else return false;
}
int main() {
	cin >> n >> m >> k;
	m -= n;
	long long top = m;
	long long bot = 0;
	while (top - bot > 1) {
		long long mid = top + bot;
		mid /= 2;
		if (solve(mid)) {
			bot = mid;
		}
		else top = mid;
	}
	if (solve(top)) {
		cout << top + 1 << endl;
	}
	else {
		cout << bot + 1 << endl;
	}
	return 0;
}