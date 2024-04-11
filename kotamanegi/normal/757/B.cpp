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
map<int, int> hogee;
int sosuu[300000] = {};
int main() {
	int n;
	cin >> n;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		hogee[tmp]++;
	}
	int ans = 1;
	for (int i = 2;i <= 100000;++i) {
		if (sosuu[i] == false) {
			int cnt = 0;
			for (int q = 1;q <= 100000 / i + 1;++q) {
				sosuu[i*q] = true;
				cnt += hogee[i*q];
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans << endl;
	return 0;
}