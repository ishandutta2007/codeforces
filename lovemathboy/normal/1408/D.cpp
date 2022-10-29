#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int> > a, b, c;

int main() {
	scanf("%d %d", &n, &m);
	int i1, i2;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &i1, &i2);
		a.push_back(make_pair(i1, i2));
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &i1, &i2);
		b.push_back(make_pair(i1, i2));
	}
	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	deque<pair<int, int> > dq;
	for (int i = 0; i < b.size(); i++) {
		while (!dq.empty() && dq.back().second <= b[i].second) dq.pop_back();
		dq.push_back(b[i]);
	}
	while (!dq.empty()) {
		c.push_back(dq.front());
		dq.pop_front();
	}
	/*for (int i = 0; i < c.size(); i++) {
		printf("%d %d\n", c[i].first, c[i].second);
	}*/
	int pi = 0;
	int maxh = 0;
	vector<vector<pair<int, int> > > useful;
	vector<int> maxi, curh;
	maxi.resize(1000050, 0);
	useful.resize(1000050);
	curh.resize(a.size(), 0);
	for (int i = 0; i < a.size(); i++) {
		int index = pi;
		while (index < c.size() && c[index].first < a[i].first) index++;
		pi = index;
		if (index >= c.size()) break;
		maxh = max(maxh, c[index].second - a[i].second + 1);
		curh[i] = c[index].second - a[i].second + 1;
		if (curh[i] >= 0) maxi[curh[i]]++;
		for (int j = index; j < c.size(); j++) {
			if (j < c.size() - 1) useful[c[j].first - a[i].first + 1].push_back(make_pair(i, max(0, c[j+1].second - a[i].second + 1)));
			else useful[c[j].first - a[i].first + 1].push_back(make_pair(i, 0));
			if (c[j].second < a[i].second) break;
		}
	}
	int ans = maxh;
	for (int i = 1; i <= 1000005; i++) {
		for (int j = 0; j < useful[i].size(); j++) {
			int x = useful[i][j].first;
			int y = useful[i][j].second;
			//printf("%d %d %d\n", i, x, y);
			if (curh[x] >= 0) {
				maxi[curh[x]]--;
				maxi[y]++;
				curh[x] = y;
			}
		}
		while (maxh > 0 && maxi[maxh] == 0) maxh--;
		ans = min(ans, maxh + i);
	}
	printf("%d\n", ans);
	return 0;
}