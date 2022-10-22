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
int main() {
	long long n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	if (s[a - 1] == s[b - 1]) {
		cout << 0 << endl;
		return 0;
	}
	else {
		for (int i = 1;i >= 0;++i) {
			if (i + b < n) {
				if (s[i + b] != s[a - 1]) {
					cout << i << endl;
					return 0;
				}
			}
			if (b - i >= 0) {
				if (s[b - i] != s[a - 1]) {
					cout << i << endl;
					return 0;
				}
			}
		}
	}
}