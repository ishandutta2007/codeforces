#include <iostream>
using namespace std;

int main()
{
	int n; 
	cin >> n;
	int a[1001];
	for(int i = 0 ; i <= 1000 ;i++)
	   a[i] = 0;	
	for(int i = 0 ;i < n ; i++ ) 
	{
		int tmp;
		cin >> tmp;
		a[tmp]++;
	}
	for(int i = 1 ; i <= 1000; i++)
	{
		int num = n/2;
		if ( n % 2 == 1 ) 
			num++;
		if ( a[i] > num ) 
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

}