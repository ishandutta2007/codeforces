//In the name of Allah
#include <bits/stdc++.h>

using namespace std;
#define __sz(x) ((int) x.size())
typedef long long ll;

const int maxN = 2 * 1000 * 100 + 100;
int a[maxN];
int b[maxN]; 
int mark[maxN] , mx[maxN], val[2*maxN];

void ss( int n ) { 
	for( int i = 0 ; i < n ; i++ ) 
		b[val[i]]++; 
	int ind = 0;
	for( int i = n - 1 ; i >= 0 ; i-- ) 
		for( ; b[i] ; b[i]-- ) val[ind++] = i;
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 

	ll ans = 0;
	for( int i = 1 ; i < n ; i++ )
		if( n % i == 0 ) { 
			for( int k = 0 ; k < i ; k++ ) 
				mx[k] = 0; 
			for( int k = 0 ; k < i ; k++ ) 
				for( int j = k ; j < n ; j += i ) 
					mx[k] = max( mx[k] , a[j] ) ; 
			for( int j = 0 ; j < n ; j++ ) 
				if( a[j] == mx[j%i] ) mark[j] = 1;
				else mark[j] = 0;

			for( int i = 2*n - 1 ; i >= 0 ; i-- ) 
				if( mark[i%n] ) 
					val[i] = min(n,1 + val[i+1]);
				else val[i] = 0;
			ss(n);


			for( int j = i ; j < n ; j += i ) 
				if( __gcd( j , n ) == i ) 
					ans += upper_bound( val , val + n , j , greater<int>() ) - val;
		}
	cout << ans << endl;
}