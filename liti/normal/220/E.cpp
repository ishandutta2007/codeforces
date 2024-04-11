/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100*100*10 + 10;

//Fenwick
int l[maxN], r[maxN];

void add( int x, int val , int* f ) { 
	for( ; x < maxN ; x += (-x) & x ) 
		f[x] += val;
}
int get( int x , int* f ) { 
	int res = 0 ;
	for( ; x > 0 ; x -= (-x) & x ) 
		res += f[x];
	return res;
}

int a[maxN], b[maxN];
long long pSum[maxN] , sSum[maxN];

int main() { 
	int n, k;
	cin >> n >> k;

	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i];
	copy( a , a + n , b ) ; 
	sort( b , b + n ) ;
	int sz = unique( b , b + n ) - b;
	for( int i =0 ; i < n ; i++ ) 
		a[i] = lower_bound( b , b + sz , a[i] ) - b + 1;

	for( int i = 0 ; i < n ; i++ ) { 
		pSum[i] = (i==0?0:pSum[i-1]) + get( n , l ) -  get( a[i]  , l ) ;
		add( a[i], 1 , l ) ;
	}
	for( int i = n - 1 ; i >= 0 ; i-- )  {
		sSum[i] = sSum[i+1] + get( a[i] - 1 , r ) ; 
		add( a[i], 1 , r ) ;
	}

	memset( l , 0 , sizeof l ) ; 

	long long ans = 0 ; 

	int p = 0;
	long long tmp = 0 ;
	for( int i = 0 ; i < n ; i++ ) { 
		tmp += get( a[i] - 1 , r ) ; 
		add( a[i] , 1 , l ) ;
		while( p != n && ( p == i || pSum[i] + sSum[p] + tmp > k ) ) { 
	//		cerr << i << ' ' << p << " B " << pSum[i] << ' ' << sSum[p] << ' ' << tmp << endl;
	//		cout << get( n , l )  << ' ' << get( a[p]  , l ) << endl;
			tmp -= get( n , l ) - get( a[p]  , l ) ; 
			add( a[p] , -1 , r ) ; 
			p++;
		}

		ans += n - p;
	}
	cout << ans << endl;
}