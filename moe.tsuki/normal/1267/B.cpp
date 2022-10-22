#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio( false );
	cin.tie( nullptr );
	string S; cin >> S;
	const int n = static_cast< int >( S.size() );
	deque< pair< char, int > > dq;
	for ( int i = 0 ; i < n ; ++ i ) {
		if ( dq.empty() or dq.back().first != S[ i ] )
			dq.emplace_back( S[ i ], 1 );
		else dq.back().second ++;
	}
	if ( dq.size() & 1 ) {
		while ( dq.size() > 1 ) {
			auto fi = dq.front(); dq.pop_front();
			auto se = dq.back(); dq.pop_back();
			if ( fi.first != se.first ) {
				cout << 0 << '\n';
				return 0;
			} else if ( fi.second + se.second < 3 ) {
				cout << 0 << '\n';
				return 0;
			}
		}
		if ( dq[ 0 ].second < 2 ) cout << 0 << '\n';
		else cout << dq[ 0 ].second + 1 << '\n';
	} else cout << 0 << '\n';
	return 0;
}