#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
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

const int MAXVAL = 3 * 1000 * 1000 + 10;

bool solve() {

	int n;

	scanf("%d", &n);

	vec< int > c(MAXVAL);

	for(int x, i = 0;i < n;i++) {
		scanf("%d", &x);
		c[x]++;
	}

	vec< ll > dp(MAXVAL);

	for(int x = 1;x < MAXVAL;x++) {
		for(int y = x;y < MAXVAL;y += x) {
			if(x != y / x) dp[y] += 1ll * c[x] * c[y / x];
			else dp[y] += 1ll * c[x] * (c[x] - 1);
		}
	}

	for(int i = 1;i < MAXVAL;i++) dp[i] += dp[i - 1];

	int q, p;

	scanf("%d", &q);

	while(q--) {
		scanf("%d", &p);
		printf("%I64d\n", 1ll * n * (n - 1) - dp[p - 1]);
	}

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}