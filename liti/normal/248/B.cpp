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
	int n; 
	cin >> n; 
	if ( n < 3 ) 
	{
		cout << -1 << endl;
		return 0;
	}

	if ( n == 3 ) 
	{
		cout << 210 << endl;
		return 0;
	}

	cout << 1;
	for(int i = 1 ; i < n - 3 ; i++ )  
		cout << 0;

	int x = 1; 
	for(int i = 1; i < n ; i++ )
	{
		x *= 10;
		x %= 210;
	}

	int ans = (210 - x) % 270;
	
	cout << ( ans / 100 == 0 ? "0" : "" ) << ( ans / 10 == 0 ? "0" : "" )  << ans << endl;
}