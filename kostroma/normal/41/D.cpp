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
typedef vector <li, li> vli;
typedef pair <li, li> pli;
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
//#define int li
int n, m, k;
int a[200][200];
int dp[200][200][20];
char pred[200][200][20];
pair <pi, int> last[200][200][20];
void solve ()
{
	cin>>n>>m>>k;
	k++;
	for ( int i=0; i<n; i++ )
		for( int j=0; j<m; j++ )
			scanf ("%1d", &a[n-1-i][j]);
	int ans=-1, curbest=0;
	string curans;
	for ( int w=0; w<m; w++ )
	{
		memset (dp, -1, sizeof (dp));
		memset (pred, 0, sizeof (pred));
		int z=a[0][w];
		dp[0][w][z%k]=z;
		for ( int i=0; i<n-1; i++ )
			for ( int j=0; j<m; j++ )
				for ( int mod=0; mod<k; mod++ )
					if ( dp[i][j][mod]!=-1 )
				{
					int cur=dp[i][j][mod];
					int add;
					if ( j>0 )
					{
						add=a[i+1][j-1];
						if ( dp[i+1][j-1][(mod+add)%k]<cur+add )
						{
						dp[i+1][j-1][(mod+add)%k]=cur+add;
						pred[i+1][j-1][(mod+add)%k]='L';
						last[i+1][j-1][(mod+add)%k]=mp ( mp(i, j), mod );
						}
					}
					if ( j<m-1 )
					{
						add=a[i+1][j+1];
						if ( dp[i+1][j+1][(mod+add)%k]<cur+add )
						{
						dp[i+1][j+1][(mod+add)%k]=cur+add;
						pred[i+1][j+1][(mod+add)%k]='R';
						last[i+1][j+1][(mod+add)%k]=mp ( mp(i, j), mod );
						}
					}
				}
		for ( int i=0; i<m; i++ )
			if ( dp[n-1][i][0]>ans )
			{
				ans=dp[n-1][i][0];
				curbest=w;
				curans.resize(0);
				pi now=mp (n-1, i);
				int mod=0;
				while ( now!=mp (0, curbest) )
				{
					curans.pb (pred[now.first][now.second][mod]);
					pi good=now;
					now=last[now.first][now.second][mod].first;
					mod=last[good.first][good.second][mod].second;
				}
			}
	}
	if ( ans==-1 )
	{
		cout<<"-1";
		return;
	}
	reverse (curans.begin(), curans.end());
	cout<<ans<<endl<<curbest+1<<endl<<curans;
}