#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	Point operator - (const Point &p) { return Point(x - p.x, y - p.y); }
	bool operator < (const Point &p) {
		return make_pair(y, x) < make_pair(p.y, p.x);
	}
	void scan() { cin >> x >> y; }
	void print() { cout << x << ' ' << y << '\n'; }
};

long long cross(Point p, Point q) { return 1ll * p.x * q.y - 1ll * q.x * p.y; }
long long area(Point a, Point b, Point c) {
	return cross(a, b) + cross(b, c) + cross(c, a);
}

bool cmp(pair<Point,pair<int,int>> a, pair<Point, pair<int,int>> b) {
	return cross(a.first, b.first) < 0;
}

const int N = 2005;

int n;
long long s;
Point a[N];
pair<Point,pair<int,int>> arr[N * N];
int sz = 0;
int pos[N], ord[N];

void solve(int lef, int rig, long long s) {
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (area(a[lef], a[rig], a[ord[mid]]) > s) l = mid + 1;
		else r = mid;
	}
	if (area(a[lef], a[rig], a[ord[l]]) == s) {
		cout << "Yes" << '\n';
		a[lef].print(), a[rig].print(), a[ord[l]].print();
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> s; s = s * 2;
	for (int i = 1; i <= n; ++i) a[i].scan();
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			arr[++sz] = make_pair(a[j] - a[i], make_pair(i, j));
		}
	}
	sort(arr + 1, arr + 1 + sz, cmp);
	
	for (int i = 1; i <= n; ++i) {
		ord[i] = i, pos[i] = i;
	}
	for (int i = 1; i <= sz; ++i) {
		int lef = arr[i].second.first, rig = arr[i].second.second; 
		solve(lef, rig, s);
		solve(lef, rig, -s);
		// shuffle
		swap(ord[pos[lef]], ord[pos[rig]]);
		swap(pos[lef], pos[rig]);
	}
	cout << "No\n";
}