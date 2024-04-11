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
#define ran 202222
int n, q, a[ran];
int l[ran], r[ran];
vector<int> pos[ran];
int o[ran];
set<int> ss;
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0)continue;
		if (l[a[i]] == 0)l[a[i]] = i;
		r[a[i]] = i;
	}
	for (int i = 1; i <= q; i++) {
		if (l[i] == 0)continue;
		pos[l[i]].push_back(i);
		pos[r[i]].push_back(-i);
	}
	for (int i = 1; i <= n; i++) {
		if (!pos[i].empty()) {
			int x = *pos[i].begin();
			if(x > 0)ss.insert(x);
		}
		if (ss.empty())o[i] = 0;else
			o[i] = *ss.rbegin();
		if (!pos[i].empty()) {
			int x = pos[i].back();
			if(x < 0)ss.erase(-x);
		}
	}
	bool sol = true;
	for (int i = 1; i <= n; i++)if (a[i] != 0 && o[i] != a[i]) {
		sol = false;
		break;
	}
	if (!sol) { cout << "NO" << endl;return 0; }
	vector<int> qqq;
	for (int i = 1; i <= n; i++)if (o[i] == 0)o[i] = 1;
	for(int i=1; i<=n; i++)if(a[i] == 0)qqq.push_back(i);
	if (l[q] == 0) {
		if (qqq.empty()) { cout << "NO" << endl;return 0; }
		o[*qqq.begin()] = q;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		cout << o[i] << (i < n ? ' ' : '\n');
	return 0;
}