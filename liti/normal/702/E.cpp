//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 100 * 1000 + 100; 
const int maxL = 40; 

int nex[maxN][maxL], mn[maxN][maxL]; 
ll sum[maxN][maxL];

int main() { 
	ios::sync_with_stdio(false); 
	int n; 
	ll t; 
	cin >> n >> t; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> nex[i][0] ; 
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> mn[i][0] ; 
		sum[i][0] = mn[i][0]; 
	}
	for( int k = 1 ; k < maxL ; k++ ) 
		for( int i = 0 ; i < n ; i++ ) { 
			nex[i][k] = nex[nex[i][k-1]][k-1]; 
			sum[i][k] = sum[i][k-1] + sum[nex[i][k-1]][k-1]; 
			mn[i][k] = min( mn[i][k-1] , mn[nex[i][k-1]][k-1] ); 
		}

	for( int i = 0 ; i < n ; i++ ) { 
		int x = i; 
		ll s = 0; 
		int m = 1000 * 1000 * 1000 + 10; 
		for( int k = maxL - 1 ; k >= 0 ; k-- ) 
			if( (t>>k) & 1ll ) { 
				s += sum[x][k]; 
				m = min( m , mn[x][k] ); 
				x = nex[x][k]; 
			}
		cout << s << ' ' << m << '\n'; 
	}
}