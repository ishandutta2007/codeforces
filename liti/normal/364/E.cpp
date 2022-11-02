//In the name of Allah
#include <iostream>
#include <cstdio>
using namespace std;

const int maxN = 2500 + 10; 
typedef long long ll;

char a[2][maxN][maxN]; 
int psum[2][maxN][maxN];
int nxu[2][maxN][maxN], nxd[2][maxN][maxN]; 

int k; 
ll ans; 
int up[10], down[10]; 
inline int gg( int t , int i1 , int j1 , int i2 , int j2 ) {
	return psum[t][i2][j2] - psum[t][i1][j2] - psum[t][i2][j1] + psum[t][i1][j1]; 
}

void solve( int t , int i1 , int j1 , int i2 , int j2 ) { 
	if( j2 - j1 > i2 - i2 ) { 
		swap( i2 , j2 ) ; 
		swap( i1 , j1 ) ; 
		t ^= 1; 
	}
	if( j2 - j1 == 0 ) return; 
	int mid = (i1 + i2) / 2; 

	for( int s = j1 ; s < j2 ; s++ ) { 
		up[0] = mid , down[0] = mid ; 
		for( int i = 1 ; i<= k ; i++ ) 
			up[i] = i1 - 1 , down[i] = i2; 
		for( int e = s ; e < j2 ; e++ ) { 
			int curr = gg( t , mid , s , mid + 1 , e + 1 ); 
			if( curr >= k ) break; 

			for( int i = 1 ; i <= k - curr ; i++ ) { 
				int lo = up[i] , hi = up[i-1]+1; 
				while( hi - lo > 1 ) { 
					int mi = (lo+hi)/2; 
					if( gg( t , mi , s , mid , e+1 ) >= i ) 
						lo = mi; 
					else 
						hi = mi; 
				}
				up[i] = lo;

				lo = down[i-1]-1 , hi = down[i]; 
				while( hi - lo > 1 ) { 
					int mi = (lo+hi)/2; 
					if( gg( t , mid+1 , s , mi + 1 , e + 1 ) >= i )
						hi = mi;
					else
						lo = mi; 
				}
				down[i] = hi; 
			} 

			for( int i = 0 ; i < k - curr ; i++ ) { 
				int j = k - curr - i - 1; 
				int f = up[i] - up[i+1]; 
				int s = down[j+1] - down[j]; 
				ans += s * f; 
			}
		}
	}

	solve( t , i1 , j1 , mid , j2 ); 
	solve( t , mid + 1 , j1 , i2 , j2 ); 
}

int main() { 
	int n,m;
	scanf("%d%d%d",&n,&m,&k);
	k++; 

	for( int i = 0 ; i < n ; i++ ) { 
		scanf("%s",a[0][i]); 
	}
	for( int i = 0 ; i < m ; i++ ) { 
		for( int j = 0 ; j < n ; j++ )
			a[1][i][j] = a[0][j][i]; 
	}

	for( int t = 0 ; t < 2 ; t++ ) { 
		for( int i = 0 ; i < n ; i++ ) 
			for( int j = 0 ; j < m ; j++ ) { 
				if( i == 0 ) nxu[t][i][j] = -1; 
				else if( a[t][i-1][j] == '1' ) 
					nxu[t][i][j] = i - 1; 
				else
				   	nxu[t][i][j] = nxu[t][i-1][j]; 
				psum[t][i+1][j+1] = psum[t][i+1][j] + psum[t][i][j+1] - psum[t][i][j] + a[t][i][j] - '0';
			}
		for( int i = n - 1 ; i >= 0 ; i-- ) 
			for( int j = 0 ; j < m ; j++ ) 
				if( i == n - 1 ) nxd[t][i][j] = -1; 
				else if( a[t][i+1][j] == '1' ) 
					nxd[t][i][j] = i + 1; 
				else
					nxd[t][i][j] = nxd[t][i+1][j]; 
		swap( m , n ); 
	}

	solve( 0 , 0 , 0 , n , m ); 

	cout << ans << endl;
}