#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <string>
#include <stack>
#include <cstring>

#define SZ(x) (( (int) x.size() ))

using namespace std;

const int maxN = 500 + 20;

string a[maxN];
bool check[maxN][maxN];
int n,m,k;

bool isValid( int x, int y )
{
	return ( x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.' ) ;
}

bool dfs( int x, int y ) 
{
	if ( check[x][y] ) 
		return 0 ;	
	if ( k == 0 ) 
		return 0;
	check[x][y] = 1; 

	int counter = 0 ; 
	for(int i = - 1 ;  i < 2 ; i+= 2 ) 
	{
		if ( isValid(x + i , y) ) 
			counter += dfs( x + i , y ) ; 
		if ( isValid( x, y + i ) )
			counter += dfs( x, y + i ) ; 
	}
	if ( k == 0 ) 
		return 0;

	if ( counter == 0 ) 
	{
		k--;
		a[x][y] = 'X';
		return 0;
	}
	return 1;
}

int main() 
{
	cin >> n >> m >> k ; 

	int x = 0, y = 0 ;
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> a[i];
		for(int j = 0 ; j < m ; j++ )
		{
			if ( a[i][j] == '.' ) 
			{
				x = i;
				y = j;
			}
		}
	}

	dfs( x,y ) ;

	for(int i = 0 ; i < n ; i++ ) 
		cout << a[i] << endl;
}