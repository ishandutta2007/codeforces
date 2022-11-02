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
#include <cstdio>

#define SZ(x) (( (int) x.size() ))

using namespace std;

int a[25][25];

void calc()
{
	memset( a, 0, sizeof a ) ; 
	int n,p;
	cin >> n >> p; 

	for(int i = 0 ; i < n; i++ )
	{
		a[i][(i+1)%n] = 1;	
		a[(i+1)%n][i] = 1; 
		a[i][(i+2)%n] = 1;
		a[(i+2)%n][i] = 1; 
	   	cout << ( i + 1 ) << ' ' << ( i + 1 ) % n + 1 << endl << ( i + 1 ) << ' ' << ( i + 2 ) % n + 1 << endl;
	}

	for( int j = 3; j < n ; j++ )
	{
		for(int i = 0 ; i < n ; i++ ) 
		{
			if( p == 0 ) 
				break;
			if( a[i][(i+j)%n] ) 
				continue;
			a[i][(i+j)%n] = 1;
			a[(i+j)%n][i] = 1;
			p--;
			cout << i + 1 << ' ' << (i + j) % n + 1 << endl;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	for(int i = 0 ; i < t; i++ ) 
		calc();
}