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
int cnt[10] = {};
int hoge_cnt[10] = {};
int main() {
	int n;
	cin >> n;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
		hoge_cnt[tmp]++;
	}
	REP(q, n) {
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
	}
	int ans = 0;
	for (int i = 1;i <= 5;++i) {
		if (cnt[i] % 2 == 1) {
			cout << -1 << endl;
			return 0;
		}
		ans += abs((cnt[i] / 2) - hoge_cnt[i]);
	}
	cout << ans / 2 << endl;
	return 0;
}