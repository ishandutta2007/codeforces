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
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
string s;
int zero[300000];
int one[300000];
int visited[300000];
int next_zero(int now) {
	if (now >= s.length()) return -1;
	else if (zero[now] == now) return now;
	return zero[now] = next_zero(zero[now]);
}
int next_one(int now) {
	if (now >= s.length()) return -1;
	else if (one[now] == now) return now;
	return one[now] = next_one(one[now]);
}
vector<int> solve() {
	vector<int> ans;
	int hoge = next_zero(0);
	if (hoge == -1) return ans;
	ans.push_back(hoge);
	visited[hoge] = 1;
	zero[hoge] = hoge + 1;
	while (true) {
		int hoo = next_one(hoge);
		if (hoo == -1) return ans;
		int popo = next_zero(hoo);
		if (popo == -1) return ans;
		ans.push_back(hoo);
		ans.push_back(popo);
		one[hoo] = hoo + 1;
		zero[popo] = popo + 1;
		visited[hoo] = 1;
		visited[popo] = 1;
		hoge = popo;
	}
}
int main() {
	cin >> s;
	vector<vector<int>> ans;
	for (int i = 0; i < s.length(); ++i) {
		zero[i] = i + 1;
		one[i] = i + 1;
		if (s[i] == '0') {
			zero[i] = i;
		}
		else {
			one[i] = i;
		}
	}
	while (true) {
		vector<int> hoge = solve();
		if (hoge.size() == 0) break;
		ans.push_back(hoge);
	}
	for (int i = 0; i < s.length(); ++i) {
		if (visited[i] == false) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans.size() << endl;
	REP(i, ans.size()) {
		cout << ans[i].size();
		for (int q = 0; q < ans[i].size(); ++q) {
			cout << " " << ans[i][q]+1;
		}
		cout << endl;
	}
	return 0;
}