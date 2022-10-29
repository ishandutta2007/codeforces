#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a, b;
vector<vector<pair<int, int> > > c;
vector<int> p;

int Find(int x) {
	if (p[x] == x) return x;
	else return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	int x1 = Find(x), y1 = Find(y);
	p[x1] = y1;
}

bool Connected(int x, int y) {
	return Find(x) == Find(y);
}

int main() {
	scanf("%d %d", &n, &m);
	a.resize(n);
	b.resize(m);
	p.resize(m);
	for (int i = 0; i < m; i++) p[i] = i;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	long long ans = 0;
	int i1, i2;
	vector<pair<int, pair<int, int> > > edges;
	for (int i = 0; i < n; i++) {
		scanf("%d", &i1);
		for (int j = 0; j < i1; j++) {
			scanf("%d", &i2);
			i2--;
			edges.push_back(make_pair(a[i] + b[i2], make_pair(i, i2)));
		}
	}
	sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges.end());
	vector<int> color;
	color.resize(n, -1);
	for (int i = 0; i < edges.size(); i++) {
		int x = edges[i].second.first;
		int col = edges[i].second.second;
		if (color[x] == -1) color[x] = col;
		else if (Connected(color[x], col)) ans += edges[i].first;
		else Union(color[x], col);
	}
	printf("%lld\n", ans);
	return 0;
}