/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*100 + 10; 

ll sum[maxN*4]; 
pair<int,int> mx[maxN*4];
int a[maxN];
int n,m;

ll getSum( int ql , int qr , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( ql <= xl && xr <= qr ) 
		return sum[ind] ; 
	int xm = (xl + xr) / 2; 
	ll ret = 0;
	if( ql < xm ) 
		ret += getSum( ql , qr , xl , xm , ind * 2 + 0 ) ; 
	if( qr > xm ) 
		ret += getSum( ql , qr , xm , xr , ind * 2 + 1 ) ; 
	return ret; 
}

void chVal( int p , int val , int lVal , int xl = 0 , int xr = n , int ind = 1 ) { 
	sum[ind] += val - lVal;
	if( xl == p && p + 1 == xr ) { 
		a[xl] = mx[ind].first = val;
		mx[ind].second = xl;
		return;
	}
	int xm = (xl + xr) / 2; 
	if( p < xm ) 
		chVal( p , val , lVal , xl , xm , ind * 2 + 0 ) ;
	else
		chVal( p , val , lVal , xm , xr , ind * 2 + 1 ) ; 
	mx[ind] = max( mx[ind*2] , mx[ind*2+1] ) ; 
}

void doMod( int ql , int qr , int mod , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( ql <= xl && xr <= qr ) { 
		while( mx[ind].first >= mod ) { 
			chVal( mx[ind].second , mx[ind].first % mod , mx[ind].first ) ; 
		}
		return;
	}
	int xm = (xl + xr) / 2; 
	if( ql < xm ) 
		doMod( ql , qr , mod , xl , xm , ind * 2 + 0 ) ; 
	if( qr > xm ) 
		doMod( ql , qr , mod , xm , xr , ind * 2 + 1 ) ; 
}

int main() { 
	scanf( "%d %d" , &n , &m ) ; 
	for( int i = 0  ; i < n ; i++ ) { 
		scanf( "%d" , a + i ) ; 
		chVal( i , a[i] ,  0 ) ; 
	}
	for( int i = 0 ; i < m ; i++ ) { 
		int t;
		scanf( "%d" , &t ) ;
		if( t == 1 ) { 
			int l,r;
			scanf( "%d %d" , &l , &r ) ;
			printf( "%I64d\n" , getSum( l-1, r ) ) ;
		} else if( t == 2 ) { 
			int l,r,x;
			scanf( "%d %d %d" , &l , &r , &x ) ;
			doMod( l - 1 , r , x ) ;
		} else { 
			int p,x;
			scanf( "%d %d" , &p , &x );
			p--;
			chVal( p , x , a[p] );
		}
	}
}