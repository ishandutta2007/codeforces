//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

inline void read( int& a ) { 
	scanf("%d" , &a ); 
}

const int maxN = 1000*1000+100;
int mark[maxN]; 
int ans[maxN],en;  

int main() { 
	int n; read(n); 
	int s = 1000*1000 + 1; 
	for( int i = 0 ; i < n ; i++ ) { 
		int x; read(x); 
		mark[x] = true; 
	}
	int cnt = 0; 
	for( int i = 1 ; s - i > i ; i++ ) { 
		if( mark[i] && !mark[s-i] ) 
			ans[en++] = s - i; 
		if( mark[s-i] && !mark[i] ) 
			ans[en++] = i; 
		if( mark[i] && mark[s-i] ) 
			cnt++; 
	}
	for( int i = 1 ; s - i > i && cnt ; i++ )
		if( !mark[i] && !mark[s-i] ) {
			ans[en++] = i , ans[en++] = s - i; 
			cnt--; 
		}
	printf( "%d\n" , en );
	for( int i = 0 ; i < en ; i++ ) 
		printf( "%d " , ans[i] ) ; 
	printf("\n");
}