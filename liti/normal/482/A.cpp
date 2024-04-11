/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

int main() { 
	int n,k;
	cin>> n >> k;
	for( int i = 1 ; i <= n - k - 1  ; i++ ) 
		cout << i << ' ';
	for( int i = 0 ; i <= k ; i++ ) 
		cout <<  ( i % 2 == 0 ? n - k +  i/2 : n - i/2  ) << ' ';
}