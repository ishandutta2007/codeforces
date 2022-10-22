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

bool solve() {

	int n, m;

	scanf("%d %d", &n, &m);

	vec< vec< int > > a(n, vec< int >(4));

	int cur = 1;

	for(int i = 0;i < min(n + n, m);i++) {
		if(i % 2 == 0) {
			a[i / 2][0] = cur++;
		}else {
			a[i / 2][3] = cur++;
		}
	}

	m = max(0, m - n - n);

	for(int i = 0;i < min(m, n + n);i++) {
		if(i % 2 == 0) {
			a[i / 2][1] = cur++;
		}else {
			a[i / 2][2] = cur++;
		}
	}

	for(int i = 0;i < n;i++) {
		for(int j = 1;j >= 0;j--) if(a[i][j] > 0) printf("%d ", a[i][j]);
		for(int j = 2;j <= 3;j++) if(a[i][j] > 0) printf("%d ", a[i][j]);
	}

	printf("\n");

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}