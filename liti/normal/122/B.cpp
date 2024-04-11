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

int main() 
{
	string s; 
	cin >> s; 

	int c1 = 0 , c2 = 0 ; 
	for(int i =0 ; i < SZ( s ) ; i++ )
	{
		if ( s[i] == '4' )  
			c1++;
		if ( s[i] == '7' ) 
			c2++;
	}
	if ( c1 == c2 && c2 == 0 ) 
		cout << -1 << endl;
	else if ( c1 >= c2 ) 
		cout << "4" << endl;
	else
		cout << "7" << endl;
}