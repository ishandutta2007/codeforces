#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const long double pi = acos(-1.0);
const int rms = (1 << 20) - 1;
const int hrms = rms / 2;

struct mdf {
	long double x, y;
	long double ang;

	mdf(long double x_ = 0.0, long double y_ = 0.0, long double a_ = 0.0) : x(x_), y(y_), ang(a_) {}
};

int n, m;
int tp, x, y;

long double sqr(long double x) {
	return x * x;
}

mdf operator + (const mdf& a, const mdf& b) {
	return mdf(a.x + b.x * cos(a.ang) - b.y * sin(a.ang), a.y + b.y * cos(a.ang) + b.x * sin(a.ang), a.ang + b.ang);
}

mdf rmq[rms + 1];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
    	rmq[i + 1 + hrms] = mdf(1.0, 0.0, 0.0);
    }
    for (int i = hrms; i > 0; i--) {
    	rmq[i].x = rmq[i * 2].x + rmq[i * 2 + 1].x;
    }

    for (int i = 0; i < m; i++) {
    	scanf("%d%d%d", &tp, &x, &y);
    	if (tp == 1) {
    		long double curlen = sqrt(sqr(rmq[x + hrms].x) + sqr(rmq[x + hrms].y));
    		rmq[x + hrms].x *= (curlen + y) / curlen;
	   		rmq[x + hrms].y *= (curlen + y) / curlen;
    	} else {
    		long double ang = atan2(rmq[x + hrms].y, rmq[x + hrms].x);
    		long double curlen = sqrt(sqr(rmq[x + hrms].x) + sqr(rmq[x + hrms].y));
    		
    		ang -= y * pi / 180.0;
    		rmq[x + hrms].x = curlen * cos(ang);
    		rmq[x + hrms].y = curlen * sin(ang);
    		rmq[x + hrms].ang -= y * pi / 180.0;
    	}
    	int ps = x + hrms;
    	while (ps > 1) {
    		ps /= 2;
    		rmq[ps] = rmq[ps * 2] + rmq[ps * 2 + 1];
    	}

    	printf("%.10lf %.10lf\n", (double) rmq[1].x, (double) rmq[1].y);
    }

    return 0;
}