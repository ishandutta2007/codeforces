#include <iostream>
#include <vector>
using namespace std;

int r[100],c[100],d[100],e[100];
int main()
{
	int n; 
	cin >> n ;

	string s[n];
	for(int i = 0;i < n ; i++ )
	{
		d[i] = n; 
		e[i] = n; 
		cin >> s[i] ; 
		for(int j = 0 ;j < n ; j++ ) 
		{
			if ( s[i][j] == '.' ) 
			{
				r[i]++;
				c[j]++;
			}
		}
	}

	bool c1 = false,c2 = false; 
	for(int i = 0; i < n ;i++ ) 
	{
		if ( r[i] == 0 ) 
		{
			c1 = true;
		}
		if ( c[i] == 0 ) 
		{

			c2 = true; 
		}
	}
	if ( c1 && c2 ) 
	{
		cout << -1 << endl;
		return 0;
	}

	if ( c1 ) 
	{
		for(int j = 0 ; j < n ; j++ )
		{
			for(int i = 0;i< n ; i++ )
			{
				if ( s[i][j] == '.' ) 
				{
					cout << i + 1 << ' ' << j + 1 << endl;
					break;
				}
			}
		}
	}
	else
	{

	for(int i = 0 ; i < n ; i++ )
		{
			for(int j = 0;j< n ; j++ )
			{
				if ( s[i][j] == '.' ) 
				{
					cout << i + 1 << ' ' << j + 1 << endl;
					break;
				}
			}
		}

	}			

}