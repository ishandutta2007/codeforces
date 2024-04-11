#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <cassert>
#include <memory.h>
#include <deque>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"

const double EPS = 1e-9;
const int INF = 1011111111;
const int MD = 1000000000 + 7;
const double PI = acos(-1.0);
const int MAX_N = 1 << 17;

int n;


vector<int> graph[MAX_N];
vector<int> ans;

int used[MAX_N];

void dfs(int v) {
	used[v] = 1;
	for (int u : graph[v]) {
		if (used[u] == 0) {
			dfs(u);
		}
		else if (used[u] == 1) {
			cout << "-1\n";
			exit(0);
		}
	}
	ans.push_back(v);
	used[v] = 2;
}

void solve() {
	memset(used, 0, sizeof(used));
	ans.clear();
	int k;
	cin >> k;
	vector<int> requriedCourses(k);
	for (int& course : requriedCourses) {
		cin >> course;
	}
	for (int i = 1; i <= n; i++) {
		int sz;
		cin >> sz;
		graph[i].resize(sz);
		for (int& u : graph[i]) {
			cin >> u;
		}
	}
	for (int v : requriedCourses) {
		if (used[v] == 0) {
			dfs(v);
		}
	}
	cout << ans.size() << '\n';
	for (int v : ans) {
		cout << v << ' ';
	}
	cout << '\n';
}


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	bool needDelim = false;
		while (cin >> n) {
		if (needDelim) {
			cerr << "_______________\n";
		}
		solve();
		needDelim = true;
	}

	return 0;
}	

/*

*/