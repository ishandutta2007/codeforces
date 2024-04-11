//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll;
const int mod = 1e9 + 7; 

inline int mul( int a , int b ) { 
	return a * 1ll * b % mod; 
}
inline int sum( int a , int b ) { 
	int c = a + b; 
	if( c >= mod ) c-= mod; 
	return c; 
}
inline int bpow( int a , int b ) { 
	int ret = 1; 
	for( ; b ; b /= 2 ) { 
		if( b & 1 ) ret = mul( ret , a ); 
		a = mul( a , a ); 
	}
	return ret; 
}

const int maxN = 3 * 100 * 1000 + 10; 

int fact[maxN],inv[maxN];
int occ[2][maxN]; 

inline void init() { 
	memset( occ , -1 , sizeof occ ); 
	fact[0] = inv[0] = 1; 
	for( int i = 1 ; i < maxN ; i++ ) { 
		fact[i] = mul( fact[i-1] , i ); 
		inv[i] = bpow( fact[i] , mod - 2 ); 
	}
}

unordered_map<ll,int> _cmb;
inline int cmb( int n , int r ) { 
	if( r > n ) return 0; 
	return mul( fact[n] , mul( inv[r] , inv[n-r] ) ) ; 
}

int cnt[maxN]; 
bool isP[maxN]; 
int arr[30]; 
int upSum[maxN]; 

int main() { 
	ios::sync_with_stdio(false); 
	init(); 
	int n; cin >> n; 
	for( int i = 0 ; i < n ; i++ ) { 
		int x; cin >> x; 
		cnt[x]++; 
	}

	int ans = 0; 
	for( int i = 2 ; i < maxN ; i++ ) if( !isP[i] ) { 
		memset( arr , 0 , sizeof arr ) ; 
		int mx = 0; 
		int tot = 0; 
		for( int j = i ; j < maxN ; j+=i ) if( (isP[j] = 1) && cnt[j] ) { 
			int v = j; 
			int x = 0; 
			for( ; v % i == 0 ; v /= i , x++ ) ; 
			tot += cnt[j] ; 
			arr[x] += cnt[j]; 
			mx = max( mx , x ) ;
		}
		mx++; 
		if( mx == 1 ) continue;
		arr[0] = n - tot ;
		//cerr << "BEG " << i << endl;
		//copy( arr , arr + mx , ostream_iterator<int>( cerr , " " ) ) ; 
		//cerr << endl;

		for( int t = 0 ; t < 2 ; t++ ) { 
			int count = 0; 
			for( int j = 0 ; j < mx ; j++ ) {  
				int tmp = 0; 
				count += arr[j]; 
				int rem = n - count; 
				if( occ[t][rem] != -1 ) { 
					ans = sum( ans , occ[t][rem] ) ; 
					continue; 
				}
				memset( upSum , 0 , sizeof upSum ); 
				for( int b = rem ; b >= 0 ; b-- ) 
					upSum[b] = sum(upSum[b+1] , cmb( rem , b )); 
				

				for( int a = 0 ; a <= count && a + t <= rem ; a++ ) 
					tmp = sum( tmp , mul( a , mul( cmb( count , a ) , upSum[a+t] ) ) ) ; 
				occ[t][rem] = tmp; 
				ans = sum( ans , tmp ); 
			}
			reverse( arr , arr + mx ); 
		}
		//cerr << "CHANGED ANS TO " << ans << endl;
	}
	cout << ans << endl;
}