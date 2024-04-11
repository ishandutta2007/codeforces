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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	long long ans = 0;
	string s;
	cin >> s;
	long long cnt = 0;
	for (int i = s.length() - 1;i >= 0;--i) {
		if (s[i] == 'b') {
			cnt++;
			cnt %= MAX_MOD;
		}
		else {
			ans += cnt;
			ans %= MAX_MOD;
			cnt *= 2;
			cnt %= MAX_MOD;
		}
	}
	cout << ans << endl;
	return 0;
}