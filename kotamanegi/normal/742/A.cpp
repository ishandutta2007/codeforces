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
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 1000000000000
int main() {
	long long n;
	cin >> n;
	long long ans = 1;
	long long wow = 8;
	while (n != 0) {
		if (n % 2 == 1) {
			ans *= wow;
			ans %= 10;
		}
		n /= 2;
		wow *= wow;
		wow %= 10;
	}
	cout << ans << endl;
	return 0;
}