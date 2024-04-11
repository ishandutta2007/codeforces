#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
char s[30],s1[30];
int cnt[30];
int a[30];
int n;
ll ans=0;
void doit()
{
	ll len=0,n0=0;
	for (int i=1;i<=n;i++)
	{
		if (s[i]!='0')	n0+=a[i];
		len+=a[i];
	}
	ll sum=1;
	for (int i=1;i<=len;i++)
	{
		if (i==1)	sum=sum*n0;else sum=sum*(len-i+1);
	}
	for (int i=1;i<=n;i++)
	{
		ll frac=1;
		for (int j=1;j<=a[i];j++)
			frac*=j;
		sum/=frac;
	}
	ans+=sum;
}
void dfs(int t)
{
	if (t>n)
	{
		doit();
		return;
	}
	for (a[t]=1;a[t]<=cnt[t];a[t]++)
		dfs(t+1);
}
int main()
{
	scanf("%s",s+1);
	strcpy(s1+1,s+1);
	n=strlen(s+1);
	sort(s+1,s+n+1);
	int _n=unique(s+1,s+n+1)-(s+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=_n;j++)
		if (s1[i]==s[j])	cnt[j]++;
	n=_n;
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}