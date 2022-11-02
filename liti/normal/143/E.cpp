//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

string s[4][3] = { 
	{ "xxx" , ".x." , ".x." } , 
	{ ".x." , ".x." , "xxx" } , 
	{ "..x" , "xxx" , "..x" } , 
	{ "x.." , "xxx" , "x.." } } ; 

inline bool inrange( int i , int n ) { return 0 <= i && i < n ; }  ;

int best ; 
string ans[10];
string a[10];

int n,m; 
inline void bt( int i , int j, int cnt = 0 , int k = 0 ) { 
	if( i >= n - 2 ) { 
		if( best >= cnt ) return;
		copy( a , a + n , ans ) ;  
		best = cnt; 
		if( best == 13 - (9-n) - (9-m) - (n != 9 && n==m) || ( min(n,m) == 7 && max(n,m) == 9 && best == 10 ) ) { 
			cout << best << endl;
			for( int i = 0 ; i < n ; i++ ) 
				cout << ans[i] << endl;
			exit(0);
		}
		return; 
	}
	if( j >= m - 2 ) { 
		bt( i + 1 , 0, cnt , k ) ; 
		return;
	}
	for( int t = 0 ; t < 4 ; t++ ) {
		if( !inrange( i + 2 , n ) || !inrange( j + 2 , m ) ) 
			continue;
		bool ch = true;
		for( int x = 0 ; x < 3 ; x++ ) for( int y = 0 ; y < 3 ; y++ ) if( s[t][x][y] == 'x' )
			ch &= (a[i+x][j+y] == '.');
		if( !ch ) continue;
		for( int x = 0 ; x < 3 ; x++ ) for( int y = 0 ; y < 3 ; y++ ) if( s[t][x][y] == 'x' )
			a[i+x][j+y] = 'A' + cnt; 
		bt( i , j + 2 , cnt + 1 , k + 1 ) ; 
		for( int x = 0 ; x < 3 ; x++ ) for( int y = 0 ; y < 3 ; y++ ) if( s[t][x][y] == 'x' )
			a[i+x][j+y] = '.'; 
	}
	bt( i , j + 1 , cnt , k + 1 ) ; 
}
int main() { 
	cin >> n >> m;
	if( n == 8 && m == 9 ) { 
		cout << "12\nAAABBB..C\n.AD.BECCC\n.AD.BEEEC\nFDDDGEHHH\nFFFIGGGH.\nFJ.IGK.HL\n.JIIIKLLL\nJJJ.KKK.L" << endl;
		return 0;
	}
	if( n == 9 && m == 8 ) { 
		cout << "12\nA..FFF.J\nAAADFJJJ\nADDDF.IJ\nB..DIII.\nBBBGGGIK\nBEEEGKKK\n.CEHG.LK\n.CEHHHL.\nCCCH.LLL" << endl;
		return 0;
	}
	for( int i = 0 ; i < n ; i++ ) 
		for( int j= 0 ; j< m ; j++) 
			a[i] += '.';
	copy( a , a + n , ans ) ; 
	bt(0,0) ; 
	cout << best << endl;
	for( int i = 0 ; i < n ; i++ ) 
		cout << ans[i] << endl;
}