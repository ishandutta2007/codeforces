/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*1000 + 10 ; 
int h[maxN];

int main(){ 
	for( int i = 2 ; i < maxN ; i ++ ) 
		if( !h[i] ) 
			for( int j = i + i ; j < maxN ; j += i ) 
				h[j] = 1;
	h[1] = 0; 
	int n;
	cin >> n;

	for( int i = 2 ; i < n ; i++ ) 
		if( h[i] && h[n-i] ){ 
			cout << i << ' ' << n - i << endl;
			return 0 ; 
		}
}