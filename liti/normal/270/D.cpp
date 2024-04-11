#include <iostream>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int a[n];
	int b[n];
	int tMax = 0;
	for(int i = 0 ; i < n ; i++)
	{
		long double d;
		cin >> a[i] >> d ;
		int max = 0 ; 

		for(int j = 0 ; j < i; j++)
			if ( a[j] <= a[i] && b[j] > max )
				max = b[j];
		b[i] = max + 1;
		if ( b[i] > tMax) 
			tMax = b[i];
	}
	cout << n - tMax << endl;

}