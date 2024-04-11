#include <iostream>
using namespace std;

int a[1000][1000]; 
/*int b[6][6] = 
{
	0, 1, 1, 1, 0, 0,
	0, 0, 1, 1, 1, 0,
	0, 0, 0, 1, 0, 1,
	0, 0, 0, 0, 1, 1,
	1, 0, 1, 0, 0, 1,
	1, 1, 0, 0, 0, 0,
};*/

int b[6][6] = 
{
	0, 1, 0, 1, 1, 0,
	0, 0, 1, 1, 0, 1,
	1, 0, 0, 0, 1, 1,
	0, 0, 1, 0, 1, 0,
	0, 1, 0, 0, 0, 1,
	1, 0, 0, 1, 0, 0,
};


int main() 
{
	int n; 
	cin >> n ; 

	if ( n % 2 == 0 ) 
	{
		if ( n < 5 ) 
		{
			cout << -1 << endl;
			return 0;
		}
		else
		{
			for(int i = 0 ; i < 6; i++) 
				for(int j = 0; j < 6 ; j++) 
					a[i][j]=b[i][j];
			for(int i = 6 ; i < n ; i+= 2 ) 
			{
				a[i][i+1] = 1; 

				for(int j = 0 ; j < i ;j++ ) 
				{
					a[j][i] = 1; 
					a[i+1][j] =  1; 
				}
			}
		}
	}
	else
	{
	for(int i = 1; i < n ;i+= 2 ) 
	{
		a[i][i+1] =  1 ;  

		for(int j =0 ; j < i ; j++ )
		{
			a[j][i] = 1 ; 
			a[i+1][j] = 1; 
		}
	}
	}
	for(int i =0 ; i < n ; i++ ) 
	{
		for(int j = 0 ; j < n ; j++ ) 
			cout << a[i][j] << ' ' ; 
		cout << endl;
	}

}