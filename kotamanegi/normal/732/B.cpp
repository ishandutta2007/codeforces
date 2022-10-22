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
#define LONGINF 1000000000000000000
int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a;
	a.push_back(k);
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	a.push_back(k);
	int ans = 0;
	for (int i = 0;i < a.size() - 1;++i) {
		if (a[i] + a[i + 1] < k) {
			ans += k - a[i] - a[i + 1];
			a[i + 1] = k - a[i];
		}
	}
	cout << ans << endl;
	for (int i = 1;i < a.size() - 1;++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}