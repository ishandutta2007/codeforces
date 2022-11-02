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

int main()
{
	string s,s1;
	cin >> s >> s1;

	string a = "", b="";

	bool check= true;
	for(int i = 0 ; i < SZ( s ) ; i++ )
	{
		if ( s[i] == '|' ) 
		{
			check = false;
			continue;
		}
		if ( check ) 
			a += s[i];
		else
			b += s[i];
	}

	check = true;
	if ( SZ(b) < SZ(a) ) 
	{
		check = false;
		swap(a,b);
	}

	int x = -SZ(a) + SZ(b);
	for(int i =  0 ; i < SZ(s1) ; i++ )
	{
		if ( i < x ) 
			a += s1[i];
		else if ( ( i - x ) % 2 == 0 )
			a += s1[i];
		else
			b += s1[i];
	}

	if ( SZ(a) != SZ(b) ) 
	{
		cout << "Impossible" << endl;
		return 0;
	}

	if ( check ) 
		cout << a << "|" << b;
	else
		cout << b << "|" << a;
}