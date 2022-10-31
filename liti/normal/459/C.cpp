/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000 + 10;

int a[maxN];
int main() { 
	int n,k,d;
	cin >> n >> k >> d;

	int val = k;
	int last =1;

	int tmp = n;
	for( int i = 0 ; i < d ; i++ ) 
		tmp = ( tmp + k - 1 ) / k;
	cerr << tmp << endl;
	if( tmp > 1 ) {
		cout << -1 << endl;
		return 0;
	}

	for(int i = 0 ; i <n ; i++ ) 
		a[i] = i;
	for(int j =0 ; j < d ; j++ ) {
		for(int i =0  ; i < n;  i++ ) {
			cout <<  (a[i] % k) +   1  << ' ' ;
			a[i] /= k;
		}
		cout << endl;
	}

}