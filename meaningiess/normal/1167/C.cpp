#include<bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
int fa[N],ans[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	int n,i,k,j,t,m,lst;cin>>n>>m;
	for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<=m;i++)
	{
		cin>>k;if (k==0) continue;
		cin>>t;lst=t;
		for (j=2;j<=k;j++)
		{
			cin>>t;int a=find(lst),b=find(t);
			fa[a]=b;
		}
	}
	for (i=1;i<=n;i++) ans[find(i)]++;for (i=1;i<=n;i++) cout<<ans[find(i)]<<' ';
}