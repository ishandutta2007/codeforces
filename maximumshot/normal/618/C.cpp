#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n;
vec< pair< pii, int > > a;
int x, y;

ll sqr(int value) {
	return 1ll * value * value;
} 

bool cmp(const pair< pii, int > & p1, const pair< pii, int > & p2) {
	int x1, y1, x2, y2;
	x1 = p1.first.first;
	y1 = p1.first.second;
	x2 = p2.first.first;
	y2 = p2.first.second;

	int u1, v1;
	int u2, v2;

	u1 = y1 - y;
	v1 = x1 - x;

	u2 = y2 - y;
	v2 = x2 - x;

	if(1ll * v2 * u1 < 1ll * v1 * u2) return 1;
	else if(1ll * v2 * u1 == 1ll * v1 * u2) {
		return sqr(x1 - x) + sqr(y1 - y) < sqr(x2 - x) + sqr(y2 - y);
	}else return 0;
}

bool solve() {

	scanf("%d", &n);

	a.resize(n);

	for(int i = 0;i < n;i++) {
		scanf("%d %d", &a[i].first.first, &a[i].first.second);
		a[i].second = i + 1;
	}

	sort(ALL(a));
	x = a[0].first.first;
	y = a[0].first.second;
	sort(a.begin() + 1, a.end(), cmp);

	cout << a[0].second << ' ' << a[1].second << ' ';
	
	int u, v;
	u = a[1].first.second - a[0].first.second;
	v = a[1].first.first - a[0].first.first;
	
	for(int i = 2;i < n;i++) {
		int tu, tv;
		tu = a[i].first.second - a[0].first.second;
		tv = a[i].first.first - a[0].first.first;
		if(1ll * u * tv != 1ll * tu * v) {
			cout << a[i].second << '\n';
			break;
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}