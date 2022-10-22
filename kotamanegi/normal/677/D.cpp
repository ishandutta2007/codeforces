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
vector<pair<int,int>> leveling[100000];
long long ans_map[400][400] = {};
long long semi_map[350][350] = {};
int size_lev[100000] = {};
int main() {
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0;i < n;++i) {
		for (int q = 0;q < m;++q) {
			int hoge;
			scanf("%d", &hoge);
			leveling[hoge].push_back(pair<int, int>(i, q));
			size_lev[hoge]++;
		}
	}
	for (int i = 0;i < 350;++i) {
		for (int q = 0;q < 350;++q) {
			ans_map[i][q] = 999999999999999;
		}
	}
	for (int i = 0;i < size_lev[1];++i) {
		ans_map[leveling[1][i].first][leveling[1][i].second] = leveling[1][i].first + leveling[1][i].second;
	}
	for (int i = 1;i < p;++i) {
		if (size_lev[i] * size_lev[i + 1] < 1000000) {
			for (int q = 0;q < size_lev[i];++q) {
				for (int j = 0;j < size_lev[i + 1];++j) {
					ans_map[leveling[i + 1][j].first][leveling[i + 1][j].second] = min(ans_map[leveling[i + 1][j].first][leveling[i + 1][j].second], ans_map[leveling[i][q].first][leveling[i][q].second] + abs(leveling[i][q].first - leveling[i + 1][j].first) + abs(leveling[i][q].second - leveling[i + 1][j].second));
				}
			}
		}
		else {
			//dijkstra
			for (int i = 0;i < n;++i) {
				for (int q = 0;q < m;++q) {
					semi_map[i][q] = 999999999999999;
				}
			}
			queue<pair<int, pair<int, int>>> hoge;
			for (int q = 0;q < size_lev[i];++q) {
				hoge.push(make_pair(ans_map[leveling[i][q].first][leveling[i][q].second], make_pair(leveling[i][q].first, leveling[i][q].second)));
				while (hoge.empty() == false) {
					long long ans = hoge.front().first + 1;
					pair<int, int> basyo = hoge.front().second;
					hoge.pop();
					if (semi_map[basyo.first + 1][basyo.second] > ans&&basyo.first - 1 < n) {
						semi_map[basyo.first + 1][basyo.second] = ans;
						hoge.push(make_pair(ans, make_pair(basyo.first + 1, basyo.second)));
					}
					if (semi_map[basyo.first][basyo.second + 1] > ans&&basyo.second - 1 < n) {
						semi_map[basyo.first][basyo.second + 1] = ans;
						hoge.push(make_pair(ans, make_pair(basyo.first, basyo.second + 1)));
					}
					if (semi_map[basyo.first - 1][basyo.second] > ans&&basyo.first > 0) {
						semi_map[basyo.first - 1][basyo.second] = ans;
						hoge.push(make_pair(ans, make_pair(basyo.first - 1, basyo.second)));
					}
					if (semi_map[basyo.first][basyo.second - 1] > ans&&basyo.second > 0) {
						semi_map[basyo.first][basyo.second - 1] = ans;
						hoge.push(make_pair(ans, make_pair(basyo.first, basyo.second - 1)));
					}
				}
			}
			for (int q = 0;q < size_lev[i + 1];++q) {
				ans_map[leveling[i + 1][q].first][leveling[i + 1][q].second] = semi_map[leveling[i + 1][q].first][leveling[i + 1][q].second];
			}
		}
	}
	cout << ans_map[leveling[p][0].first][leveling[p][0].second] << endl;
}