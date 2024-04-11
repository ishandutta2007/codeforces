#include <iostream>
using namespace std;



const long long limit = 1000000007;

long long exp( long long a, long long b )
{
	long long result= 1; 

	while ( b > 0 ) 
	{
		if ( b % 2 == 1 ) 
			result = ( result * a ) % limit;
		b = b >> 1 ; 
		a = ( a * a ) % limit;
	}
	return result; 
}

int main() 
{
	string a; 
	cin >> a; 

	long long k ; 
	cin >> k; 

	int b[a.size()];

	long long ans = 0; 
	int counter = 0 ; 
	int lastIndex = -1;
	long long lastR;
	for(int i = 0 ; i < a.size() ; i++ ) 
	{
		if ( ( a[i] - 48 ) % 5 != 0  )
		{
			counter++; 
			b[i] = counter;
		}
		else
		{

			b[i] = counter;
			long long r  =1 ; 
			if (lastIndex == -1 ) 
			{
				r = exp( 2, counter ) ; 
			}
			else
			{
				r = ( lastR * exp( 2, counter - b[lastIndex] ) )  % limit;
				
			}
			lastIndex = i;
			lastR = r ; 

			ans =  ( ans + r ) % limit;
			counter++;
		}

	}
	
	if ( ans == 0  )
	{
		cout << 0 << endl;
		return 0 ; 
	}
	long long size = exp( 2,a.size()) ;
	long long result = 0; 
	long long lastSize = 1 ; 
//	cout << ans << endl;
	while ( k > 0 ) 
	{
	//	cout << "DALL" << ' ' << ans << endl;
		
	//	cout << result << ' ' << ans << endl;
		if ( k % 2 == 1 ) 
		{
			result = ( result + ( ( lastSize * ans ) % limit ) ) % limit;
			lastSize = ( lastSize  *  size ) % limit;
		}
		k = k >> 1 ; 
		ans = ( ans * ( 1 + size ) ) % limit ;

		size = ( size * size ) % limit;
	}
//	cout << ans << ' ' <<  result << endl;
	cout << result   << endl;
}