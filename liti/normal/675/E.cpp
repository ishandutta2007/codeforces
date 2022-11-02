//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 
const int maxN = 100 * 1000 + 100; 

int a[maxN]; 
pii mx[4*maxN]; 
int n; 
void build( int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr - xl == 1 ) { 
		mx[ind] = {a[xl],xl}; 
		return; 
	}
	int xm = (xl+xr)/2;
	build( xl , xm , ind * 2 ) ; 
	build( xm , xr , ind * 2 + 1 ); 
	mx[ind] = max( mx[ind*2] , mx[ind*2+1] );
} 
pii gVal( int ql , int qr , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return {-1,-1}; 
	if( ql <= xl && xr <= qr ) return mx[ind]; 
	int xm = (xl+xr)/2; 
	return max( gVal( ql , qr , xl , xm , ind * 2 ) , 
			gVal( ql , qr , xm , xr , ind * 2 + 1 ) ); 

}

ll dp[maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); //XXX remember scanf
	cin >> n; 
	ll ans = 0 ; 
	for( int i = 0 ; i < n - 1 ; i++ ) 
		cin >> a[i]; 
	build(); 
	for( int i = n - 2 ; i >= 0 ; i-- ) { 
		int ql = i+1 , qr = a[i]; 
		if( qr == n ) { 
			dp[i] = n - i - 1; 
			ans += dp[i];
			continue; 
		}
		pii ret = gVal( ql , qr ); 
		int ind = ret.second;
		dp[i] = dp[ind] + (n-qr) + (ind - ql + 1); 
		ans += dp[i]; 
	}
	cout << ans << endl;
}