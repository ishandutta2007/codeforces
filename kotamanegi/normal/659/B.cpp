#define _CRT_SECURE_NO_WARNINGS
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
#include<map>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
vector<pair<int,string>> name[200000];
int counts[200000] = {};
int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin >> n >> m;
	REP(i, n) {
		string hoge;
		int hogehoge[2];
		cin >> hoge >> hogehoge[0] >> hogehoge[1];
		name[hogehoge[0]].push_back(pair<int, string>(hogehoge[1], hoge));
		counts[hogehoge[0]]++;
	}
	for (int i = 1;i <= m;++i) {
		sort(name[i].begin(), name[i].end());
		if (name[i].size() != 2) {
			if (name[i][counts[i] - 2].first == name[i][counts[i] - 3].first) {
				cout << "?" << endl;
			}
			else {
				cout << name[i][counts[i] - 1].second << " " << name[i][counts[i] - 2].second << endl;
			}
		}
		else {
			cout << name[i][counts[i] - 1].second << " " << name[i][counts[i] - 2].second << endl;
		}
	}
	return 0;
}