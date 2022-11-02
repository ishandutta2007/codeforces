#include<bits/stdc++.h>
using namespace std;

const int maxn=1010;
int f[maxn];
int is[maxn];
void prepare()
{
	for (int i=2;i<=1000;i++)
	if (!is[i])
	{
		for (int j=i*2;j<=1000;j+=i)
			is[j]=true;
	}
	for (int i=1;i<=1000;i++)
	{
		if (is[i])	f[i]=1;else f[i]=-1;
		for (int j=4;j<=i-4;j++)
			if (f[i-j]!=-1 && f[j]!=-1)
				f[i]=max(f[i],f[i-j]+f[j]);
	}
}
int n,x;
int main()
{
	scanf("%d",&n);
	prepare();
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		int ans=0;
		if (x>1000)
		{
			ans+=(x-1000)/4;
			x-=ans*4;
			while (x>1000)	x-=4,ans++;
		}
		ans+=f[x];
		printf("%d\n",ans);
	}
	return 0;
}