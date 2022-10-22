#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <iomanip>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	int n;
	scanf("%d", &n);
	int m[100], r[100];
	REP(i, n) scanf("%d", &m[i]);
	REP(i, n) scanf("%d", &r[i]);
	double me = 0;
	double teammate = 0;
	for (int i = 0;i <= 10000000;++i) {
		for (int q = 0;q < n;++q) {
			if (i % m[q] == r[q]) {
				me++;
				goto ok;
			}
		}
		teammate++;
	ok:;
	}
	cout << fixed << setprecision(10) << me / (teammate + me) << endl;
}