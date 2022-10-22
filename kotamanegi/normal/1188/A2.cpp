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
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
vector<pair<int, int>> vertexs[200000];
int winner = 1;
vector<tuple<int, int, int>> ans;
vector<pair<int,int>> solve(int now, int back, int back_required) {
	vector<pair<int, int>> here;
	vector<vector<pair<int, int>>> merger;
	if (vertexs[now].size() == 1) {
		here.push_back(make_pair(now, back_required));
		return here;
	}
	for (int q = 0; q < vertexs[now].size(); ++q) {
		if (vertexs[now][q].first != back) {
			vector<pair<int, int>> getting = solve(vertexs[now][q].first, now, vertexs[now][q].second);
			merger.push_back(getting);
		}
	}
	{
		if (merger.size() == 1) {
			int summer = 0;
			for (int q = 0; q < merger[0].size(); ++q) {
				summer += merger[0][q].second;
			}
			if (summer != back_required) {
				winner = 0;
			}
			here = merger[0];
		}
		else {
			for (int q = 1; q < merger.size(); ++q) {
				for (int j = 0; j < merger[q].size(); ++j) {
					if (merger[q][j].second == 0) continue;
					merger[0][0].second -= merger[q][j].second;
					ans.push_back(make_tuple(merger[0][0].first, merger[q][j].first, merger[q][j].second));
					merger[q][j].second = 0;
				}
			}
			if (back_required == -1e9) {
				//final merge start
				for (int q = 1; q < merger[0].size(); ++q) {
					if (merger[0][q].second == 0) continue;
					merger[0][0].second += merger[0][q].second;
					ans.push_back(make_tuple(merger[0][0].first, merger[1][0].first, -merger[0][q].second));
					ans.push_back(make_tuple(merger[0][q].first, merger[1][0].first, merger[0][q].second));
					merger[0][q].second = 0;
				}
				if (merger.size() >= 3) {
					int geko = merger[0][0].second;
					geko /= 2;
					ans.push_back(make_tuple(merger[0][0].first, merger[1][0].first, geko));
					ans.push_back(make_tuple(merger[0][0].first, merger[2][0].first, geko));
					ans.push_back(make_tuple(merger[1][0].first, merger[2][0].first, -1 * geko));
					merger[0][0].second = 0;
				}
				if (merger[0][0].second != 0) {
					winner = 0;
				}
				return here;
			}
			int summing = 0;
			REP(q, merger[0].size()) {
				summing += merger[0][q].second;
			}
			summing -= back_required;
			if (summing == 0) {
				here = merger[0];
			}
			else {
				summing /= -2;
				merger[0][0].second += summing;
				merger[1][0].second += summing;
				ans.push_back(make_tuple(merger[0][0].first, merger[1][0].first, -summing));
				here = merger[0];
				here.push_back(merger[1][0]);
			}
			for (int q = 1; q < here.size(); ++q) {
				if (here[q].second == 0) {
					here.erase(here.begin() + q);
					q--;
				}
			}
		}
	}
	return here;
}
int main() {
	int n;
	cin >> n;
	int ok = 1;
	REP(i, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c != 0) {
			ok = 0;
		}
		vertexs[a].push_back(make_pair(b, c));
		vertexs[b].push_back(make_pair(a, c));
	}
	if (ok == 1) {
		cout << "YES" << endl;
		cout << "0" << endl;
		return 0;
	}
	if (n == 2) {
		cout << "YES" << endl;
		cout << "1" << endl;
		cout << "1 2 " << vertexs[1][0].second << endl;
		return 0;
	}
	int now_itr = 0;
	REP(i, n) {
		if (vertexs[i + 1].size() >= 2) {
			now_itr = i + 1;
			break;
		}
	}
	solve(now_itr,-1,-1e9);
	if (winner == 1) {
		cout << "YES" << endl;
		cout << ans.size() << endl;
		REP(i, ans.size()) {
			cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << endl;
		}
	}
	else {
		cout << "NO" << endl;
		return 0;
	}
}