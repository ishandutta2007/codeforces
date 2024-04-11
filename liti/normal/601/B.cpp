//In the name of allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000*100 + 100;
int a[maxN]; 
int b[maxN]; 
int que[maxN];
int L[maxN],R[maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n,q; 
	cin >> n >> q; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	for( int i = 0 ; i < n - 1 ; i++ ) 
		b[i] = abs(a[i] - a[i+1]); 

	int en = 0; 
	for( int i = 0 ; i < n - 1 ; i++ ) { 
		while( en && b[que[en-1]] < b[i] ) en--; 
		if( en == 0 ) L[i] = -1; 
		else L[i] = que[en-1]; 
		que[en++] = i; 
	}
	en = 0;
	for( int i = n - 2 ; i >= 0 ; i-- ) { 
		while( en && b[que[en-1]] <= b[i] ) en--; 
		if( en == 0 ) R[i] = n - 1; 
		else R[i] = que[en-1]; 
		que[en++] = i; 
	}

	
	for( int i = 0 ; i < q ; i++ ) { 
		int l,r; cin >> l >> r; 
		l--; 
		if( r - l == 1 ) cout << 0 << '\n';
		else { 
			r--; 
			long long ans = 0; 
			for( int j = l ; j < r ; j++ ) { 
				ans += ( min( r , R[j] ) - j ) *1ll 
					* (j - max( l - 1 , L[j] )) * 1LL * b[j]; 
			}
			cout << ans << '\n';
		}
	}
}