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
long long neko[10000000] = {};
int main() {
	long long n;
	cin >> n;
	neko[1] = 2;
	neko[0] = 1;
	if (n == 2) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 2;i >= 0;++i) {
		neko[i] = neko[i - 1] + neko[i - 2];
		if (neko[i] > n) {
			cout << i - 1 << endl;
			return 0;
		}
	}
}