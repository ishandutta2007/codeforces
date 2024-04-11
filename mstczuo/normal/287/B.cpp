# include <iostream>
# include <cstdio>
using namespace std;

long long n, k;
long long func(int m)
{
	return (k - m + 1) * (k + m ) / 2;
}

int main()
{
	cin >> n >> k; n --; k --;
	if ( n == 0 ) { cout << 0; return 0; }
	if ( k * (k+1) /2 < n )
		return cout << -1 << endl, 0;
	long long L = 1, R = k+1, M;
	while ( R-L>1 ) {
		M = (L + R ) >> 1;
		( func(M) >= n ) ? L = M : R = M; 
	}
	cout << k - L + 1 << endl;
	return 0;
}