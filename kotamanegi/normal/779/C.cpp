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
int a[1000000] = {}, b[1000000] = {};
int main() {
	int n, k;
	cin >> n >> k;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a[i]=tmp;
	}
	REP(i, n) {
		int tmp;
		cin >> tmp;
		b[i] = tmp;
	}
	vector<pair<int, int>> wow;
	for (int i = 0;i < n;++i) {
		wow.push_back(make_pair(a[i] - b[i],i));
	}
	sort(wow.begin(), wow.end());
	int ans = 0;
	int now = 0;
	while (now != n) {
		if (wow[now].first > 0) break;
		ans += a[wow[now].second];
		now++;
	}
	while (now < k) {
		ans += a[wow[now].second];
		now++;
	}
	for (int i = now;i < n;++i) {
		ans += b[wow[i].second];
	}
	cout << ans << endl;
	return 0;
}