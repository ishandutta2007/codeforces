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

int a[12];
int main()
{
	int k;
	cin >> k;

	for(int i = 0; i < 12 ; i++ ) 
		cin >> a[i];
	if ( k == 0 ) 
	{
		cout << 0 << endl;
		return 0;
	}

	sort( a, a + 12 ) ; 
	reverse( a, a + 12 ) ; 
	int ans = -1 ; 
	int sum = 0 ; 

	for(int i = 0 ; i < 12 ; i++ )
	{
		sum += a[i];
		if ( sum >= k ) 
		{
			ans = i + 1; 
			break;
		}
	}
	cout << ans << endl;
}