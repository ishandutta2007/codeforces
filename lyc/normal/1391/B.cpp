#include<bits/stdc++.h>
using namespace std;
int T,n,m,b[1000][1000],ans;
char ch[1000][1000];
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=m;j++)
		    cin>>ch[i][j];
		ans=0;
		for (int i=1;i<m;i++) if (ch[n][i]!='R') ans++;
		for (int i=1;i<n;i++) if (ch[i][m]!='D') ans++;
		
		cout<<ans<<endl;
	}
}