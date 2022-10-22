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
#include <cassert>
#include<fstream>
#include <cstdlib>
#define EVAL 1
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 1048576
#define PI 3.1415926535
int main() {
	long long n;
	cin >> n;
	long long ans = 0;
	for (int i = 1;i <= n / 2;++i) {
		if ((n - i) % i == 0) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}