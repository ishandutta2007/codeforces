#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
typedef long long li;
typedef long double ld;
#define mp make_pair
#define pb push_back
typedef pair <int, int> pi;
typedef vector <int> vi;
void solve ();
int main ()
{
#ifdef _DEBUG
        freopen ("in.txt", "r", stdin);
        //freopen ("out.txt", "w", stdout);
#endif
        int t=1;
        while (t--)
        solve ();
}
int n, a[2000];
int dp[1050][1050];
pi pred[1050][1050];
pi p[1050][1050];
vector <pi> ans;
void solve ()
{
	cin>>n;
	bool flag=false;
	if ( n%2 )
	{
		n++;
		a[n]=0;
		flag=true;
	}
	for ( int i=0; i<n; i++ )
		cin>>a[i+1];
	for ( int i=0; i<=n+1; i++ )
		for ( int j=0; j<=n+1; j++ )
			dp[i][j]=(1<<30);
	dp[1][1]=0;
	p[1][1]=mp (0, 0);
	//cout<<n<<endl;
	for ( int i=1; i<=n-1; i+=2 )
		for ( int j=1; j<=i;  j++ )
		{
			//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			int man=a[j], one=a[i+1], two=a[i+2];
			int ifman=max ( one, two );
			if ( dp[i+2][j]>dp[i][j]+ifman )
			{
				dp[i+2][j]=dp[i][j]+ifman;
				pred[i+2][j]=mp ( i+1, i+2 );
				p[i+2][j]=mp ( i, j );
			}
			int ifone=max ( two, man );
			if ( dp[i+2][i+1]>dp[i][j]+ifone )
			{
				dp[i+2][i+1]=dp[i][j]+ifone;
				pred[i+2][i+1]=mp ( j, i+2 );
				p[i+2][i+1]=mp ( i, j );
			}
			int iftwo=max ( one, man );
			if ( dp[i+2][i+2]>dp[i][j]+iftwo )
			{
				dp[i+2][i+2]=dp[i][j]+iftwo;
				pred[i+2][i+2]=mp ( j, i+1 );
				p[i+2][i+2]=mp ( i, j );
			}
		}
	pi cur=pred[n+1][n+1], current=p[n+1][n+1];
	//cout<<current.first<<' '<<current.second<<endl;
	while ( current!=mp (0, 0) )
	{
		ans.pb(cur);
		pi shit=current;
		current=p[current.first][current.second];
		cur=pred[shit.first][shit.second];
	}
	cout<<dp[n+1][n+1]<<endl;
	for ( int i=ans.size()-1; i>=0; i-- )
	{
		cout<<ans[i].first<<' ';
		if ( ans[i].second!=n || !flag )
			cout<<ans[i].second;
		cout<<endl;
	}
}