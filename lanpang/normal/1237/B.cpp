#include<bits/stdc++.h>
using namespace std;

int n,maxn,ans;
int a[100010],b[100010],re[100010];
bool vis[100010];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		re[a[i]]=i;
	}
	maxn=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		b[i]=re[b[i]];
		vis[b[i]]=1;
		if(maxn<b[i]) ans++;
		else 
		{
			maxn++;
			while(vis[maxn]) maxn++;
		}
		//cout<<b[i]<<" "<<ans<<endl;
	}
	printf("%d\n",ans);
	return 0;
}