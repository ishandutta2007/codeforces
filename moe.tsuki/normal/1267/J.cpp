#include <bits/stdc++.h>
using namespace std;
const int N = 2000000 + 5;

int n, a[ N ], cnt[ N ];
int tot[ N ], step[ N ], step_;
void solve() {
	step_ ++; cin >> n;
	for ( int i = 0 ; i < n ; ++ i )
		cin >> a[ i ];
	for ( int i = 0 ; i < n ; ++ i )
		cnt[ a[ i ] ]++;
	vector< int > chk;
	for ( int i = 0 ; i < n ; ++ i ) {
		if ( step[ a[ i ] ] == step_ )
			continue;
		step[ a[ i ] ] = step_;
		if ( ++ tot[ cnt[ a[ i ] ] ] == 1 )
			chk.push_back( cnt[ a[ i ] ] );
	}
	int ans = 1 << 30;
	{
		int x = n;
		bool valid = true;
		int sum = 0;
		for ( int b : chk ) {
			// k * ( x - 1 ) <= b <= k * x
			int k = ( b + x - 1 ) / x;
			valid &= ( k * ( x - 1 ) <= b and b <= x * k );
			sum += k * tot[ b ];
		}
		if ( valid ) ans = min( ans, sum );
	}
	int REP = 0;
	while ( REP != n ) {
		int nREP = n / ( n / ( REP + 1 ) );
		{
			int x = REP;
			int S = n / nREP + 1;
			if ( S * ( x - 1 ) <= n and n <= S * x ) {
				bool valid = true;
				int sum = 0;
				for ( int b : chk ) {
					// k * ( x - 1 ) <= b <= k * x
					int k = ( b + x - 1 ) / x;
					valid &= ( k * ( x - 1 ) <= b and b <= x * k );
					sum += k * tot[ b ];
				}
				if ( valid ) ans = min( ans, sum );
			}
		}
		{
			int x = REP + 1;
			int S = n / nREP + 1;
			if ( S * ( x - 1 ) <= n and n <= S * x ) {
				bool valid = true;
				int sum = 0;
				for ( int b : chk ) {
					int k = ( b + x - 1 ) / x;
					valid &= ( k * ( x - 1 ) <= b and b <= x * k );
					sum += k * tot[ b ];
				}
				if ( valid ) ans = min( ans, sum );
			}
		}
		REP = nREP;
	}
	cout << ans << '\n';
}

void clear() {
	for ( int i = 0 ; i < n ; ++ i ) {
		tot[ cnt[ a[ i ] ] ] = 0;
		cnt[ a[ i ] ] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio( false );
	cin.tie( nullptr );
	int t; cin >> t;
	while ( t -- ) {
		solve();
		clear();
	}
	return 0;
}