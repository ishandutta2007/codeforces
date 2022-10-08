#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

struct Point {
	int x, y;
	int index;
};

bool operator < (const Point& a, const Point& b) {
	return a.index < b.index;
}

int dist(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int det(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int scal(Point b, Point a, Point c) {
	return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

int main() {
	vector<Point> p;
	for (int i = 1; i <= 8; ++i) {
		Point c;
		scanf("%d %d", &c.x, &c.y);
		c.index = i;
		p.PB(c);
	}
	do {
		bool ok = true;
		for (int i = 1; i < 4; ++i) {
			int j = (i + 1) % 4;
			if (dist(p[i], p[j]) != dist(p[0], p[1])) {
				ok = false;
			}
		}
		for (int i = 0; i < 4; ++i) {
			int j = (i + 1) % 4;
			int k = (j + 1) % 4;
			if (det(p[i], p[j], p[k]) <= 0 || scal(p[i], p[j], p[k]) != 0) {
				ok = false;
			}
			if (det(p[4 + i], p[4 + j], p[4 + k]) <= 0 || scal(p[4 + i], p[4 + j], p[4 + k]) != 0) {
				ok = false;
			}
		}
		if (dist(p[4], p[5]) != dist(p[6], p[7])) {
			ok = false;
		}
		if (dist(p[5], p[6]) != dist(p[7], p[4])) {
			ok = false;
		}
		if (ok) {
			printf("YES\n");
			for (int i = 0; i < 4; ++i) {
				printf("%d", p[i].index);
				if (i < 3) {
					printf(" ");
				}
			}
			printf("\n");
			for (int i = 0; i < 4; ++i) {
				printf("%d", p[4 + i].index);
				if (i < 3) {
					printf(" ");
				}
			}
			printf("\n");
			return 0;
		}
	} while (next_permutation(ALL(p)));
	printf("NO\n");
	return 0;
}