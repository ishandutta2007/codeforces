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
	string s;
	cin >> s;
	int a=0, b =0;
	REP(i, s.length()) {
		if (s[i] == 'U') {
			a++;
		}
		else if (s[i] == 'D') {
			a--;
		}
		else if (s[i] == 'L') {
			b++;
		}
		else if (s[i] == 'R') {
			b--;
		}
	}
	int tmp = abs(a) + abs(b);
	if (tmp % 2 == 1) {
		cout << "-1" << endl;
		return 0;
	}
	cout << tmp / 2 << endl;
	return 0;
}