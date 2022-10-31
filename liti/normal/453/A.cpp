/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100*100*10 + 10;
typedef long double ld;

int main() { 
	int n,m;
	cin >> m >> n;

	ld res = 0 ; 
	for( int i = 1 ; i <= m ; i++ ) { 
		ld tmp = 0; 
		tmp = pow( (1.f*i)/m , n ) - pow( (1.f*(i-1))/m , n ) ;
		res += tmp*i;
	}
	
	cout << fixed << setprecision(6) << res << endl;
}