//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

ll x[3][26];
void calc( ll* a , string s ) { 
	for( auto x : s ) 
		a[x-'a']++;
}
ll p[26];
string a,b,c; 

inline pair<int,int> doJob( int k , bool pr = 0 ) { 
	// x from b 
	for( int i = 0 ; i < 26 ; i++ ) 
		p[i] = x[0][i]; 
	ll mx = 1000*1000 + 10;
	for( int i = 0 ; i < 26 ; i++ ) {
		p[i] -= k * x[1][i]; 
		if( p[i] < 0 ) return {-1,-1}; 
		if( x[2][i] > 0 ) 
			mx = min( mx , p[i] / x[2][i] ) ; 
	}
	for( int i = 0 ; i < 26 ; i++ ) 
		p[i] -= mx * x[2][i];
	if( pr ) { 
		for( int i = 0 ; i < k ; i++ ) 
			cout <<b ; 
		for( int i = 0 ; i < mx ; i++ ) 
			cout << c; 
		for( int i = 0 ; i < 26 ; i++ ) 
			for( int j = 0 ; j < p[i] ; j++ ) 
				cout << char( i + 'a' ) ; 
		cout << endl;
	}
	return { mx + k , k } ; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> c; 
//	for( int i = 0 ; i < 1000*100 ; i++ ) 
//		a += 'a';
//	b = c= a ;
	calc( x[0] , a ) ; 
	calc( x[1] , b ) ; 
	calc( x[2] , c ) ; 

	pair<int,int> ans = {-1,-1};
	for( int i = 0 ; i <= __sz(a) ; i++ ) {
		ans = max( ans , doJob(i) ) ; 
	}
	doJob( ans.second , 1 ) ; 
}