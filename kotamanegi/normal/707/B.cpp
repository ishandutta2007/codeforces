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
vector<pair<int,long long>> towns[200000];
vector<int> to_visit;
int visited[300000] = {};
int main() {
	int n, m,k;
	cin >> n >> m >> k;
	if (k == 0) {
		cout << "-1" << endl;
		return 0;
	}
	REP(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		towns[a].push_back(pair<int, long long>(b, c));
		towns[b].push_back(pair<int, long long>(a, c));
	}
	REP(i, k) {
		int a;
		cin >> a;
		to_visit.push_back(a);
		visited[a] = true;
	}
	long long ans = 99999999999999999;
	for (int i = 0;i < to_visit.size();++i) {
		for (int q = 0;q < towns[to_visit[i]].size();++q) {
			if (visited[towns[to_visit[i]][q].first] == false) {
				ans = min(ans, towns[to_visit[i]][q].second);
			}
		}
	}
	if (ans == 99999999999999999) {
		cout << "-1" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}