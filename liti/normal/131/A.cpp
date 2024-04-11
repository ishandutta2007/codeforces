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

string getAns( string s ) 
{
	for(int i = 0; i < SZ( s ) ; i++ )
	{
		if ( s[i] <= 'Z' ) 
		{
			s[i] = s[i] + ( 'a' - 'A' ) ; 
		}
		else 
		{
			s[i] = s[i] - ( 'a' - 'A' ) ; 
		}
	}
	return s;
}
int main() 
{
	string s; 
	cin >> s;

	bool check = true;

	for(int i = 1; i < SZ( s ) ; i++ )
		if ( s[i] > 'Z' ) 
		{
			check = false;
			break;
		}

	if ( check ) 
		s = getAns( s ) ;
	cout << s << endl;
}