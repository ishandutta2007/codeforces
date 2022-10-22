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
int main() {
	int n;
	cin >> n;
	vector<int> a;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	int ans = n - 2;
	for (int i = 1;i < n;++i) {
		if (a[i] != a[i - 1]) break;
		ans--;
	}
	for (int i = n - 2;i >= 0;--i) {
		if (a[i] != a[i + 1]) break;
		ans--;
	}
	cout << max(ans, 0) << endl;
	return 0;
}