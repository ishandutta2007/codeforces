#include<bits/stdc++.h>
#define ll long long
using namespace std;
int vis[1010][1010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,j,tp,ans=0;cin>>n;
		for (i=0;i<=n+1;i++) for (j=0;j<=n+1;j++) vis[i][j]=0;
		for (i=1;i<=n;i++) for (j=1;j<=n;j++)
		{
			cin>>tp;
			if (!vis[i-1][j] && !vis[i][j-1] && !vis[i+1][j] && !vis[i][j+1])
			{
				ans^=tp;vis[i-1][j]=vis[i][j-1]=vis[i+1][j]=vis[i][j+1]=1;
			}
		}
		cout<<ans<<endl;
	}
}