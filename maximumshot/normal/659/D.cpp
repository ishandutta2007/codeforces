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

bool solve() {

	int n;
	scanf("%d", &n);

	vec< int > x(n + 1), y(n + 1); 

	for(int i = 0;i <= n;i++) {
		scanf("%d %d", &x[i], &y[i]);
	}

	int res = 0, x1, y1, x2, y2, x3, y3;

	for(int i = 0;i < n;i++) {
		x1 = x[i];
		y1 = y[i];
		x2 = x[i + 1];
		y2 = y[i + 1];
		x3 = x[(i + 2) % (n + 1)];
		y3 = y[(i + 2) % (n + 1)];
		if(x1 == x2) {
			if(y1 < y2) {
				res += (x3 < x2);
			}else {
				res += (x3 > x2);
			}
		}else {
			if(x1 < x2) {
				res += (y3 > y2);
			}else {
				res += (y3 < y2);
			}
		}
	}

	printf("%d\n", res);

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}