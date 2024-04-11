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

int  main() 
{
	int n;
	cin >> n; 

	for(int i = 0 ; i < 4 ; i++ )
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d; 
		int x = min(a,b) + min( c,d ) ; 
		if ( x <= n ) 
		{
			cout << i + 1 << ' ' << min(a,b) + ( n - x ) << ' ' << min(c,d ) << endl;
		   return 0;
		}
	}
	cout << -1 << endl;
}