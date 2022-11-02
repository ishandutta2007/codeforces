/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 150000 + 100; 
int a[maxN], b[maxN]; 

int mx[4*maxN], toAdd[4*maxN];
int n,len,h;

inline int gg( int x ) { 
	return upper_bound( b + 1 , b + len + 1 , x ) - b - 1; 
}

inline void shift( int ind ) { 
	toAdd[ind*2] += toAdd[ind];
	toAdd[ind*2+1] += toAdd[ind];
	mx[ind*2] += toAdd[ind];
	mx[ind*2+1] += toAdd[ind];
	toAdd[ind] = 0;
}

void addVal( int ql , int qr , int val , int xl = 0 , int xr = len + 1 , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) 
		return;
	if( ql <= xl && xr <= qr ) {
		toAdd[ind] += val;
		mx[ind] += val;
		return;
	}
	shift(ind);
	int xm = (xl+xr) >> 1;
	addVal( ql , qr , val , xl , xm , ind * 2 + 0 ) ; 
	addVal( ql , qr , val , xm , xr , ind * 2 + 1 ) ; 
	mx[ind] = max(mx[ind*2],mx[ind*2+1]);
}

int main() {
	scanf("%d %d %d" , &n, &len , &h ) ;

	for( int i = 0 ; i < len ; i++ ) 
		scanf( "%d" , b + i + 1 ) ; 
	sort( b + 1 , b + len + 1 , greater<int>() ) ; 
	for( int i = 1 ; i <= len ; i++ ) 
		b[i] = h - b[i];
	int ans = 0;
	for( int i = 1 ; i <= len ; i++ ) 
		addVal( i , n , -1 ) ; 
	for( int i = 0 ; i < n ; i++ ) {
		scanf( "%d" , a + i ) ; 
		addVal( gg( a[i] ) , n , 1 ) ; 
		if( i >= len ) 
			addVal( gg( a[i-len] ) , n , -1 ) ; 
		if( i >= len - 1 && mx[1] <= 0 ) 
			ans++;
	}
	printf("%d\n" , ans ) ;
}