#define _CRT_SECURE_NO_WARNINGS
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
#define LONGINF 1000000000000000000
int main() {
	ios::sync_with_stdio(false);
	vector<long long> a;
	long long starting = 0;
	long long minni = -1;
	REP(i, 3) {
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
		if (a[i] > minni) {
			minni = a[i];
			starting = i;
		}
	}
	a[starting]--;
	for (int i = 0;i < 3;++i) {
		if (starting != i) {
			a[i] -= a[starting];
		}
	}
	long long ans = 0;
	for (int i = 0;i < 3;++i) {
		if (starting != i) {
			ans += max((long long)0, (long long)-1 * a[i]);
		}
	}
	cout << ans << endl;
	return 0;
}