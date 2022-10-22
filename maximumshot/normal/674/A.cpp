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
	
	int n;
	scanf("%d", &n);

	vec< int > a(n + 1), c(n + 1), t(n + 1);

	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
	}

	for(int l = 1;l <= n;l++) {
		for(int col = 1;col <= n;col++) t[col] = 0;
		pii tmp = mp(0, 0);
		for(int r = l;r <= n;r++) {
			t[a[r]]++;
			tmp = max(tmp, mp(t[a[r]], -a[r]));
			c[-tmp.second]++;
		}
	}

	for(int i = 1;i <= n;i++) {
		printf("%d ", c[i]);
	}

	printf("\n");

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}