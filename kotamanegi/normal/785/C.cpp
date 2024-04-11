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
#include <time.h>
#include <random>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
long long n, m;
int judge(long long mid) {
	long long ans = mid*(mid + (long long)1);
	ans /= 2;
	if (ans >= n) return true;
	return false;
}
int main() {
	cin >> n >> m;
	if (n <= m) {
		cout << n << endl;
		return 0;
	}
	n -= m;
	long long top = 2000000000;
	long long bot = 0;
	while (top - bot > 1) {
		long long mid = top + bot;
		mid /= 2;
		if (judge(mid)) {
			top = mid;
		}
		else bot = mid;
	}
	long long ans = 0;
	if (judge(top)) {
		ans = top;
	}
	else ans = bot;
	ans += m;
	cout << ans << endl;
	return 0;
}