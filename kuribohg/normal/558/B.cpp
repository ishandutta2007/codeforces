#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[1000010];
int Min[1000010],Max[1000010],cnt[1000010];
int ans,sub;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=1000000;i++) Min[i]=n+1;
	for(int i=1;i<=1000000;i++) Max[i]=0;
	for(int i=1;i<=n;i++) Min[a[i]]=min(Min[a[i]],i),Max[a[i]]=max(Max[a[i]],i),cnt[a[i]]++;
	ans=-1;
	for(int i=1;i<=1000000;i++)
	{
		if(Min[i]==n+1) continue;
		if(cnt[i]>ans) ans=cnt[i],sub=i;
		else if(cnt[i]==ans)
		{
			if(Max[sub]-Min[sub]>Max[i]-Min[i])
				sub=i;
		}
	}
	printf("%d %d\n",Min[sub],Max[sub]);
	return 0;
}