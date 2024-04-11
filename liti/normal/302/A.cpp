#include <iostream>
using namespace std;

int main()
{
	int n, m; 
	cin >>  n >> m ; 

   	int a= 0,b=0;
	for(int i = 1 ; i <= n; i++ ) 
	{
		int tmp ; 
		cin >> tmp; 
		if ( tmp == 1 ) 
			a++;
		if ( tmp == -1 ) 
			b++;

	}
	for(int i = 0 ; i < m; i++ )
	{
		int l,r;
		cin >> l >> r; 
		l = r - l + 1;
		if ( l % 2 == 0 && l/2 <= min(a,b) && l != 0  ) 
			cout << "1" << endl;
		else
			cout << "0" << endl;

	}

}