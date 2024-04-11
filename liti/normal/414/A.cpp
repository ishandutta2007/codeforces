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

int main()
{
	int n,k;
	cin >> n >> k;

	if( n == 1 ) 
	{
		if( k == 0 ) 
			cout << "1" << endl;
		else
			cout << "-1" << endl;
		return 0;
	}

	int x = n/2;
	if( x > k ) 
	{
		cout << -1 << endl;
		return 0;
	}

	int y = k/x;
	int z = k%x;
	
	z = x - z ;
	z++;
	for(int i = 1 ; i <= x ; i++ )
	{
		if( i < z ) 
			cout << 2*y*i << ' ' << 2*y*i + y << ' ';
		else
			cout << 2*(y+1)*i << ' ' << 2*(y+1)*i + y+1 << ' ';
	}
	if( n % 2 ) 
		cout << 1000LL*1000LL*1000LL ;
	cout << endl;
}