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

	int counter = 0 ; 
	int ans = 1 ; 

	for(int i = 1 ; i < SZ(s) ; i++ )
	{
		if ( s[i] == s[i-1] ) 
			counter++;
		else
		{
			counter = 0 ; 
			ans++;
		}

		if ( counter == 5 ) 
		{
			ans++;
			counter = 0 ;
		}
	}
	cout << ans << endl;
}