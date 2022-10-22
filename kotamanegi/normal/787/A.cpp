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
int counter[300000] = {};
int main() {
	int a, b, c, d;
	cin >> c >> a >> d >> b;
	for (int i = 0;a + c*i < 250000;++i) {
		counter[a + c*i] = true;
	}
	for (int i = 0;b + d*i < 250000;++i) {
		if (counter[b + d*i] == true) {
			cout << b + d*i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}