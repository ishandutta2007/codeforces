#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m;
int a[N+5],b[N+5];
int f[N+5][N+5],nxt[N+5];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	memset(nxt,-1,sizeof(nxt));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]!=b[j]) f[i][j]=f[i-1][j];
			else
			{
				f[i][j]=1;
				nxt[j]=-1;
				for(int k=1;k<=j-1;k++) 
				{
					if(f[i][j]<f[i-1][k]+1&&b[k]<b[j])
					{
						f[i][j]=f[i-1][k]+1;
						nxt[j]=k;
					}
				}
			}
		}
	} 
	int ans=0,st;
	for(int i=1;i<=m;i++) 
	{
		if(ans<f[n][i])
		{
			st=i;
			ans=f[n][i];
		}
	}
	printf("%d\n",ans);
	if(ans==0) return 0;
	vector<int> v;
	for(int i=st;i!=-1;i=nxt[i]) v.push_back(i);
	for(int i=v.size()-1;i>=0;i--) printf("%d ",b[v[i]]);
	printf("\n");
	return 0;
}