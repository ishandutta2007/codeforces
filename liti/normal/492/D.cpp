/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
typedef long double ld;

int main() { 
	int n;
	int x,y;
	cin >> n >> x >> y;

	for( int i = 0 ; i < n ; i++ ) { 
		int k;
		cin >> k;

		ld tmp = k / ld(x + y);
		int a = floor(tmp*x) ;
		int b = floor(tmp*y) ;
		bool flag = 0;
		if( a + b >= k ) {
			a--; b--;
			swap(a,b);
			swap(x,y);
			flag = 1;
		}
		if( ll( b + 1 ) * x == ll( a + 1 ) * y ) 
			cout << "Both" << endl;
		else if( ll( b + 1 ) * x > ll( a + 1 ) * y ) 
			cout << ( ll(b)*x == ll(a+1)*y ? "Both" : "Vanya" ) << endl;
		else
			cout << ( ll(b+1)*x == ll(a)*y ? "Both" : "Vova"  ) << endl;

		if( flag ) swap(x,y);
	}
}