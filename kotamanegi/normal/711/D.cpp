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
#include <malloc.h>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
#define LONGINF 1000000000000000000
long long cal(long long a, long long b) {
	long long ans = 1;
	for (int i = 0;i < b - a;++i) {
		ans *= 2;
		ans %= MAX_MOD;
	}
	long long tmp = 1;
	for (int i = 0;i < a;++i) {
		tmp *= 2;
		tmp %= MAX_MOD;
	}
	tmp -= 2;
	if (tmp == 0) tmp = MAX_MOD;
	if (tmp == -1) tmp = MAX_MOD - 1;
	ans *= tmp;
	ans %= MAX_MOD;
	if (ans == 0) ans = MAX_MOD;
	return ans;
}
vector<int> go[300000];
int visited[300000] = {};
long long loop[300000] = {};
int main() {
	int n;
	cin >> n;
	vector<int> a;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp - 1);
		go[i].push_back(tmp - 1);
		go[tmp - 1].push_back(i);
	}
	vector < pair < long long, long long >> hogee;
	for (int i = 0;i < n;++i) {
		if (visited[i] == false) {
			long long c=0;
			int hoge = i;
			loop[i] = 1;
			while (hoge != -1) {
				if (loop[a[hoge]] != 0) {
					c = loop[hoge] - loop[a[hoge]]+1;
					hoge = -1;
				}
				else {
					loop[a[hoge]] = loop[hoge] + 1;
					hoge = a[hoge];
				}
			}
			//cnt size
			queue<int> hogea;
			hogea.push(i);
			int size_cnt = 1;
			visited[i] = true;
			while (hogea.empty() == false) {
				int tmp = hogea.front();
				hogea.pop();
				for (int q = 0;q < go[tmp].size();++q) {
					if (visited[go[tmp][q]] == false) {
						visited[go[tmp][q]] = true;
						size_cnt++;
						hogea.push(go[tmp][q]);
					}
				}
			}
			hogee.push_back(make_pair(c, size_cnt));
		}
	}
	long long ans = 1;
	for (int i = 0;i < hogee.size();++i) {
		ans *= cal(hogee[i].first, hogee[i].second);
		ans %= MAX_MOD;
	}
	cout << ans << endl;
}