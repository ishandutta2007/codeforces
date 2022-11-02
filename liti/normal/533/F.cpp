/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 2*1000*100 + 100;
int match[26][maxN];
int nex[maxN];
int mark[maxN];

char x , y ; 
inline bool ch( char a , char b ) { 
	if( a == x ) 
		return b == y;
	if( a == y ) 
		return b == x; 
	return b != x && b != y;
}
inline bool ch1( char a , char b ) { 
	if( a == x ) 
		return b == x; 
	if( a == y ) 
		return b == y;
	return b != x && b != y ; 
}

vector<int> ans;
int main() { 
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m; 

	memset( match , -1 , sizeof match ) ; 
	string s,t;
	cin >> s >> t; 

	for( int i = 0 ; i < 26 ; i++ )  
		for( int j = i ; j < 26 ; j++ ) { 
			x = 'a' + i , y = 'a' + j;
			int cnt = 0;
			for( int k = 1 ; k < m ; k++ ) { 
				while( cnt && ch1( t[cnt] , t[k] ) == 0 ) 
					cnt = nex[cnt];
				if( ch1( t[cnt] , t[k] ) ) 
					cnt++;
				nex[k+1] = cnt;
			}
			cnt = 0;
			for( int k = 0 ; k < n ; k++ ) {
				while( cnt && ch( t[cnt] , s[k] ) == 0 ) 
					cnt = nex[cnt];
				if( ch( t[cnt] , s[k] ) ) 
					cnt++;
				if( cnt == m ) {
					if( match[i][k-m+1] == -1 ) {
						match[i][k-m+1] = j , match[j][k-m+1] = i;
//						if( j < 2 ) cerr << i << ' ' << j << ' ' << k - m + 1 << ' ' << nex[2] << endl;
					}
					cnt = nex[cnt];
				}
			}
		}

	for( int i = 0 ; i <= n - m ; i++ ) {
		bool cfg = true;
		for( int j = 0 ; j < 26 ; j++ ) 
			if( mark[j] != i + 1 ) {
				if ( match[j][i] != -1 ) 
					mark[match[j][i]] = i + 1;
				else{
					cfg = false;
					break;
				}
			}
		if( cfg ) 
			ans.push_back( i + 1 ) ; 
	}
	cout << sz(ans) << '\n';
	for( int i = 0 ; i < sz(ans) ; i++ ) 
		cout << ans[i] << ' ';
	cout << '\n';
}