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
typedef pair< ll, ll > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool solve() {
	
	int n, q;

	scanf("%d %d", &n, &q);

	int c1, c2;

	c1 = 0;
	c2 = 1;

	for(int ty, x, i = 0;i < q;i++) {
		c1 = (c1 % n + n) % n;
		c2 = (c2 % n + n) % n;
		scanf("%d", &ty);
		if(ty == 1) {
			scanf("%d", &x);
			c1 += x;
			c2 += x;
		}else {
			if(c1 % 2 == 0) c1++, c2--;
			else c1--, c2++;
		}
	}

	c1 = (c1 % n + n) % n;
	c2 = (c2 % n + n) % n;

	vec< int > a(n);

	for(int c = 0;c < n / 2;c++, c1 = (c1 + 2) % n, c2 = (c2 + 2) % n) {
		a[c1] = 2 * c + 1;
		a[c2] = 2 * c + 2;
	}

	for(int i = 0;i < n;i++) printf("%d ", a[i]);
	printf("\n");

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}