#include <bits/stdc++.h>
using namespace std;

#define N 1011

struct point {
	int x, y, i;
};
vector <point> a[2][2];
int n;

void output(vector <point> a, vector <point> b, vector <point> c, vector <point> d) {
	printf("%d\n", int(a.size() + b.size()));
	for (auto v: a) printf("%d ", v.i);
	for (auto v: b) printf("%d ", v.i);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;		
		scanf("%d%d", &x, &y);
		a[x & 1][y & 1].push_back({x, y, i});
	}
	do {
		vector <point> b;
		int flag = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++) {
				flag += !!a[i][j].size();
				for (auto v : a[i][j]) b.push_back(v);
			}
		if (flag != 1) break;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				a[i][j].clear();
		for (auto v : b) {
			a[v.x & 1][v.y & 1].push_back({(v.x + 1000000000) / 2 - 500000000,(v.y + 1000000000) / 2 - 500000000, v.i});
		}
	} while (true);
	if (a[0][0].size() + a[1][1].size() && a[0][1].size() + a[1][0].size()) {
		output(a[0][0], a[1][1], a[0][1], a[1][0]);
	}
	else if (a[0][0].size() + a[0][1].size() && a[1][0].size() + a[1][1].size()) {
		output(a[0][0], a[0][1], a[1][0], a[1][1]);
	}
	else puts("FUCK");
}