#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <deque>

#define SZ(x) (( (int) x.size() ))

using namespace std;

int a[30][30];
int main() 
{
	for(int i =  0 ; i < 30 ; i++ ) 
		for(int j = 0 ; j < 30 ; j++ ) 
			a[i][j] = -1;
	int n;
	cin >> n; 

	queue<pair<int, int> > bfs;
	a[n][n] = 0; 

	bfs.push( make_pair( n,n ) ) ; 

	while( bfs.size() != 0 ) 
	{
		int x = bfs.front().first;
		int y = bfs.front().second;
		bfs.pop();

		for(int i = -1 ; i < 2 ; i++ )
			for(int j = -1 ; j < 2 ; j ++ )
			{
				if ( abs( i ) + abs ( j ) == 2 ) 
					continue; 
				if ( x + i == -1 || x + i == 2*n + 1 || y + j == -1 ||
						y + j == 2*n + 1 ) 
					continue;
				if ( a[x + i][y + j] != -1 ) 
					continue; 
				
				bfs.push( make_pair( x + i, y + j ) ) ; 
				a[x + i][y+j] = a[x][y] + 1; 
			}
	}

	for(int i = 0 ; i < 2*n + 1 ; i++ )
	{
		for(int j = 0 ; j < 2*n + 1 ; j++ )
		{
			if ( j != 0 && n - a[i][j-1] >= 0 && n - a[i][j] < 0 ) 
				break;
			if ( j != 0 ) 
				cout << ' ' ; 
			if ( n - a[i][j] < 0 ) 
				cout << " ";
			else
				cout << n - a[i][j]  ; 
		}
		cout << endl;
	}
}