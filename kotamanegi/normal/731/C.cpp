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
int color[300000] = {};
vector<int> graph[300000];
int visited[300000] = {};
int main() {
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	REP(i, n) {
		cin >> color[i];
	}
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1;i <= n;++i) {
		if (visited[i] == false) {
			visited[i] = true;
			vector<int> visit;
			visit.push_back(i);
			queue<int> go;
			go.push(i);
			while (go.empty() == false) {
				int hoge = go.front();go.pop();
				REP(i, graph[hoge].size()) {
					if (visited[graph[hoge][i]] == false) {
						visited[graph[hoge][i]] = true;
						visit.push_back(graph[hoge][i]);
						go.push(graph[hoge][i]);
					}
				}
			}
			map<int, int> wombo;
			int now_max = 0;
			for (int i = 0;i < visit.size();++i) {
				wombo[color[visit[i]-1]]++;
				now_max = max(now_max, wombo[color[visit[i]-1]]);
			}
			ans += visit.size() - now_max;
		}
	}
	cout << ans << endl;
	return 0;
}