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
#define LONG_INF 800000000000000000
int wooow[2000000] = {};
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> wow;
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		wow.push_back(make_pair(a, b));
	}
	REP(i, n) {
		cin >> wooow[i+1];
	}
	vector<pair<int, int>> ans;
	REP(i, n - 1) {
		if (wooow[wow[i].first] != wooow[wow[i].second]) {
			ans.push_back(make_pair(wow[i].first,wow[i].second));
		}
	}
	if (ans.size() == 0) {
		cout << "YES" << endl;
		cout << "1" << endl;
		return 0;
	}
	int aaa = ans[0].first;
	for (int i = 1;i < ans.size();++i) {
		if (ans[i].first != aaa&&ans[i].second != aaa) goto wa;
	}
	cout << "YES" << endl;
	cout << aaa << endl;
	return 0;
wa:;
	aaa = ans[0].second;
	for (int i = 1;i < ans.size();++i) {
		if (ans[i].first != aaa&&ans[i].second != aaa) goto failed;
	}
	cout << "YES" << endl;
	cout << aaa << endl;
	return 0;
failed:;
	cout << "NO" << endl;

	return 0;
}