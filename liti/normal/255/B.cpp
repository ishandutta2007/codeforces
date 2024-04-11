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
#include <string> 

#define SZ(x) (( (int) x.size() ))

using namespace std;

int main()
{
	string s; 
	cin >> s; 
	vector<char>  a,b; 
	
	for(int i = 0 ; i < SZ( s ) ; i++ )
	{
		if ( SZ(a) == 0 ) 
		{
			a.push_back( s[i] );
			continue;
		}

		if ( a.back() == 'y' && s[i] == 'x' ) 
			a.pop_back();
		else
			a.push_back( s[i] ) ; 
	}

	for(int i = 0 ; i < SZ( a ) ; i++ )
	{
		if ( SZ(b) == 0 ) 
		{
			b.push_back( a[i] );
			continue;
		}

		if ( b.back() == 'x' && a[i] == 'y' ) 
			b.pop_back();
		else
			b.push_back( a[i] ) ; 
	}

	for(int i = 0 ; i < SZ( b ) ; i++ )
		cout << b[i] ;
	cout << endl;
}