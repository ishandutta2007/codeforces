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
	int n;
	cin >> n;
	int copy_n = n;
	int cnt = 0;
	while (n >= 0) {
		cnt++;
		n -= cnt;
	}
	cout << cnt - 1 << endl;
	for (int i = 1;i < cnt - 1;++i) {
		cout << i << " ";
		copy_n -= i;
	}
	cout << copy_n << endl;
	return 0;
}