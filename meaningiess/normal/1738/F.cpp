#include<bits/stdc++.h>
#define ll long long
using namespace std;
int d[1010],vis[1010],fa[1010];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	int T;cin>>T;d[0]=-1;
	while (T--)
	{
		int n,i,j;cin>>n;
		for (i=1;i<=n;i++) cin>>d[i];
		for (i=1;i<=n;i++) fa[i]=i;
		for (i=1;i<=n;i++) vis[i]=0;
		for (i=1;i<=n;i++)
		{
			int mx=0;
			for (j=1;j<=n;j++) if (!vis[j] && d[j]>d[mx]) mx=j;
			vis[mx]=1;
			for (j=1;j<=d[mx];j++)
			{
				cout<<"? "<<mx<<endl;
				fflush(stdout);
				int tp;cin>>tp;
				if (vis[tp])
				{
					fa[mx]=tp;
					break;
				}
				vis[tp]=1;fa[tp]=mx;
			}
		}
		cout<<'!';
		for (i=1;i<=n;i++) cout<<' '<<find(i);
		cout<<endl;
		fflush(stdout);
	}
}