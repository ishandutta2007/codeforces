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
#include <random>
#define EVAL 1
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 1048576
#define PI 3.1415926535
vector<int> vertexs[200000];
vector<int> go_vertexs[200000];
int visited[2][200000] = {};
int already[200000] = {};
int resulting[200000] = {};
int dfs(int now) {
	if (resulting[now] == 1) return 0;
	for (int i = 0; i < go_vertexs[now].size(); ++i) {
		if (already[go_vertexs[now][i]] == 1) return 1;
		already[go_vertexs[now][i]] = 1;
		int moo = dfs(go_vertexs[now][i]);
		if (moo == 1) return 1;
		already[go_vertexs[now][i]] = 0;
		resulting[go_vertexs[now][i]] = 1;
	}
	return 0;
}
int main() {
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> next;
	REP(i, n) {
		int a;
		cin >> a;
		REP(q, a) {
			int b;
			cin >> b;
			vertexs[b].push_back(i + 1);
			go_vertexs[i + 1].push_back(b);
		}
		if (a == 0) {
			next.push(make_pair(0, i + 1));
			visited[0][i + 1] = -1;
		}
	}
	int beginning = 0;
	cin >> beginning;
	while (next.empty() == false) {
		pair<int, int> now = next.front();
		next.pop();
		for (int q = 0; q < vertexs[now.second].size(); ++q) {
			if (visited[(now.first + 1) % 2][vertexs[now.second][q]] == 0) {
				visited[(now.first + 1) % 2][vertexs[now.second][q]] = now.second;
				next.push(make_pair((now.first + 1) % 2, vertexs[now.second][q]));
			}
		}
	}
	if (visited[1][beginning] != 0) {
		cout << "Win" << endl;
		int cnt = 1;
		while (beginning != -1) {
			cout << beginning << " ";
			beginning = visited[cnt][beginning];
			cnt++;
			cnt %= 2;
		}
		return 0;
	}
	int geko = dfs(beginning);
	if (geko == 1) {
		cout << "Draw" << endl;
	}
	else {
		cout << "Lose" << endl;
	}
	return 0;
}