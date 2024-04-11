#include<bits/stdc++.h>
#define ll long long
using namespace std;
int us[100010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,a,b,c;cin>>n>>m;
		for (i=1;i<=n;i++) us[i]=0;
		for (i=1;i<=m;i++)
		{
			cin>>a>>b>>c;us[b]=1;
		}
		for (i=1;i<=n;i++) if (!us[i]) break;
		b=i;
		for (i=1;i<=n;i++) if (i!=b) cout<<i<<' '<<b<<endl;
	}
}