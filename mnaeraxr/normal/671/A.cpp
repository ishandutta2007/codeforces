#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;
typedef complex<ld> point;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

point read(){
	ld x, y;
	cin >> x >> y;
	return point(x, y);
}

void update(point child, point g, vector<pair<ld, int>> &v, int idx){
	ld dist = -abs(child - g) + abs(g);
	if (dist > v[1].first){
		v[1] = {dist, idx};
	}

	if (dist > v[0].first){
		v[1] = v[0];
		v[0] = {dist, idx};
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	point c1 = read();
	point c2 = read();
	point center = read();

	c1 -= center;
	c2 -= center;

	int n; cin >> n;

	ld total = 0;
	vector<pair<ld,int>> v1(2, pair<ld,int>(-1e60, -1));
	vector<pair<ld,int>> v2(2, pair<ld,int>(-1e60, -1));

	for (int i = 0; i < n; ++i){
		point g = read();
		g -= center;

		total += 2 * abs(g);
		update(c1, g, v1, i);
		update(c2, g, v2, i);
	}

	ld ans = 1e60;

	ans = min(ans, total - v1[0].first);
	ans = min(ans, total - v2[0].first);

	if (v1[0].second != v2[0].second){
		ans = min(ans, total - v1[0].first - v2[0].first);
	}
	else{
		ans = min(ans, total - v1[0].first - v2[1].first);
		ans = min(ans, total - v1[1].first - v2[0].first);
	}

	cout.precision(17);
	cout << fixed << ans << endl;

	return 0;
}