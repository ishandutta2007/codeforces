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

bool solve() {
		
	int n;

	scanf("%d", &n);

	vec< int > a(n);

	for(int i = 0;i < n;i++) scanf("%d", &a[i]);

	sort(ALL(a));

	int mx = 1;

	a[0] = 1;

	for(int i = 1;i < n;i++) {
		a[i] = min(a[i], mx + 1);
		mx = max(mx, a[i]);
	}

	printf("%d\n", mx + 1);

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}