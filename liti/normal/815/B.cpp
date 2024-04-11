//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int mod = 1e9 + 7; 

inline int sum(int a,int b) { 
    return ( (a+b) % mod + mod ) % mod;
}
inline int mul(int a, int b) { 
    return 1ll * a * b % mod; 
}
inline int bpow(int a,int b) { 
    int r = 1; 
    for( ; b ; b /= 2 ) { 
        if( b & 1 ) 
            r = mul( r , a ); 
        a = mul(a,a); 
    }
    return r;
}

const int maxN = 2* 1000 * 100 + 100; 

int fact[maxN];
int rfact[maxN];

int a[maxN];
int b[maxN]; 

int solve(int n, int z, int lvl) { 
    for( int t = 0; t < lvl ; t++ ) { 
        for( int i = 0 ; i < n - t - 1 ; i++ ) {
            b[i] = sum( a[i] , z * a[i+1] ); 
            z *= -1; 
        }
        swap( a , b );
    }
    return z; 
}

int main() { 
    ios::sync_with_stdio(false); cin.tie(0);

    fact[0] = 1; 
    rfact[0] = 1; 
    for( int i = 1 ; i < maxN ; i++ ) {
        fact[i] = mul( fact[i-1] , i );
        rfact[i] = bpow( fact[i] , mod - 2 ); 
    }

    int n; cin >> n;
    for( int i = 0 ; i < n ; i++ )
        cin >> a[i];
    solve( n , 1 , (n-1) % 4 );

    int ans = 0; 
    int N = ( n - (n-1) % 4  - 1 )  / 2;
    for( int i = 0 ; i < n - (n-1) % 4 ; i += 2 ) 
        ans = sum( ans , mul( a[i] , mul( fact[N] , mul( rfact[i/2] , rfact[N-i/2] ) ) ) );
    cout << ans << endl;
}