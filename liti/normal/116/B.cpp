#include <iostream>
#include <cmath>
using namespace std;

int a[11][11];
int n,m;

bool isAns( int x, int y ) 
{
	for(int i = - 1; i < 2 ; i++ )
		for(int j = -1 ; j < 2 ; j++ )
		{
			if ( abs( i ) + abs( j ) == 2 ) 
				continue;
			if ( x + i == n || y  + j == m || x + i == -1 || y + j == -1 ) 
				continue; 
			if ( a[x + i][y + j] == 2 ) 
				return true;
		}
	return false;
}

int main() 
{
	cin >> n >>m; 
	
	for(int i = 0 ;i < n ;i++ ) 
	{
		string s; 
		cin >> s;

		for(int j = 0 ; j < m ; j++ )
		{
			if ( s[j] == 'P' ) 
				a[i][j] = 2;
			else if ( s[j] == 'W' ) 
				a[i][j] = 1; 
			else
				a[i][j] = 0;
		}
	}

	int ans = 0 ; 

	for(int i = 0 ;i  < n ;i++ ) 
		for(int j = 0 ; j < m ; j++ )
			if ( a[i][j] == 1 ) 
				ans += isAns( i , j ) ; 
	cout << ans << endl;

}