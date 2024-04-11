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

int a[101];

int main() 
{
	int n,d; 
	cin >> n >> d ; 
	for(int i = 0 ; i < n ; i++ )
		cin >> a[i];
	sort( a , a + n ) ; 

	int m;
	cin >> m ; 

	int ans = 0 ; 
	for(int i = 0 ; i < n ; i++ )
	{
		if ( m == 0 ) 
			break;
		ans += a[i];
		m--;
	}

	cout << ans - d*m << endl;
}