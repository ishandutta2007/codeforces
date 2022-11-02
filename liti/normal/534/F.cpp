/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

int a[5], b[20];

set<vector<int>> state[21];
char ans[5][20];

int n,m;
void doJob( int y , vector<int>& curr ) { 
	if( y == m ) { 
		for( int i = 0 ; i < n ; i++ ) 
			if( a[i] != curr[i] ) 
				return;
		for( int i = 0 ; i < n ; i++ ){
			for( int j = 0 ; j < m ; j++ ) 
				cout << ans[i][j]; 
			cout << endl;
		}
		exit(0);
	}
	if( state[y].find( curr ) != state[y].end() ) 
		return;
	for( int mask = 0 ; mask < (1<<n) ; mask++ ) {
		for( int x = 0 ; x < n ; x++ ) 
			ans[x][y] = ( mask & (1<<x) ) ? '*' : '.';
		int cnt = 0; 
		for( int x = 0 ; x < n ; x++ ) 
			if( ans[x][y] == '*' && ( x == 0 || ans[x-1][y] == '.' ) ) cnt++;
		if( cnt != b[y] ) continue;
		vector<int> nc = curr;
		bool flag = true;
		for( int x = 0 ; x < n ; x++ ) {
			if( ans[x][y] == '*' && ( y == 0 || ans[x][y-1] == '.' ) ) nc[x]++;
			if( nc[x] > a[x] || (m - y)/2 + nc[x] < a[x]  ) { 
				flag = false;
				break;
			}
		}
		nc.back() = mask;
		if( flag ) 
			doJob( y + 1 , nc ) ; 
	}
	state[y].insert( curr ) ; 
}

int main() { 
	cin >> n >> m; 

	for( int i= 0 ; i < n ; i++ ) 
		cin >> a[i];
	for( int i = 0 ; i < m ; i++ ) 
		cin >> b[i]; 

	auto tmp = vector<int>( n + 1 , 0 ) ;
	doJob( 0 , tmp  ) ; 
	return 0;
}