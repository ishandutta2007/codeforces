//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 200*1000 + 1000; 
int a[maxN];
int main() {
	int n; 
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	sort( a , a + n );
	int s = 0 , e = a[n-1] - a[0] + 1; 
	int k = (n-1)/2;
	while( e - s > 1 ) { 
		int m = (s+e) / 2; 
		bool canDo = false;
		for( int i = 0 ; i < n ; i++ ) {
			int ind = lower_bound( a, a + n , a[i] + m ) - a;
			int del = i + n - ind;
			if( del <= k ) canDo = true;
		}
		if( canDo ) 
			e = m;
		else
			s = m;
	}
	cout << s << endl;
}