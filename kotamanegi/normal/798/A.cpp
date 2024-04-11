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
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0;i < s.length() / 2;++i) {
		if (s[i] != s[s.length() - 1 - i]) cnt++;
	}
	if (cnt == 1||(cnt == 0&&s.length() % 2 == 1)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}