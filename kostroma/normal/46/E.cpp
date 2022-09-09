#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <deque>
using namespace std;
typedef long double ld;
typedef long long li;
typedef pair <li, li> pi;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	solve ();
	return 0;
}
//#define int li
int n, m;
li matrix[1600][1600];
li gran[1600];
li dp[1600][1600];
li sums[1600][1600];
li mn[1600][1600];
li mx[1600][1600];
void solve ()
{
	for (int i=0; i<1600; i++)
		for (int j=0; j<1600; j++)
			dp[i][j]=-(1LL<<60);
	cin>>n>>m;
	for ( int i=0; i<n; i++ )
	{
		for (int j=0; j<m; j++)
			scanf ("%I64d", &matrix[i][j]);
		sums[i][0]=matrix[i][0];
		for (int  j=1; j<m; j++ )
			sums[i][j]=sums[i][j-1]+matrix[i][j];
	}
	li maximum=-(1<<30);
	for ( int i=m-1; i>=0; i-- )
	{
		dp[0][i]=sums[0][i];
		maximum=max( maximum, sums[0][i] );
		mx[0][i]=maximum;
	}
	for ( int i=1; i<n; i++ )
	{
		if ( i%2 )
		{
			maximum=-(1<<30);
			for ( int j=0; j<m-1; j++ ) 
			{
				dp[i][j]=mx[i-1][j+1]+sums[i][j];
				maximum=max ( maximum, dp[i][j] );
				mx[i][j]=maximum;
			}
		}
		else 
		{
			maximum=-(1<<30);
			for ( int j=m-1; j>0; j-- )
			{
				dp[i][j]=mx[i-1][j-1]+sums[i][j];
				maximum=max ( maximum, dp[i][j] );
				mx[i][j]=maximum;
			}
		}
	}
	li ans=-(1<<30);
	for ( int i=0; i<m; i++ )
		ans=max (ans, dp[n-1][i]);
	cout<<ans;
}