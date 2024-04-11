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

	bool check = false;
	for(int i =0 ; i < SZ(s) ; i++ )
	{
		if ( s[i] == 'H' || s[i] == 'Q' || s[i] == '9' ) 
		{
			check = true;
			break;
		}

	}
	cout << ( check ? "YES" : "NO" ) << endl;
}