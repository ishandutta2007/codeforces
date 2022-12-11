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

const int MAXN = 40;
const int MAXM = 11;

int n, m, correct[ MAXM ], uncorrect[ MAXM ], answer = 0;
char s[ MAXM ][ MAXN ]; 

void rec( int pos ) {
	if ( pos == n + 1 ) {
		answer += 1;
		return;
	}
	for ( char c = '0'; c <= '1'; c++ ) {
		bool flag = true;
		for ( int i = 1; i <= m; i++ ) {
			if ( s[i][pos] == c &&   correct[i] == 0 ) flag = false;
			if ( s[i][pos] != c && uncorrect[i] == 0 ) flag = false;
		}
		if ( flag ) {
			for ( int i = 1; i <= m; i++ ) {
				if ( s[i][pos] == c )   correct[i] -= 1;
				if ( s[i][pos] != c ) uncorrect[i] -= 1;
			}
			rec( pos + 1 );
			for ( int i = 1; i <= m; i++ ) {
				if ( s[i][pos] == c )   correct[i] += 1;
				if ( s[i][pos] != c ) uncorrect[i] += 1;
			}
		}
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for ( int i = 1; i <= m; i++ ) scanf("%s%d", s[i] + 1, &correct[i]), uncorrect[i] = n - correct[i];
	rec( 1 );
	printf("%d\n", answer);
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}