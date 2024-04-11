/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 4*1000*100 + 100; 


int a[maxN];
pair<int,int> b[maxN]; 
int place[maxN];

set<pair<int,int>> curr; 

int main() { 
	int n,k;
	scanf( "%d%d" , &n , &k ) ;

	for( int i =0 ; i < n ; i++ ) {
		scanf( "%d" , a + i ) ; 
		b[i] = { a[i] , i } ; 
	}
	sort( b , b + n ) ; 
	for( int i = 0 ; i < n ; i++ ) 
		place[b[i].second] = i; 

	int last = 0; 
	for( int i = 0 ; i <= n ; i++ ) 
		if( i == n || b[i].first != b[i-1].first ) { 
			int v = b[i-1].first;
			if( last + k <= i ) 
				curr.insert( {b[last+k-1].second,v} ) ; 
			last = i; 
		}

	ll ans = 0;
	for( int i = 0 ; i < n ; i++ ) { 
		if( curr.empty() ) 
			break;
		int v = curr.begin()->first; 
		ans += n - v; 
		if( place[i] + k - 1 < n && b[place[i]+k-1].first == a[i] ) { 
			curr.erase( { b[place[i] + k - 1].second , a[i] } );
			if( place[i] + k < n && b[place[i]+k].first == a[i] ) 
				curr.insert( { b[place[i] + k].second , a[i] } ) ; 
		}
	}
	cout << ans << endl;
}