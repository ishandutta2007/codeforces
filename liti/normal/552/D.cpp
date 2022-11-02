//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 2000 + 10; 
#define X first
#define Y second

pair<int,int> a[maxN];
map<pair<int,int>,int> cnt; 

int gcd( int a , int b ) { 
	if( b == 0 ) 
		return a; 
	return gcd( b , a % b ) ; 
}

int main() { 
	int n; 
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i].first >> a[i].second;
	ll ans = 0; 
	for( int i =0 ; i < n ; i++ ) {
		cnt.clear(); 
		for( int j = i + 1 ; j < n ; j++ ) { 
			int dx = ( a[j].X - a[i].X ) , 
				dy = ( a[j].Y - a[i].Y ) ; 
			if( dx < 0 ) 
				dx *= -1 , dy *= -1;
			if( dx == 0 ) dy = abs(dy) ; 
			int x = gcd( abs(dx) , abs(dy) ) ; 
			cnt[ make_pair( dx / x , dy / x ) ]++;
		}
		int num = n - i - 1; 
		for( auto it : cnt ) 
			ans += it.second * 1ll * ( num - it.second ) ; 
	}
	cout << ans/2 << endl;
}