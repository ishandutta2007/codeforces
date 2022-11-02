//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

int main() { 
	ll k, b, n, t;
	cin >> k >> b >> n >> t; 
	ll curr = 1; 
	n++;
	for( int i = 0 ; ; i++ ) { 
		if( curr > t ) break;
		curr = curr * k + b; 
		n--;
	}
	cout << max(0ll,n) << endl;
}