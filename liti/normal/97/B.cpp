//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

typedef pair<int,int> P; 

const int maxN = 1000 * 100 + 100; 
P a[maxN];
vector<P> ans;
vector<int> Y; 

void doJob( int s , int e ) {  
	if( e - s < 2 ) return;
	int j ;
	int m = ( e - s ) / 2;
	Y.clear();
	for( int i = s ; i < e ; i++ ) 
		Y.push_back( a[i].second ) ; 
	sort( Y.begin() , Y.end() ) ; 
	Y.resize( unique(Y.begin(),Y.end()) - Y.begin()); 
	for( int i = s ; i < e ; i = j ) { 
		for( j = i ; j < e ; j++ ) if( a[i].first != a[j].first ) 
			break;
		int left = i - s;
		int right = e - j; 
		if( left <= m && right <= m ) { 
			for( auto y : Y ) ans.push_back( { a[i].first , y } ) ; 
			doJob( s , i ) ; 
			doJob( j , e ) ; 
			return;
		}
	}
	assert( false ) ; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n; 
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i].first >> a[i].second;
		ans.push_back( a[i] ) ; 
	}
	sort( a , a + n ) ;
	doJob( 0 , n ) ; 

	sort( ans.begin() , ans.end() ) ;
	ans.resize( unique(ans.begin(),ans.end()) - ans.begin() ) ; 
	cout << __sz(ans) << '\n';
	for( int i = 0 ; i < __sz(ans) ; i++ ) 
		cout << ans[i].first << ' ' << ans[i].second << '\n';
}