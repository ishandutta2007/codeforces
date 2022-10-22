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
	int n, k;
	cin >> n >> k;
	if (n == 2 || n == 3) {
		cout << -1 << endl;
		return 0;
	}
	if (n == 4) {
		if (k == 3) {
			cout << "3" << endl;
			cout << "1 2" << endl;
			cout << "2 3" << endl;
			cout << "3 4" << endl;
			return 0;
		}
		cout << -1 << endl;
		return 0;
	}
	if (k == 2) {
		cout << n - 1 << endl;
		for (int i = 1;i < n;++i) {
			cout << i << " " << i + 1 << endl;
		}
		return 0;
	}
	else if(k == 3) {
		cout << n-1 << endl;
		cout << "1 2" << endl;
		cout << "2 3" << endl;
		for (int i = 4;i <= n;++i) {
			cout << "3 " << i << endl;
		}
		return 0;
	}
	cout << -1 << endl;
	return 0;
}