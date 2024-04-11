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

vector<int> l;

bool isLucky( int num )
{
	bool d[10];
	for(int i = 0 ; i < 10 ; i++ )
		d[i] = false;

	while ( num != 0 ) 
	{
		d[ num % 10 ] = true;
		num /= 10;
	}

	for(int i = 0 ; i < 10 ; i++ ) 
		if ( i != 4 && i != 7 && d[i] == true ) 
			return false;

	return true;
}


int main() 
{

	for(int i = 1 ; i < 1001; i++ )
		if ( isLucky( i ) ) 
			l.push_back(i);
	int n;
	cin >> n;

	bool isAns = false;

	for(int i = 0 ; i < l.size() ; i++ )
		if ( n % l[i] == 0 ) 
		{
			isAns = true;
			break;
		}
	cout << ( isAns ? "YES" : "NO" ) << endl;
}