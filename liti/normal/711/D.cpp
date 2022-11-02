//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 2 * 1000 * 100 + 100; 
const int mod = 1e9 + 7; 
inline int mul( int a , int b ) { 
	return a * 1ll * b % mod; 
}
inline int sum( int a , int b ) { 
	return ( (a+b)%mod + mod ) % mod; 
}

int a[maxN]; 

int mark[maxN]; 
int tav[maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n; 
	for( int i =0 ; i < n ; i++ ) { 
		cin >> a[i]; 
		a[i]--; 
	}
	tav[0] = 1; 
	for( int i = 1 ; i < maxN ; i++ ) 
		tav[i] = mul(tav[i-1],2); 

	int good = 0; 
	int z = 1; 
	for( int i = 0 ; i < n ; i++ ) 
		if( !mark[i] ) { 
			int cnt = 1; 
			int x = i; 
			while( !mark[x] ) { 
				mark[x] = cnt++; 
				x = a[x];
			}  
			if( mark[x] == -1 ) 
				good += cnt-1; 
			else { 
				good += mark[x]-1; 
				z = mul( z , sum( tav[ cnt - mark[x] ] , -2 ) ); 
			}
			x = i; 
			while( mark[x] != -1 ) {
				mark[x] = -1; 
				x = a[x];
			} 
		}



	cout << mul( z , tav[good] ) << endl; 
}