#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int maxn = 1050;
 
int n,m,K;
int findfa(int fa[],const int x)
{
	return fa[x]==x?x:fa[x]=findfa(fa,fa[x]);
}
int fa[maxn][maxn];
int a[maxn][maxn];
 
int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m>>K;
	for(int j=1;j<=m;j++) fa[j][n+1]=n+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1) fa[j][i]=i;
			else if(a[i][j]==2) fa[j][i]=i+1;
			else fa[j][i]=i;
		}
	}
	
	for(int ki=1;ki<=K;ki++)
	{
		int ci; cin>>ci;
		int i=1,j=ci;
		while(i<=n)
		{
			i=findfa(fa[j],i);
//			cerr<<"go "<<i<<' '<<j<<endl;
			if(i<=n)
			{
				int cc=a[i][j];
				
				a[i][j]=2;
				fa[j][i]=i+1;
				if(cc==1) j++;
				else j--;
			}
		}
		cout<<j<<" \n"[ki==K];
	}
	
	return 0;
}