#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

const int maxN = 5*100*100*10 + 100;

int a[maxN];

int main() 
{
	int n;
	cin >> n;

	for(int i =0 ; i < n ;i++ )
		cin >> a[i];

	sort( a, a + n );
//	reverse( a , a + n ) ;

	int j = 0 ; 
	int i = n/2 + ( n % 2 ) ;

	int ans = n;
	while( j != n/2 + ( n % 2 ) && i != n )
	{
		if ( a[i] >= 2*a[j] ) 
		{
			ans--;
			i++;
			j++;
		}
		else
			i++;

	}
	cout << ans << endl;


}