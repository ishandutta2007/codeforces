#include <iostream>
#include <stdio.h>

using namespace std;

long long l1 , r1 , l2 , r2 , k , ans , x , y;

int main()
{
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	if( l1 > l2 ) swap( l1 , l2 ) , swap( r1 , r2 );
	if( r1 < l2 ) ans = 0;
	else if( r2 >= r1 ) ans = r1 - l2 + 1 , x = l2 , y = r1;
	else ans = r2 - l2 + 1 , x = l2 , y = r2;
	if( x <= k && k <= y ) ans--;
	cout << max( ans , 0ll ) << endl;
	return 0;
}