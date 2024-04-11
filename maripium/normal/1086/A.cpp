#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int xa, ya, xb, yb, xc, yc;
vector<pair<int,int>> vals;

int get(int a,int b,int c) {
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	return b;
} 

void go(int x,int y,int gx,int gy) {
	if (x < gx) {
		while (x <= gx) {
			vals.push_back(make_pair(x++, y));
		}
	}
	else {
		while (x >= gx) {
			vals.push_back(make_pair(x--, y));
		}
	}
	if (y < gy) {
		while (y <= gy) {
			vals.push_back(make_pair(gx, y++));
		}
	}
	else {
		while (y >= gy) {
			vals.push_back(make_pair(gx, y--));
		}
	}
}

int main() {
	scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
	int xg = get(xa, xb, xc);
	int yg = get(ya, yb, yc);
	go(xa, ya, xg, yg);
	go(xb, yb, xg, yg);
	go(xc, yc, xg, yg);
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	cout << vals.size() << '\n';
	for (auto v : vals) {
		cout << v.first << ' ' << v.second << '\n';
	}
}