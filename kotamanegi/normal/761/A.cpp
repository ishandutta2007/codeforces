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
#define LONG_INF 800000000000000000
int main() {
	int a, b;
	cin >> a >> b;
	if (a + b == 0) {
		cout << "NO" << endl;
		return 0;
	}
	if (abs(a - b) <= 1) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0;
}