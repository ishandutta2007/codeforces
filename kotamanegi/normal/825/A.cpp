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
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	long long ans = 0;
	long long mul = 1;
	long long cnt = 0;
	for (int i = n - 1;i >= 0;--i) {
		if (s[i] == '0') {
			ans += cnt*mul;
			mul *= 10;
			cnt = 0;
		}else{
			cnt++;
		}
	}
	cout << ans+cnt*mul << endl;
	return 0;
}