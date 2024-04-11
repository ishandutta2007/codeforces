//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
const int maxN = 3 * 1000 * 100 + 100;
const ll base = 701;
ll h1[maxN],h2[maxN],tav[maxN];
string a,b;
ll g1( int s , int e ) { 
	return h1[e] - h1[s] * tav[e-s]; 
}
ll g2( int s , int e ) { 
	return h2[e] - h2[s] * tav[e-s]; 
}

bool solve( int s1 , int e1 , int s2 , int e2 ) { 
	if( g1( s1 , e1 )  == g2( s2 , e2 ) ) 
		return true;
	if( ( e1 - s1 ) & 1 ) return false;
	int m1 = (s1+e1)/2, m2 = (s2+e2)/2;
	bool c1 = solve( s1 , m1 , s2 , m2 ) ; 
	bool c2 = (!c1?0:solve( m1 , e1 , m2 , e2 )) ; 
	if( c1 && c2 ) return true;
	bool c3 = solve( s1 , m1 , m2 , e2 ) ; 
	if( !c3 ) return false;
	if( c1 ) return false;
	return solve( m1 , e1 , s2 , m2 ) ; 
}

int main() { 
	ios::sync_with_stdio(false);
	cin >> a >> b;
	int n = __sz(a);
	tav[0] = 1;
	for( int i = 0 ; i < n ; i++ ) { 
		h1[i+1] = h1[i] * base + a[i] - 'a';
		h2[i+1] = h2[i] * base + b[i] - 'a';
		tav[i+1] = tav[i] * base;
	}
	cout << (solve(0,n,0,n)?"YES":"NO") << endl;
}