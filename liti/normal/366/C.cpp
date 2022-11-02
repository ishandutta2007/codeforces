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

const int maxN = 100 + 5;
const int maxK = 10;
int dp[maxN*maxN*maxK*2 + 50];
int a[maxN],b[maxN];

int main()
{
	memset( dp, 0 , sizeof dp ) ; 
	int n,k;
	cin >>n >> k; 

	for(int i = 0 ; i < n ; i++ ) 
		cin >> a[i];
	for(int i = 0 ; i < n ; i++ )
		cin >> b[i];

	int h = maxN*maxN*maxK;

	for(int i = 0; i < n ; i++ ) 
	{
		int num = b[i]*k - a[i];
		if ( num < 0 )
		{
			for( int j = -maxN*maxN ; j < h ; j++ )
			{
				if (  j - num < -maxN*maxN ) 
					continue;
				if ( j - num >= maxN*maxN*maxK )
					continue;

				if ( dp[j- num + maxN*maxN ] != 0 || j - num == 0 ) 
					dp[j + maxN*maxN] = max( dp[ j+ maxN*maxN ] , dp[ j - num + maxN*maxN ] + a[i] ) ; 
			}
		}
		else
		{
			for( int j = h-1 ; j >= -maxN*maxN ; j-- )
			{
				if (  j - num < -maxN*maxN ) 
					continue;
				if ( j - num >= maxN*maxN*maxK )
					continue;

				if ( dp[j- num + maxN*maxN ] != 0 || j - num == 0 ) 
					dp[j + maxN*maxN] = max( dp[ j+ maxN*maxN ] , dp[ j - num + maxN*maxN ] + a[i] ) ; 
			}
		}
	}

	if ( dp[maxN*maxN] == 0 )
		cout << -1 << endl;
	else
		cout << dp[maxN*maxN] << endl;
}