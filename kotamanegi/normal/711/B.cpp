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
#include <malloc.h>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
long long dp[1000][1000] = {};
long long foo[1000] = {};
bool check(long long n) {
	long long sum = 0;
	for (int i = 0;i < n;++i) {
		sum += dp[0][i];
	}
	for (int i = 0;i < n;++i) {
		long long hoge = 0;
		for (int q = 0;q < n;++q) {
			hoge += dp[i][q];
			if (dp[i][q] <= 0) return false;
		}
		if (hoge != sum) return false;
	}
	for (int i = 0;i < n;++i) {
		long long hoge = 0;
		for (int q = 0;q < n;++q) {
			hoge += dp[q][i];
			if (dp[q][i] <= 0) return false;
		}
		if (hoge != sum) return false;
	}
	long long tmp[2] = {};
	for (int i = 0;i < n;++i) {
		tmp[0] += dp[i][i];
		tmp[1] += dp[i][n - 1 - i];
	}
	if (tmp[0] != sum || tmp[1] != sum) return false;
	return true;
}
pair<int, int> whereis;
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1" << endl;
		return 0;
	}
	REP(i, n) {
		REP(q, n) {
			cin >> dp[i][q];
			foo[i] += dp[i][q];
			if (dp[i][q] == 0) {
				whereis = make_pair(i,q);
			}
		}
	}
	long long sum = 0;
	if (whereis.first == 0) {
		sum = foo[1];
	}
	else {
		sum = foo[0];
	}
	dp[whereis.first][whereis.second] = sum - foo[whereis.first];
	if (dp[whereis.first][whereis.second] <= 0) {
		cout << "-1" << endl;
		return 0;
	}
	if (check(n) == false) {
		cout << "-1" << endl;
		return 0;
	}
	else cout << dp[whereis.first][whereis.second] << endl;
	return 0;
}