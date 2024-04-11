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
int block[200][200] = {};
int main() {
	int c, r;
	cin >> c >> r;
	REP(i, c) {
		string hoge;
		cin >> hoge;
		REP(q, r) {
			if (hoge[q] == 'B') {
				block[i+1][q+1] = true;
			}
		}
	}
	long long ans = 0;
	for (int i = 1;i <= c;++i) {
		for (int q = 1;q <= r;++q) {
			if (block[i][q] == true) {
				block[i][q] = false;
				ans++;
				queue<pair<int,int>> go;
				go.push(make_pair(i, q));
				while (go.empty() == false) {
					pair<int, int> o = go.front();
					go.pop();
					if (o.first > 0&&block[o.first-1][o.second] == 1) {
						block[o.first - 1][o.second]--;
						go.push(make_pair(o.first - 1, o.second));
					}
					if (o.first < c&&block[o.first + 1][o.second] == 1) {
						block[o.first + 1][o.second]--;
						go.push(make_pair(o.first + 1, o.second));
					}
					if (o.second > 0 && block[o.first][o.second-1] == 1) {
						block[o.first][o.second - 1]--;
						go.push(make_pair(o.first, o.second - 1));
					}
					if (o.second < r&&block[o.first][o.second + 1] == 1) {
						block[o.first][o.second + 1]--;
						go.push(make_pair(o.first, o.second + 1));
					}
				}

			}
		}
	}
	cout << ans << endl;
}