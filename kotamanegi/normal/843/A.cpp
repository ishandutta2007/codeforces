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
using namespace std;
#define eps 0.00000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int visited[200000] = {};
int main() {
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int,int>> a;
	vector<int> b;
	REP(i, n) {
		int hoge;
		cin >> hoge;
		a.push_back(make_pair(hoge,i));
		b.push_back(0);
	}
	sort(a.begin(), a.end());
	for (int i = 0;i < n;++i) {
		b[a[i].second] = i;
	}
	vector<vector<int>> gogo;
	for (int i = 0;i < n;++i) {
		if (visited[i] == false) {
			visited[i] = true;
			vector<int> ans;
			ans.push_back(i);
			queue<int> geko;
			geko.push(i);
			while (geko.empty() == false) {
				int now = geko.front();geko.pop();
				if (visited[b[now]] == false) {
					visited[b[now]] = true;
					ans.push_back(b[now]);
					geko.push(b[now]);
				}
			}
			gogo.push_back(ans);
		}
	}
	cout << gogo.size() << endl;
	for (int i = 0;i < gogo.size();++i) {
		cout << gogo[i].size() << " ";
		for (int q = 0;q < gogo[i].size();++q) {
			cout << gogo[i][q]+1 << " ";
		}
		cout << endl;
	}
	return 0;
}