#include <iostream>
using namespace std;

int main()
{
	int n;
	long long k;
	cin >> n >> k;

	int ans = (n* ( n - 1 )) / 2 ;

	if ( k >= ans ) 
	{
		cout << "no solution" << endl;
		return 0;
	}
	else
	{
		for(int i = 0 ;i < n ;i++) 
		{
			cout << 0  << ' ' << i<< endl;
		}
	}
	

}