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
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
#define int long long 
	int a, x, y;
	cin >> a >> x >> y;
	string s;
	cin >> s;
	int cnt = 0;
	if (s[s.length() - 1] == '0') {
		cnt++;
	}
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] != s[i - 1]) {
			if (s[i - 1] == '0') {
				cnt++;
			}
		}
	}
	if (cnt == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << min(x, y) * (cnt - 1LL) + y << endl;
	return 0;

}