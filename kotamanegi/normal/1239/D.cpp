//J^!w

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
#include <random>
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
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
vector<int> vertexs[2000000], gyaku[2000000];
int visited[2000000];
stack<int> visitings;
void dfs(int now) {
	visited[now] = 1;
	REP(i, vertexs[now].size()) {
		int go = vertexs[now][i];
		if (visited[go]) continue;
		dfs(go);
	}
	visitings.push(now);
}
void gyaku_dfs(int now) {
	visited[now] = 1;
	REP(i, gyaku[now].size()) {
		int go = gyaku[now][i];
		if (visited[go]) continue;
		gyaku_dfs(go);
	}
	visitings.push(now);
}
int main() {
	iostream::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	REP(i, test_case) {
		int n, m;
		cin >> n >> m;
		REP(i, n) {
			vertexs[i].clear();
			gyaku[i].clear();
			visited[i] = 0;
		}
		REP(i, m) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			if (a != b) {
				vertexs[a].push_back(b);
				gyaku[b].push_back(a);
			}
		}
		REP(i, n) {
			if (visited[i] == 0) {
				dfs(i);
			}
		}
		int nya = visitings.top();
		while (visitings.empty() == false) visitings.pop();
		REP(i, n) {
			visited[i] = 0;
		}
		gyaku_dfs(nya);
		vector<int> humans;
		while (visitings.empty() == false) {
			humans.push_back(visitings.top());
			visitings.pop();
		}
		if (humans.size() == n) {
			cout << "No" << endl;
		}
		else {
			sort(humans.begin(), humans.end());
			cout << "Yes" << endl;
			cout << n - humans.size() << " " << humans.size() << endl;
			REP(i, n) {
				if (visited[i] == 0) {
					cout << i+1 << " ";
				}
			}
			cout << endl;
			REP(i, humans.size()) {
				if (i != 0) cout << " ";
				cout << humans[i] + 1;
			}
			cout << endl;
		}
	}
}