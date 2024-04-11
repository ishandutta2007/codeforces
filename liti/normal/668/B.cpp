//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000 * 1000 + 100;
int a[maxN];
int main() { 

	int p1 = 0 , p2 = 1; 
	int n,q; scanf("%d %d" , &n, &q);
	for( int i = 0 ; i < q ; i++ ) { 
		int t; scanf("%d" , &t);
		if( t == 1 ) { 
			int x; scanf("%d",&x);
			p1 = (p1 + x + n) % n; 
			p2 = (p2 + x + n) % n; 
		} else 
			p1 ^= 1 , p2 ^= 1;
	}
	for( int i = 0 ; i < n ; i++ ) 
		if( i % 2 == 0 ) 
			a[(i+p1)% n] = i; 
		else
			a[(i-1+p2)%n] = i; 
	for( int i = 0 ; i < n ;i ++) 
		printf("%d " , a[i] + 1 ) ; 
	printf("\n");
}