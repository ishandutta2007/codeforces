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

const int maxN = 100*100*10 + 100; 

long long a[maxN], b[maxN], c[maxN];

vector<long long> ans,an;

int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ;i++ )
		cin >> a[i];

	if ( n == 1 ) 
	{
		cout << -1 << endl;
		return 0;
	}

	sort( a, a + n ) ; 

	b[1] = a[1] - a[0];

	bool check = true;
	for(int i = 2 ; i < n ; i++ )
	{
		long long x = a[i] - a[i-1];
		if ( x != b[i-1] ) 
			check = false;

		if ( !check ) 
			b[i] = -1;
		else
			b[i] = x;
		cerr << i << ' ' << b[i] << endl;
	}

	c[n-1] = a[n-1] - a[n-2];
	cerr <<c[n-1] << endl;
	check = true;
	for(int i = n - 2 ; i > 0 ; i-- ) 
	{
		long long x = a[i] - a[i-1];
		if ( x != c[i+1] ) 
			check = false;
		if ( !check ) 
			c[i] = -1;
		else
			c[i] = x; 

		cerr << i <<  ' ' << c[i]  << ' ' << x << endl;
	}

	if ( b[n-1] != -1 ) 
		ans.push_back( a[n-1] + b[n-1] ) ; 
	if ( c[1] != -1 ) 
		ans.push_back( a[0] - c[1] ) ; 

	for(int i = 1; i < n ;i++ )
	{
		if ( ( a[i] - a[i-1] ) % 2 != 0 ) 
			continue;
		int x = ( a[i] - a[i-1] ) / 2 ; 
		
		bool c1 = false;
		if( i == 1 || b[i-1] == x ) 
			c1 = true;
		bool c2 = false;
		if ( i == n-1 || c[i+1] == x ) 
			c2 = true;
		if ( c1 && c2 ) 
			ans.push_back( a[i-1] + x ) ; 
	}

	sort( ans.begin() , ans.end() ) ; 
	for(int i = 0 ; i < SZ( ans ) ; i++ )
		if ( i == 0 || ans[i] != ans[i-1] ) 
			an.push_back(ans[i]) ; 
	cout << SZ( an ) << endl;
	for(int i = 0; i < SZ( an ) ; i++ )
		cout << an[i] << ' ' ; 
	cout << endl;
}