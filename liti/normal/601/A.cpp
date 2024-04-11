//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 400 + 10; 
int a[maxN][maxN]; 
int que[maxN]; 
int d[maxN];

int main() {
	int n,m; 
	cin >> n >> m; 
	for( int i = 0 ; i < m ; i++ ) {
		int u,v; cin >> u >> v; 
		u--; v--; 
		a[u][v] = a[v][u] = 1; 
	}
	if( a[0][n-1] == 1 ) { 
		for( int i = 0 ; i < n ; i++ ) 
			for( int j = 0 ; j < n ; j++ ) 
				if( i != j ) a[i][j] ^= 1; 
	}
	int en = 0; 
	que[en++] = 0;
	memset( d , -1 , sizeof d ) ; 
	d[0] = 0; 
	for( int i = 0 ; i < en ; i++ ) { 
		int s = que[i]; 
		if( s == n - 1 ) { 
			cout << d[s] << endl;
			return 0; 
		}
		for( int j = 0 ; j < n ; j++ ) if( d[j] == -1 && a[s][j] ) { 
			d[j] = d[s] + 1; 
			que[en++] = j; 
		}
	}
	cout << -1 << endl;
}