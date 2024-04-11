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
#define REP(i,n) for(int i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int main() {
	int n;
	scanf("%d", &n);
	long long t = 2;
	for (long long i = 1;i <= n;++i) {
		long long pre_i = i;
		long long after = 1;
		for (long long q = 2;q <= 200;++q) {
			if (pre_i % (q*q) == 0) {
				pre_i /= (q*q);
				after *= q;
				q--;
			}
		}
		long long ans = (i+1)*(i+1)*pre_i;
		ans -= t;
		cout << ans << endl;
		t = after*pre_i;
	}
	return 0;
}