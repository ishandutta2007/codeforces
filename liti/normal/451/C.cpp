#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void calc() { 
	ll n,k,d1,d2;
	cin >> n >> k >> d1 >> d2;

	if( n % 3 != 0 ) { 
		cout << "no" << endl;
		return;
	}

	ll a[3];
	for(int i = 0 ; i < 2 ; i++ ) 
		for(int j = 1 ; j < 3 ; j++ ) { 
			a[0] = a[1] = a[2] = 0; 

			if( i == j ) {
				a[0] = -d1;
				a[2] = -d2;
			} else if( i == 0 && j == 1 ) 
			{
				a[0] = d1;
				a[2] = -d2;
			} else{ 
				a[i] += d1;
				a[2] = a[1];
				a[j] += d2;
			}

			ll mi  = min( a[0], min ( a[1], a[2] ) ) ;
			a[0] -= mi; a[1] -= mi; a[2] -= mi;
			ll ma = max( a[0], max( a[1], a[2] ) ) ; 

			if( ( a[0] + a[1] + a[2] ) % 3  == k % 3 && 
					a[0] + a[1] + a[2] <= k &&
					3*ma + k - a[0] - a[1] - a[2]  <= n ) {
				cerr << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
				cout << "yes" << endl;
				return;
			}
		}

	cout << "no" << endl;
}

int main() { 
	int t;
	cin >> t;

	for(int i = 0 ; i < t ; i++ ) 
		calc();
}