#include <iostream>
using namespace std;

int main()
{
	int na = -1, nb = -1;
	int k;
	cin >> k; 

	int a[k];
	
	int i1 = -1,i2=-1;
	for(int i =0  ; i < k ; i++)
	{ 
		cin >> a[i];
		if ( a[i] == 100  ) 
		{
			i1 = i;
		   continue;	
		}
		if ( a[i] == 0 ) 
		{
			i2 = i; 
			continue;
		}

		if ( a[i] < 10 ) 
		{
			na = a[i];
		}
		if ( a[i] % 10 == 0 )
		{
			nb = a[i];
		}

	}

	if ( na != -1 || nb != -1 ) 
	{
		int result = ( na != -1 ) + ( nb != -1 ) + ( i1 != -1 )  +  (i2 != -1) ;

		cout << result << endl;

		if ( na != -1 ) 
			cout << na << ' ';
		if ( nb != -1 ) 
			cout << nb << ' ';
		if ( i1 + 1 ) 
			cout << a[i1] << ' ';
		if ( i2 + 1 ) 
			cout << a[i2] << ' ';

		cout << endl;
	}

	if ( na == -1 && nb == -1 ) 
	{
		if ( i1 == -1 && i2 == -1 ) 
		{
			cout << 1 << endl;
			cout << a[0] << endl;
		}
		else
		{
			int index = -1;
			for(int i = 0 ; i < k ; i++  ) 
			{
				if ( i != i1 && i != i2 && a[i] != 100 && a[i] != 0 ) 
				{
					index = i;
					break;
				}
			}
			cout << ( i1 != -1 ) + ( i2 != -1 ) + ( index != -1 ) << endl;
			if ( i1 + 1 ) 
				cout << a[i1] << ' ';
			if ( i2 + 1 ) 
				cout << a[i2] << ' ';

			if (index  + 1 ) 
				cout << a[index] << ' ' ;
			cout << endl;
		}

	}

}