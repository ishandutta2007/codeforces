#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

struct point {
	ld x, y;
	point() {
		x = y = 0;
	}
	point(ld X, ld Y) {
		x = X, y = Y;
	}
	point operator-(point a) {
		return point(x - a.x, y - a.y);
	}
	ld len() {
		return sqrt(x * x + y * y);
	}
};
point a, b, t;
point arr[120000];
ld bl[120000];
ld br[120000];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
	a = a - t;
	b = b - t;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].x >> arr[i].y;
		arr[i] = arr[i] - t;
	}
	ld sum = 0;
	for (int i = 0; i < n; ++i)
		sum += 2* arr[i].len();

	ld bst = 0;
	for (int i = 0; i < n; ++i) {
		bl[i] = bst;
		bst = max(bst,  arr[i].len() - (arr[i] - b).len());
	}
	bl[n] = bst;
	bst = 0;
	br[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		br[i] = bst;
		bst = max(bst,  arr[i].len() - (arr[i] - b).len());
	}

	ld ans = sum + 5e10;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, sum - arr[i].len() + (arr[i] - b).len());
	}
	for (int i = 0; i < n; ++i) {
		ans = min(ans, sum - max(bl[i], br[i]) - (arr[i].len() - (arr[i] - a).len()));
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << ans << "\n";

	return 0;
}