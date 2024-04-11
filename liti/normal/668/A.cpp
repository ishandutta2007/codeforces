//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 100 + 10; 
int a[maxN][maxN]; 

int n,m,q; 
void solve( int q ) { 
	if( q == 0 ) return; 
	int t; cin >> t; 
	int x,y,v; 
	if( t <= 2 ) cin >> x; 
	else cin >> x >> y >> v; 
	solve( q - 1 ) ; 
	x--; y--;
	if( t == 1 ) { 
		int tmp = a[x][m-1]; 
		for( int j = m - 2 ; j >= 0 ; j-- ) 
			a[x][j+1] = a[x][j]; 
		a[x][0] = tmp; 
	} else if ( t == 2 ) { 
		int tmp = a[n-1][x]; 
		for( int i = n - 2 ; i >= 0 ; i-- ) 
			a[i+1][x] = a[i][x]; 
		a[0][x] = tmp; 
	} else
		a[x][y] = v; 
}

int main() { 
	cin >> n >> m >> q;
	solve( q ) ; 
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < m ; j++ ) 
			cout << a[i][j] << " \n"[j==m-1];
}