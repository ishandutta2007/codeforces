#include <iostream>
using namespace std;

const long long limit = 1000*1000*1000LL + 9;

const int maxN = 3*100*100*10 + 100; 

int sum[4*maxN], fVal[4*maxN], sVal[4*maxN];
int fib[maxN]; 

inline int getNth( long long a, long long b, int n ) { 
	if( n == 0 ) 
		return a;
	if( n == 1 ) 
		return b;
	return ( (fib[n-1]*b % limit) +  (fib[n-2]*a  % limit) ) % limit; 
}

inline int getSum( int a, int b, int n ) { 
	return ( getNth( a, b , n + 1 ) - b + limit ) % limit ; 
}

inline void update( int ind, int s , int e ) { 
	int m = ( s + e ) / 2;
	
	fVal[ind*2] = ( fVal[ind*2] + fVal[ind] ) % limit;
	sVal[ind*2] = ( sVal[ind*2] + sVal[ind] ) % limit;
	sum[ind*2] = ( sum[ind*2] + getSum(fVal[ind], sVal[ind], m - s ) ) % limit ;

	int F = getNth(fVal[ind], sVal[ind], m - s  ) ;
	int S = getNth(fVal[ind], sVal[ind], m - s + 1 ) ;
	fVal[ind*2+1] = ( fVal[ind*2+1] + F ) % limit;
	sVal[ind*2+1] = ( sVal[ind*2+1] + S ) % limit;
	sum[ind*2+1] = ( sum[ind*2+1] + getSum( F, S , e - m ) ) % limit ;
	
	fVal[ind] = 0; 
	sVal[ind] = 0;
}

inline void add( int ind,  int s, int e,  int f, int l,  int F, int S ) { 
	if( s == f && l == e ) {
		fVal[ind] = (fVal[ind] + F) % limit; 
		sVal[ind] = (sVal[ind] + S) % limit;
		sum[ind] = ( sum[ind] + getSum( F, S , e - s ) ) % limit;
		return;
	}

	sum[ind] = ( sum[ind] + getSum( F, S , l - f )  ) % limit;
	update( ind, s, e ) ; 

	int m = ( s + e ) / 2; 

	if( f < m ) 
		add( ind*2 ,  s, m,  f, min( l, m ) , F, S ); 

	if( m > f ) { 
		int tmpF = F;
		F = getNth(F,S,m-f);
		S = getNth(tmpF,S,m-f+1) ;
	}

	if( l > m ) 
		add( ind*2 + 1,  m, e , max( f, m ) , l , F, S ) ; 
}

inline int get( int ind, int s, int e,  int f, int l ) { 
	if( s == f && l == e ) { 
		return sum[ind];
	}

	update( ind, s, e ); 
	
	int m = ( s + e ) / 2; 
	int ret = 0 ;
	if( f < m ) 
		ret = get( ind*2 , s, m , f, min( l,m ) ); 
	if( l > m ) 
		ret = ( ret + get( ind*2 + 1, m, e , max( f, m ) , l ) ) % limit ;
	return ret;
}

int main() { 
	ios::sync_with_stdio(false);
	fib[0] = fib[1] = 1;
	for(int i = 2 ; i < maxN ; i++ ) 
		fib[i] = ( fib[i-1] + fib[i-2] ) % limit;

	int n,m;
	cin >> n >> m;

	for(int i = 0 ; i < n ; i++ ) { 
		int num;
		cin >> num;
		add( 1, 0, n, i, i+1, num, 0);
	}

	for(int i = 0 ; i < m; i++ ) { 
		int t,l,r;
		cin >> t >> l >> r;
		l--; 
		
		if( t == 1 ) 
			add( 1, 0, n, l, r, fib[0] , fib[1] );
		else
			cout << get( 1, 0, n, l, r ) << endl;
	}
}