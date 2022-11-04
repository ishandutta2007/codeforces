#include <iostream>
#include <iomanip>
#include <cmath>
#define ll long long

using namespace std;

ll days(ll n){
	ll resl = ( -1.0 + sqrt ( 1 + 8 * n ) ) / 2.0;
	if ( resl * ( resl + 1 ) / 2 != n )
		return resl + 1;
	else
		return resl;
}

int main(){
	ll n, m;

	cin >> n >> m;

	if ( m >= n )
		cout << n;
	else
		cout << fixed << m + days(n-m);
	cout << endl;
	return 0;
}