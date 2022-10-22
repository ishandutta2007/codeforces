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
#include <iomanip>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
long long painted[200000][10] = {};
long long top_counter = 0;
long long left_counter = 0;
int main() {
	long long n, m;
	scanf("%I64d%I64d", &n, &m);
	long long ans = n*n;
	REP(i, m) {
		long long a, b;
		scanf("%I64d%I64d", &a, &b);
		if (painted[a][0] == false) {
			painted[a][0] = true;
			left_counter++;
			ans -= n - top_counter;
		}
		if (painted[b][1] == false) {
			painted[b][1] = true;
			top_counter++;
			ans -= n - left_counter;
		}
		cout << ans << " ";
	}
	cout << endl;
	return 0;
	return 0;
}