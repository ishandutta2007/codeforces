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
#define REP(i,n) for(int i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int cal[1000000] = {};
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int count_r = 0;
	int count_b = 0;
	REP(i, n) {
		if (s[i] == 'r') {
			cal[i] = 0;
			count_r++;
		}
		else {
			cal[i] = 1;
			count_b++;
		}
	}
	int ans = 10000000;
	int tmp_ans = 0;
	if (n % 2 == 1) {
		count_r--;
	}
	int need_change = (max(count_r,count_b)-min(count_r,count_b))/2;
	for (int i = 0;i < n;++i) {
		if (cal[i] != i % 2) {
			tmp_ans++;
		}
	}
	ans = min(ans, need_change + ((tmp_ans - need_change) / 2));
	if (n % 2 == 1) {
		count_r++;
		count_b--;
	}
	tmp_ans = 0;
	need_change = (max(count_r, count_b) - min(count_r, count_b)) / 2;
	for (int i = 0;i < n;++i) {
		if (cal[i] == i % 2) {
			tmp_ans++;
		}
	}
	ans = min(ans, need_change + ((tmp_ans - need_change)) / 2);
	cout << ans << endl;
	return 0;
}