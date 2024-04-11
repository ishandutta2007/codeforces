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
int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	int m, d;
	cin >> m >> d;
	int ans = 1;
	int hoge = days[m - 1];
	hoge -= (8 - d);
	if (hoge % 7 != 0) {
		ans++;
	}
	ans += hoge / 7;
	cout << ans << endl;
	return	0;
}