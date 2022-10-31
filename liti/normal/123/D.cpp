/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> Str;

const int maxN = 100*100*10 + 10;
const ll h_base = 701;

ll tav[maxN];
ll h[maxN];
string s;
Str s_array[maxN]; //Suffix array

//Solving part
stack<pair<int,int> > curr; //denoting to { val , start } 

int lcp( Str a , Str b ) {
	if( s[a.first] != s[b.first] ) 
		return -1;

	int s = 0 , e = min( a.second - a.first , b.second - b.first ) ;
	while( e - s > 1 ) { 
		int m = ( s + e ) / 2;

		int v1 = h[a.first+m] - h[a.first]*tav[m];
		int v2 = h[b.first+m] - h[b.first]*tav[m];

		if( v1 == v2 ) 
			s = m;
		else
			e = m;
	}

	return s;
}

bool cmp( Str a , Str b ) { 
	int eq = lcp( a , b ) ; 
	return s[a.first+eq+1] < s[b.first+eq+1] ; // Here it's not possible that they point to end of string
}

int main() { 
	tav[0] = 1;
	for( int i = 1 ; i < maxN ; i++ ) 
		tav[i] = tav[i-1]*h_base;
	
	cin >> s;

	int n = s.size();

	for( int i = 0 ; i < n ; i++ ) 
		h[i] = (i?h[i-1]*h_base:0) + (s[i]-'a');

	for( int i = 0 ; i < n ; i++ ) 
		s_array[i] = Str( i , n )  ; 
	sort( s_array , s_array + n , cmp ) ;

	//solving part
	ll ans = 0;

	for( int i = 0 ; i < n ; i++ ) { 
		curr.push( { n - s_array[i].first , i } ) ;
	
		if( i == n - 1 ) 
			continue;

		int x = lcp( s_array[i] , s_array[i+1] ) + 1 ;
	//	cerr << x << endl;
		int lVal = i + 1 ;
		while( !curr.empty() && curr.top().first >= x ) {
			int w = i + 1 - curr.top().second;
			lVal = curr.top().second;
			int h = curr.top().first ;
			curr.pop();
			h = min( h - x , ( !curr.empty() ? h - curr.top().first : h ) );

	//		cerr << "?"  << w << ' ' << h << endl;
			ans += 1LL*w*(w+1)/2*h;
		}
		curr.push( { x , lVal } ) ;
	}

	while( !curr.empty() ) {
		int w = n  - curr.top().second;
		int h = curr.top().first;
	//	cerr << "!" << h << endl;
		curr.pop();
		if( !curr.empty() ) 
			h -= curr.top().first;
	//	cerr << "!" << w << ' ' << h << endl;
		ans += 1LL*w*(w+1)/2*h;
	}

	cout << ans << endl;
}