#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define i64 long long int
int m;
vector<int> a[3030];
int main() {
	int n,x,y;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= m; i++)sort(a[i].begin(), a[i].end());
	i64 bes = (i64)1e18;
	for (int T = max((int)a[1].size(), 1); T <= n; T++) {
		i64 cur = 0;int sz = a[1].size();
		vector<int> all;
		for (int i = 2; i <= m; i++) {
			if (a[i].size() >= T) {
				int todo = a[i].size() - T + 1;
				for (int j = 0; j < todo; j++)
					cur += a[i][j];
				sz += todo;
				for (int j = todo; j < a[i].size(); j++)
					all.push_back(a[i][j]);
			}
			else {
				for (int j = 0; j < a[i].size(); j++)
					all.push_back(a[i][j]);
			}
		}
		if (sz < T) {
			sort(all.begin(), all.end());
			for (int j = 0; j < T - sz; j++)
				cur += all[j];
		}
		bes = min(bes, cur);
	}
	cout << bes << endl;
	return 0;
}