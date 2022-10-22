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
using namespace std;
#define eps 0.00000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
vector<pair<int,int>> vertex[400000];
int used[400000] = {};
int degree[400000] = {};
int visited[400000] = {};
int solve(int now) {
	if (degree[now] != -1) {
		int hoge = degree[now];
		int gogo = -1;
		for (int i = 0;i < vertex[now].size();++i) {
			if (visited[vertex[now][i].first] == 0) {
				visited[vertex[now][i].first] = true;
				int nya = solve(vertex[now][i].first);
				if (nya == -1) {
					gogo = vertex[now][i].second;
				}
				else if (nya == 1){
					used[vertex[now][i].second] = 1;
					hoge++;
				}
			}
		}
		if (hoge % 2 == 0) {
			return 0;
		}
		else if (gogo == -1) {
			return 1;
		}
		else {
			used[gogo] = 1;
			return 0;
		}
	}
	else {
		for (int i = 0;i < vertex[now].size();++i) {
			if (visited[vertex[now][i].first] == 0) {
				visited[vertex[now][i].first] = true;
				int nya = solve(vertex[now][i].first);
				if (nya == 1) {
					used[vertex[now][i].second] = 1;
				}
			}
		}
		return -1;
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, n) {
		scanf("%d", &degree[i + 1]);
	}
	REP(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		vertex[a].push_back(make_pair(b,i));
		vertex[b].push_back(make_pair(a,i));
	}
	int a = 0;
	for (int i = 1;i <= n;++i) {
		if (degree[i] == -1) {
			visited[i] = true;
			a = solve(i);
			goto ok;
		}
	}
	visited[1] = true;
	a = solve(1);
ok:;
	if (a == 1) {
		cout << -1 << endl;
	}
	else {
		int cnt = 0;
		for (int i = 0;i < m;++i) {
			cnt += used[i];
		}
		cout << cnt << endl;
		for (int i = 0;i < m;++i) {
			if (used[i]) {
				cout << i+1 << " ";
			}
		}
		cout << endl;
	}
	return 0;
}