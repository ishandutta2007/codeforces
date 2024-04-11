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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cstdint>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
long long hogee[10000000] = {};
int main() {
	long long n, k;
	scanf("%I64d%I64d", &n, &k);
	long long why_why = 0;
	REP(i, n) {
		scanf("%I64d", &hogee[i]);
		why_why += hogee[i];
	}
	if (n == 1) {
		cout << "0" << endl;
		return 0;
	}
	sort(hogee, hogee + n);
	long long rich_top = 999999999999999;
	long long poor_btm = -1;
	long long copy_k = k;
	long long loner = 0;
	for (int i = n -1;i >= 0;--i) {
		if (i != 0) {
			loner++;
			if (k >= (hogee[i] - hogee[i - 1])*loner) {
				k -= (hogee[i] - hogee[i - 1])*loner;
			}
			else {
				rich_top = hogee[i] - (int)(k / loner);
				goto wowok;
			}
		}
		else {
			rich_top = -1;
		}
	}
wowok:;
	k = copy_k;
	for (int i = 0;i < n;++i) {
		if (i != n - 1) {
			if (k >= (hogee[i + 1] - hogee[i])*(i + 1)) {
				k -= (hogee[i + 1] - hogee[i])*(i + 1);
			}
			else {
				poor_btm = hogee[i] + k / (i+1);
				goto asok;
			}
		}
		else {
			poor_btm = 999999999999999999;
		}
	}
asok:;
	if (why_why%n == 0) {
		cout << max((long long)0, rich_top - poor_btm) << endl;
	}
	else {
		cout << max((long long)1, rich_top - poor_btm) << endl;
	}
}