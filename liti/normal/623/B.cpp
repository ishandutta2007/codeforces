//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 1000 * 1000 + 100; 
int a[maxN]; 

ll ans; 
int dp[maxN];
int sum[maxN]; 

int n,A,B;

ll solve( int x ) { 
	int st = -1 , en = -1; 
	bool flag = false;
	for( int i = 1 ; i < n ; i++ ) { 
		if( a[i] % x == 0 ) 
			dp[i] = 0; 
		else if( ( (a[i] + 1) % x == 0 ) || 
				( (a[i] - 1) % x == 0 ) )
			dp[i] = 1 ;
		else { 
			//cerr << "SHIT " << i << endl;
			dp[i] = 2; 
			en = i; 
			if( st == -1 ) st = i; 
			flag = true;
		}
		sum[i+1] = sum[i] + (dp[i]!=0);
	}
	// For a [j,i) -> min total cost - ( sum[i] - sum[j] ) * b + ( i - j ) * a 
	// -> total cost   - sum[i] * b + i * a    + sum[j] * b - j * a 
	// -> for fixed i -> minimize( sum[j] * b -j * a ) 
	ll tot = sum[n] *1ll* B; 
//	cerr << tot << endl;
	ll mn = 0; 
	ll ret = ll(1e9) * ll(1e8); 
	if( !flag ) ret = tot;
	for( int i = 1 ; i <= n ; i++ ) { 
		if( i > en || en == -1 ) 
			ret = min( ret , tot + mn - sum[i] * ll(B) + i * ll(A) ); 
//		cerr << i <<  ' ' << ret << endl;
		if( i == n ) continue;
		if( i <= st || st == -1 ) 
			mn = min( mn , sum[i] * 1ll * B - i * 1ll * A  ); 
	}
/*	cerr << "FOR " << x << endl;
	cerr << st << ' ' << en << endl;
	for( int i = 0 ; i < n ; i++ ) 
		cerr << a[i] << " \n"[i==n-1]; 
	cerr << "And the answer is " << ret << endl;
	*/
	return ret; 
}

int main() { 
	ios::sync_with_stdio(false); 
	cin >> n >> A >> B; 

	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 

	ll ans = ll(1e9) * ll(1e7); 
	for( int t = 0 ; t < 2 ; t++ ) { 
		for( int v = a[0] - 1 ; v < a[0] + 2 ; v++ ) { 
			int x = v; 
			for( int i = 2 ; i * i <= x ; i++ ) 
				if( x % i == 0 ) { 
					ans = min( ans , solve( i ) + (v!=a[0])*B ); 
					while( x % i == 0 ) x /= i; 
				}
			if( x > 1 ) 
				ans = min( ans , solve( x ) + (v!=a[0])*B ); 
		}
		reverse( a , a + n ); 
	}
	cout << ans << '\n'; 
}