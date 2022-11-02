/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 100 + 10;
string a[maxN];
vector<int> c[26];

void doJob( int s , int e , int k ) { 
	if( e - s <= 1 ) return;
	//cerr << s << ' ' << e << ' ' << k << endl;
	int last = -1;
	int cnt = 0;
	for( int i = s ; i < e ; i++ ) 
		if( a[i].size() <= k ) {
			cnt++;
			last= i;
		}
	if( cnt > 0 && last + 1 - s != cnt ) {
		cout << "Impossible" << endl;
		exit(0);
	}
	last = max(s,last+1);
	for( int i = last + 1  ; i < e  ; i++ ) 
		if( a[i][k] != a[i-1][k] ) {
			doJob( last , i , k + 1 );
			last = i;
			c[a[i-1][k]-'a'].push_back( a[i][k] - 'a' ) ; 
		}
	doJob( last , e , k + 1 );
}

vector<int> ans;
int mark[26];
void dfs( int s ) { 
	mark[s] = 1;
	for( auto x : c[s] ) 
		if( !mark[x] ) 
			dfs( x ) ;
		else if( mark[x] == 1 ) { 
			cout << "Impossible" << endl;
			exit(0);
		}
	mark[s] = 2;
	ans.push_back( s ) ;
}

int main()  { 
	int n;
	cin >> n ;
	for( int i = 0 ;i < n ; i++ ) 
		cin >> a[i];

	doJob( 0 , n , 0 );
	for( int i = 0 ; i < 26 ; i++ ) 
		if( !mark[i] ) 
			dfs(i);
	reverse(ans.begin(),ans.end());
	for( int i = 0 ; i < 26 ; i++ ) 
		cout << char( ans[i] + 'a' )  ;
	cout << endl;
}