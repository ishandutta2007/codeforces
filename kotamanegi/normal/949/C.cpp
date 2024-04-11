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
int mente[200000];
vector<int> vertexs[200000];
stack<int> visit_vertexs;
int visited[200000];
int itr = 1;
int dfs(int now) {
	visited[now] = -1;
	for (int i = 0; i < vertexs[now].size(); ++i) {
		if (visited[vertexs[now][i]] == 0) {
			dfs(vertexs[now][i]);
		}
	}
	visited[now] = itr;
	itr++;
	visit_vertexs.push(now);
	return 0;
}
int final_visited[200000];
vector<int> gyaku[200000];
vector<int> sizes[200000];
vector<int> connection[200000];
int main() {
	iostream::sync_with_stdio(false);
	int n, m, h;
	cin >> n >> m >> h;
	REP(i, n) {
		cin >> mente[i];
	}
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if ((mente[a] + 1) % h == mente[b] % h) {
			vertexs[a].push_back(b);
			gyaku[b].push_back(a);
		}
	     if ((mente[b] + 1) % h == mente[a] % h) {
			vertexs[b].push_back(a);
			gyaku[a].push_back(b);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (visited[i] == 0) {
			dfs(i);
		}
	}
	//stack is in
	itr = 1;
	while (visit_vertexs.empty() == false) {
		int hoge = visit_vertexs.top();
		visit_vertexs.pop();
		if (final_visited[hoge] == 0) {
			final_visited[hoge] = itr;
			queue<int> next;
			next.push(hoge);
			sizes[itr].push_back(hoge);
			while (next.empty() == false) {
				int now = next.front();
				next.pop();
				for (int i = 0; i < gyaku[now].size(); ++i) {
					if (final_visited[gyaku[now][i]] == 0) {
						final_visited[gyaku[now][i]] = itr;
						sizes[itr].push_back(gyaku[now][i]);
						next.push(gyaku[now][i]);
					}
					else if (final_visited[gyaku[now][i]] != itr) {
						connection[final_visited[gyaku[now][i]]].push_back(itr);
					}
				}
			}
			itr++;
		}
	}
	int now_minnest = 1000000;
	int now_itr = 0;
	for (int i = 0; i <= n; ++i) {
		if (sizes[i].size() != 0) {
			if (connection[i].size() == 0) {
				if (now_minnest > sizes[i].size()) {
					now_minnest = sizes[i].size();
					now_itr = i;
				}
			}
		}
	}
	cout << now_minnest << endl;
	for (int i = 0; i < sizes[now_itr].size(); ++i) {
		if (i != 0) cout << " ";
		cout << sizes[now_itr][i]+1;
	}
	cout << endl;
	return 0;
}