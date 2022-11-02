#include <iostream> 
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() 
{
	int n;
	cin >> n; 

	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2; 

	int s1,s2; 
	if ( x1 == 0 ) 
		s1 = 0;
	else if ( x1 == n ) 
		s1 = 2; 
	else if ( y1 == 0 ) 
		s1 = 1; 
	else
		s1 = 3;

	if ( x2 == 0 ) 
		s2 = 0;
	else if ( x2 == n ) 
		s2 = 2; 
	else if ( y2 == 0 ) 
		s2 = 1; 
	else
		s2 = 3;

	
	if ( abs( s1 - s2 ) != 2 ) 
	{
		cout << abs( x1 - x2 ) + abs( y1 - y2 ) << endl;
		return 0; 
	}

	int ans1 = n, ans2 = n ; 
	if ( x1 == 0 || x2 == 0  ) 
	{
		ans1 += y1 + y2; 
		ans2 += n - y1 + n - y2;
		cout << min(ans1,ans2) << endl;
		return 0;
	}
	
	ans1 += x1 + x2 ; 
	ans2 += n - x1 + n - x2; 
	cout << min(ans1,ans2) << endl;
}