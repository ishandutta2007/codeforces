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
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	int n;
	cin >> n;
	vector<int> hoge;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		hoge.push_back(tmp);
	}
	int nya = gcd(hoge[0], hoge[1]);
	for (int i = 2;i < n;++i) {
		nya = gcd(nya, hoge[i]);
	}
	if (nya >= 2) {
		cout << "YES" << endl;
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 0;i < n - 1;++i) {
		if (hoge[i] % 2 == 1) {
			ans++;
			if (hoge[i + 1] % 2 == 0) ans++;
			hoge[i] = 2;
			hoge[i + 1] = 2;
		}
	}
	if (hoge[n - 1] % 2 == 1) ans += 2;
	cout << "YES" << endl;
	cout << ans << endl;
	return 0;
}