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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <iomanip>
#include <cstdint>
#include <unordered_map>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
int main() {
	int n;
	cin >> n;
	int a[200] = {};
	REP(i, n) cin >> a[i];
	int max_small_dis = 0;
	int max_big_dis = 0;
	for (int i = 0;i < n;++i) {
		if (a[max_small_dis] > a[i]) {
			max_small_dis = i;
		}
		if (a[max_big_dis] < a[i]) {
			max_big_dis = i;
		}
	}
	if (max_big_dis < max_small_dis) swap(max_big_dis, max_small_dis);
	int ans = max(max_big_dis, n - max_small_dis-1);
	cout << ans << endl;
}