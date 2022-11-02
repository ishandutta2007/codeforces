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
	string s;
	cin >> s; 

	int k;
	cin >> k;

	int ans = 0 ; 
	for(int i = 0 ; i < k ; i++ )
	{
		string x;
		cin >> x; 
		char a = x[0], b = x[1];
		int c1= 0 , c2 = 0 ;

		for(int i = 0 ; i < SZ( s )   ; i++ )
		{
			if ( s[i] == a ) 
				c1++;
			else if ( s[i] == b ) 
				c2++;
			else
			{
				ans += min( c1, c2 ) ; 
				c1 = 0 ; 
				c2 = 0 ; 
			}
		}
		ans += min( c1, c2 ) ; 
	}
	cout << ans << endl;

}