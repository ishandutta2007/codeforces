#include <iostream>
using namespace std;

int main()
{
	long n;
	long long k;
	cin >> n >> k;

	long long num = 0, j = 0;
	bool d=false;
	long newN = n;
	for(int i  = 0 ; i < n; i++ ) 
	{
		if ( d )
			j += (i - (  n - newN ) - 1 ) * num;
		cin >> num;
		if ( i == 0 )
		{	
			d = true;
			continue;
		}
		long long adad = j - ( num * ( n - i - 1 ) * ( i - ( n - newN ) ) )   ;
		//cout << num << ' '  << j << ' ' <<  adad << endl;
		if ( adad < k ) 
		{
			cout << i + 1 << endl;
			d = false;
			newN--;
		}
		else
		{
			d = true;
		}
	}
}