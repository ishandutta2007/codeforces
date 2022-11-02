#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n; 
	cin >> n ;

	long counter = 0 ; 
	
	long a,b;
	for(int i =1 ; i <= n ;i++ )
	{
		a = i*i;
		for( int j = i ;j <= n ;j++ )
		{
			b = j*j;
			double ans = sqrt( a + b ) ; 
			if ( a+b <= n*n && ans - (int) ans == 0 )
				counter++;
		}
	}
	cout << counter << endl;
}