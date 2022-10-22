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
int mapping[100][100] = {};
int answers[100][100] = {};
int visited[100][100] = {};
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U> & l, const std::pair<T, U> & r) {
	return{ l.first + r.first,l.second + r.second };
}
template <typename T, typename U>
std::pair<T, U> operator-(const std::pair<T, U> & l, const std::pair<T, U> & r) {
	return{ l.first - r.first,l.second - r.second };
}
pair<int,int> moves[4] = { make_pair(-1,0),make_pair(1,0),make_pair(0,1),make_pair(0,-1) };
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<tuple<int, int, int>> these_ans;
	REP(i, n) {
		string tmp;
		cin >> tmp;
		REP(q, m) {
			if (tmp[q] == '.') {
				mapping[i+1][q+1] = 1;
				answers[i + 1][q + 1] = 1;
			}
		}
	}
	for (int i = 0;i < 100;++i) {
		mapping[i][0] = 2;
		mapping[0][i] = 2;
		mapping[n + 1][i] = 2;
		mapping[i][m + 1] = 2;
	}
	int cnt_lake = 0;
	for (int i = 1;i <= n;++i) {
		for (int q = 1;q <= m;++q) {
			if (mapping[i][q] == 1&&visited[i][q] == false) {
				queue<pair<int, int>> gogo;
				bool can_be_ans = true;
				visited[i][q] = true;
				int ans_cnt = 1;
				gogo.push(make_pair(i, q));
				while (gogo.empty() == false) {
					pair<int, int> zahyou = gogo.front();
					gogo.pop();
					for (int j = 0;j < 4;++j) {
						zahyou = zahyou+ moves[j];
						if (mapping[zahyou.first][zahyou.second] == 2) {
							can_be_ans = false;
						}
						else if (mapping[zahyou.first][zahyou.second] == 1 && visited[zahyou.first][zahyou.second] == false) {
							ans_cnt++;
							visited[zahyou.first][zahyou.second] = true;
							gogo.push(zahyou);
						}
					zahyou	= zahyou - moves[j];
					}
				}
				if (can_be_ans == true) {
					cnt_lake++;
					these_ans.push_back(make_tuple(ans_cnt, i, q));
				}
			}
		}
	}
	sort(these_ans.begin(), these_ans.end());
	int ans = 0;
	queue<pair<int, int>> wombo;
	for (int i = 0;i < cnt_lake - k;++i) {
		ans += get<0>(these_ans[i]);
		wombo.push(make_pair(get<1>(these_ans[i]), get<2>(these_ans[i])));
	}
	cout << ans << endl;
	while (wombo.empty() == false) {
		pair<int, int> now_go = wombo.front();wombo.pop();
		answers[now_go.first][now_go.second] = 0;
		for (int i = 0;i < 4;++i) {
			now_go = now_go + moves[i];
			if (answers[now_go.first][now_go.second] == 1) {
				answers[now_go.first][now_go.second] = 1;
				wombo.push(now_go);
			}
			now_go = now_go - moves[i];
		}
	}
	for (int i = 1;i <= n;++i) {
		for (int j = 1;j <= m;++j) {
			if (answers[i][j] == 0) {
				cout << "*";
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
	return 0;
}