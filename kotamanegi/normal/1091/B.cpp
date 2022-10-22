#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
using namespace std;
#define eps 0.000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*2
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> obelisk, clue;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		obelisk.push_back(make_pair(a, b));
	}
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		clue.push_back(make_pair(a, b));
	}
	for (int i = 0; i < n; ++i) {
		int visited[2000] = {};
		int bad = 0;
		int ok_x = obelisk[0].first, ok_y = obelisk[0].second;
		ok_x += clue[i].first;
		ok_y += clue[i].second;
		visited[i] = 1;
		for (int q = 1; q < n; ++q) {
			int nya = 0;
			REP(j, n) {
				if (visited[j] == 0) {
					int go_x = obelisk[q].first + clue[j].first;
					int go_y = obelisk[q].second + clue[j].second;
					if (go_x == ok_x && go_y == ok_y) {
						visited[j] = 1;
						nya = 1;
						break;
					}
				}
			}
			if (nya == 0) {
				bad = 1;
				break;
			}
		}
		if (bad == 0) {
			cout << ok_x << " " << ok_y << endl;
			return 0;
		}
	}
	return 0;
}