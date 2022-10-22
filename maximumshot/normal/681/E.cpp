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
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>
#include <complex>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

const double pi = acos(-1.0);

double dist(pdd a, pdd b) {
	double x, y;
	x = a.first - b.first;
	y = a.second - b.second;
	return sqrt(x * x + y * y);
}

double deg(double x, double y) {
	return atan2(y, x);
}

pdd read_pair() {
	int x, y;
	scanf("%d %d", &x, &y);
	return mp(x, y);
}

double read_d() {
	int x;
	scanf("%d", &x);
	return x;
}

bool solve() {
	
	cout.precision(10);
	cout << fixed;

	pdd s;

	cin >> s.first >> s.second;

	double v, T;
	
	cin >> v >> T;

	int n;
	
	cin >> n;

    pdd seg[100100];
    int sz = 0;

	double RR = v * T;
	
	for(int i = 0;i < n;i++) {
		pdd o;
		double R;
		
		//cin >> o.first >> o.second >> R;
		
		o = read_pair();
		R = read_d();

		double d = dist(s, o);
		
		if(d <= R) {
			cout << 1.0 << '\n';
			return true;
		}
		
		if(RR <= d - R) continue;
		
		double a = sqrt(d * d - R * R);
		double _deg = deg(o.first - s.first, o.second - s.second);
		double l, r;
		
		if(RR >= a) {
			l = _deg + asin(R / d);
			r = _deg - asin(R / d);
		}else {
			double t_cos = (d * d + RR * RR - R * R) / (2 * d * RR);
			double t = acos(t_cos);
			l = _deg - t;
			r = _deg + t;
		}
		
		if(l > r) swap(l, r);
		
		if(l < -pi) seg[sz++] = mp(l + pi + pi, pi), l = -pi;
		if(r > pi) seg[sz++] = mp(-pi, r - pi - pi), r = pi;
		seg[sz++] = mp(l, r);
	}

    sort(seg, seg + sz);

	double sum = 0.0;
	double last = -10.0;

	for(int i = 0;i < sz;i++) {
	    auto cur = seg[i];
		if(cur.second <= last) continue;
		if(cur.first <= last) sum += cur.second - last, last = cur.second;
		else sum += cur.second - cur.first, last = cur.second;
	}

	cout << sum / (2.0 * pi) << '\n';

	return true;

}

int main() {

	//while(solve());
	solve();

	return 0;
}