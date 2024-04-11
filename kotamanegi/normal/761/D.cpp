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
int main() {
#define int long long
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a, p;
	REP(i, n) {
		int b;
		cin >> b;
		a.push_back(b);
	}
	REP(i, n) {
		int b;
		cin >> b;
		p.push_back(b);
	}
	vector<tuple<int, int,int>> wow;
	for (int i = 0;i < n;++i) {
		wow.push_back(make_tuple(p[i],a[i],i));
	}
	sort(wow.begin(), wow.end());
	vector<pair<int, int>> ans;
	ans.push_back(make_pair(get<2>(wow[0]), l - get<1>(wow[0])));
	for (int i = 1;i < n;++i) {
		if (r - get<1>(wow[i]) <= ans[i-1].second) {
			cout << -1 << endl;
			return 0;
		}else if(l - get<1>(wow[i]) > ans[i-1].second){
			ans.push_back(make_pair(get<2>(wow[i]), l - get<1>(wow[i])));
		}
		else {
			ans.push_back(make_pair(get<2>(wow[i]), ans[i - 1].second + 1));
		}
	}
	sort(ans.begin(), ans.end());
	vector<int> checker;
	for (int i = 0;i < n;++i) {
		int true_value = ans[i].second + a[i];
		if (true_value - ans[i].second < l || true_value - ans[i].second > r) {
			cout << -1 << endl;
			return 0;
		}
		else checker.push_back(true_value);
	}
	REP(i, n) {
		cout << checker[i] << " ";
	}
	cout << endl;
	return 0;
}