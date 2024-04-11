#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[100],b[100],c[100];

	for(int i = 0 ; i < n ; i++ ) 
	{
		c[i] = 0;
		cin >> a[i] >> b[i];
	}
	for(int i  = 0 ; i < n ; i++ ) 
	{
		for(int j  = 0 ; j < n; j++ ) 
		{
			if ( a[j] == b[i] && i != j ) 
				c[j] = 1;
		}
	}
	int result = 0;
	for(int i = 0 ; i < n; i++) 
		result += c[i];

	cout << n - result << endl;
		
}