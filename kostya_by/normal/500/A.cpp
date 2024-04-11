#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 30300;

int n, t, a[ MAXN ];

void solve() {
	scanf("%d%d", &n, &t);
	for ( int i = 1; i < n; i++ ) scanf("%d", &a[i]);
	int st = 1;
	while ( true ) {
		if ( st == t ) {
			printf("YES\n");
			return;
		}
		if ( st > t ) {
			printf("NO\n");
			return;
		}
		if ( st == n ) break;
		st += a[ st ]; 
	}
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}