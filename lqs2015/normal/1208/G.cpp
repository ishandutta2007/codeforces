#include<bits/stdc++.h>
using namespace std;
int n,k,phi[1111111],cnt,prime[1111111];
bool f[1111111];
long long ans;
void Init()
{
	phi[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!f[i])
		{
			prime[++cnt]=i;
			phi[i]=i-1;
		}
		for (int j=1;j<=cnt && i*prime[j]<=n;j++)
		{
			f[i*prime[j]]=1;
			if (i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	if (k==1)
	{
		printf("3\n");
		return 0;
	}
	Init();
	sort(phi+1,phi+n+1);k+=2;
	for (int i=1;i<=k;i++) ans+=phi[i];
	printf("%lld\n",ans);
	return 0;
}