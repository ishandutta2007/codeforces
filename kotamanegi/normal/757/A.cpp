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
#define LONG_INF 100000000000000
map<char, int> hogee;
int main() {
	string s;
	cin >> s;
	REP(i, s.length()) {
		hogee[s[i]] += 1;
	}
	int ans = hogee['B'];
	ans = min(ans, hogee['b']);
	ans = min(ans, hogee['r']);
	ans = min(ans, hogee['u'] / 2);
	ans = min(ans, hogee['l']);
	ans = min(ans, hogee['s']);
	ans = min(ans, hogee['a'] / 2);
	cout << ans << endl;
	return 0;
}