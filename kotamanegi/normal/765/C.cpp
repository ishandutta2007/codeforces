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
#define LONG_INF 800000000000000000
int main() {
	long long k, a, b;
	cin >> k >> a >> b;
	if (a < b) swap(a, b);
	if (b < k) {
		if (a % k != 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	long long ans = a / k + b / k;
	cout << ans << endl;
	return 0;
}