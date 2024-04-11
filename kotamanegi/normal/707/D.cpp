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
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
int datas[3000][3000] = {};
int data_reverse[3000] = {};
int n, m, q;
vector<int> go_to[300000] = {};
int separated_ans[3000] = {};
int total_nowans = 0;
int ans[300000] = {};
bool was_exec[300000] = {};
vector<tuple<int, int, int>> asks;
void go_back(int a) {
	for (int i = a;i >= 0;--i) {
			int force = get<0>(asks[i]);
			int from = get<1>(asks[i]);
			int to = get<2>(asks[i]);
			if (force == 2) {
				if (was_exec[i] == true) {
					datas[from][to] = (datas[from][to] + 1) % 2;
					total_nowans++;
					separated_ans[from]++;
				}
			}
			if (force == 1) {
				if (was_exec[i] == true) {
					datas[from][to] = (datas[from][to] + 1) % 2;
					total_nowans--;
					separated_ans[from]--;
				}
			}
			if (force == 3) {//always execute
				total_nowans -= separated_ans[from];
				separated_ans[from] = m - separated_ans[from];
				total_nowans += separated_ans[from];
				data_reverse[from] = (data_reverse[from] + 1) % 2;
			}
			if (force == 4||force == -1) return;
		//if force == 4,do nothing since teleported
	}
}
void solve(int a) {
	for (int i = a;i >= 0;++i) {
			int force = get<0>(asks[i]);
			if (i != a&&force == 4) {
				go_back(i - 1);
				return;
			}
			int from = get<1>(asks[i]);
			int to = get<2>(asks[i]);
			if (force == 1) {
				if (datas[from][to] == data_reverse[from]) {
					datas[from][to] = (datas[from][to] + 1) % 2;
					total_nowans++;
					separated_ans[from]++;
					was_exec[i] = true;
				}
			}
			if (force == 2) {
				if (datas[from][to] != data_reverse[from]) {
					datas[from][to] = (datas[from][to] + 1) % 2;
					total_nowans--;
					separated_ans[from]--;
					was_exec[i] = true;
				}
			}
			if (force == 3) {
				total_nowans -= separated_ans[from];
				separated_ans[from] = m - separated_ans[from];
				total_nowans += separated_ans[from];
				data_reverse[from] = (data_reverse[from] + 1) % 2;
				was_exec[i] = true;
			}
			//if force == 4,do nothing since teleported
		for (int q = 0;q < go_to[i].size();++q) {
			solve(go_to[i][q]);
		}
		ans[i] = total_nowans;
	}
	return;
}
int main() {
	cin >> n >> m >> q;
	asks.push_back(make_tuple(-1, -1, -1));
	REP(i, q) {
		int a,b,c;
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			asks.push_back(make_tuple(a, b, c));
		}
		if (a == 2) {
			cin >> c;
			asks.push_back(make_tuple(a, b, c));
		}
		if (a == 3) {
			asks.push_back(make_tuple(a, b, -1));
		}
		if (a == 4) {
			asks.push_back(make_tuple(a, b, -1));
			go_to[b].push_back(i+1);
		}
	}
	asks.push_back(make_tuple(4, 4, 4));
	solve(0);
	for (int i = 1;i <= q;++i) {
		cout << ans[i] << endl;
	}
	return 0;
}