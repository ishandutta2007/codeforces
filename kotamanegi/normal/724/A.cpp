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
string wow[7] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
int cnt[11] = { 3,0,3,2,3,2,3,3,2,3,2};
map<string, int> hoge;
int dp[100][1000] = {};
int main() {
	string a,b;
	cin >> a >> b;
	for (int i = 0;i < 7;++i) {
		hoge[wow[i]] = i;
	}
	int ans = (hoge[b]+7) - hoge[a];
	ans %= 7;
	for (int i = 0;i < 11;++i) {
		if (cnt[i] == ans) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
	cout << "NO" << endl;
	return 0;
}