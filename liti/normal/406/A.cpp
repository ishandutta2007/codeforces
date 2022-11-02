//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

int main() { 
	int n; scanf( "%d" , &n ); 
	int sum = 0;
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < n ; j++ ) { 
			int x; scanf("%d" , &x ); 
			if( i == j ) 
				sum ^= x; 
		}
	int q; scanf("%d" , &q ); 
	for( int i = 0 ; i < q ; i++ ) { 
		int t; scanf("%d" , &t); 
		if( t == 3 ) 
			printf("%d" , sum); 
		else { 
			sum ^= 1; 
			scanf("%d" , &t);
		}
	}
}