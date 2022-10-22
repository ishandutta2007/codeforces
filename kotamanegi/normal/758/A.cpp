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
	long long n;
	cin >> n;
	vector<long long> hoge;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		hoge.push_back(tmp);
	}
	sort(hoge.begin(), hoge.end(),greater<long long>());
	long long ans = 0;
	for (int i = 1;i < hoge.size();++i) {
		ans += hoge[0] - hoge[i];
	}
	cout << ans << endl;
	return 0;
}