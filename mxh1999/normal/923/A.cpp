#include<bits/stdc++.h>
using namespace std;

const int maxn=1000010;
int n;
bool pri[maxn];
int f[maxn];
int suf[maxn];
void prepare()
{
	for (int i=2;i<=n;i++)	pri[i]=true;
	for (int i=2;i<=n;i++)
	if (pri[i])
	{
		for (int j=i*2;j<=n;j+=i)
		{
			pri[j]=false;
			f[j]=j-i+1;
		}
	}
	suf[n]=f[n];
	for (int i=n-1;i>=2;i--)
	{
		suf[i]=suf[i+1];
		if (f[i]!=0)	suf[i]=min(suf[i],f[i]);
	}
}
int main()
{
	scanf("%d",&n);
	prepare();
	int ans=suf[n];
	for (int i=2;i<=n;i++)
	if (pri[i] && n%i==0)
		ans=min(ans,suf[n-i+1]);
	printf("%d\n",ans);
	return 0;
}