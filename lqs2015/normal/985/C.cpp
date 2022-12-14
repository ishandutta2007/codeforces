#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,k,m,a[111111],l,pos,cur,ans,lst;
bool f[111111];
int main()
{
	scanf("%I64d%I64d%I64d",&n,&k,&l);
	m=n*k;
	for (long long i=1;i<=m;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+m+1);
	pos=1;cur=a[1];lst=n;
	for (long long i=1;i<=n;i++)
	{
		if (a[pos]-cur>l) break;
		ans+=a[pos];
		f[pos]=1;
		pos+=k;
		lst--;
	}
	for (long long i=m;i>=1;i--)
	{
		if (a[i]-a[1]<=l) 
		{
			pos=i;
			break;
		}
	}
	while(lst>0 && pos>0)
	{
		if (!f[pos])
		{
			ans+=a[pos];
			lst--;
		}
		pos--;
	}
	if (!lst) printf("%I64d\n",ans);
	else printf("0\n");
	return 0;
}