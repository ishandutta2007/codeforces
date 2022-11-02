/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 3*1000*100 + 300; 
const int maxL = 26;
pair<int,int> a[maxN];

int seg[maxL][maxN];

int n;

inline void makeTree( int xl = 0 , int xr = n , int id = 0 ) { 
	if( xr - xl == 1 ) { 
		seg[id][xl] = a[xl].second;
		return;
	}
	int xm = (xl+xr) >> 1; 
	makeTree( xl , xm , id + 1 ) ; 
	makeTree( xm , xr , id + 1 ) ; 
	merge( &seg[id+1][xl] , &seg[id+1][xm] , &seg[id+1][xm] , &seg[id+1][xr] , &seg[id][xl] );
}

inline int getVal( int ql , int qr , int mx , int xl = 0 , int xr = n , int id = 0 ) { 
	if( xr <= ql || qr <= xl ) 
		return 0;
	if( ql <= xl && xr <= qr ) { 
		int x = lower_bound( &seg[id][xl] , &seg[id][xr] , mx ) - &seg[id][xl];
		return xr - xl - x;
	}
	int xm = (xl+xr) >> 1; 
	int ret = 0; 
	ret += getVal( ql , qr , mx , xl , xm , id + 1 ) ; 
	ret += getVal( ql , qr , mx , xm , xr , id + 1 ) ; 
	return ret;
}

int main() { 
	int m;
	scanf("%d %d" , &n , &m);

	for( int i = 0 ; i < n ; i++ ) 
		scanf("%d %d" , &a[i].first , &a[i].second ) ; 

	sort( a , a + n ) ; 
	makeTree();

	for( int i = 0 ; i < m ; i++ ) { 
		int k; 
		scanf( "%d" , &k ) ;
		int last = 0;
		int ans = 0;
		for( int j = 0 ; j < k ; j++ ) {
			int num;
			scanf("%d" , &num);
			int nex = upper_bound( a , a + n , make_pair( num , maxN * 10 ) ) - a; 
			ans += getVal( last , nex , num ) ; 
			last = nex;
		}
		printf( "%d\n" , ans ) ; 
	}
}