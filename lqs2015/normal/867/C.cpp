#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct par
{
	long long sl,a,b;
	bool operator < (const par &k) const
	{
		return a-b<k.a-k.b;
	}
}p[111111];
long long n,s,cur,k,pp,cnt,re,lf,pk,tot,ans,cp,pos,del;
int main()
{
	scanf("%I64d%I64d",&n,&s);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d%I64d%I64d",&p[i].sl,&p[i].a,&p[i].b);
		cur+=p[i].b*p[i].sl;
		cnt+=p[i].sl;
	}
	pp=(cnt-1)/s+1;
	lf=pp*s-cnt;
	sort(p+1,p+n+1);
	reverse(p+1,p+n+1);
	for (long long i=1;i<=n;i++)
	{
		if (p[i].a>p[i].b) 
		{
			pos=i;
			del+=p[i].sl*(p[i].a-p[i].b);
			cp+=p[i].sl;
		}
		else break;
	}
	if (s-cp%s<=lf) 
	{
		printf("%I64d\n",cur+del);
		return 0;
	}
	tot=cp%s;
	long long pdel=del;
	for (long long i=pos;i>=1;i--)
	{
		if (tot<=p[i].sl)
		{
			del-=(p[i].a-p[i].b)*tot;
			break;
		}
		del-=(p[i].a-p[i].b)*p[i].sl;
		tot-=p[i].sl;
	}
	ans=cur+del;
	del=pdel;
	tot=s-cp%s-lf;
	for (long long i=pos+1;i<=n;i++)
	{
		if (p[i].sl>=tot)
		{
			del+=(p[i].a-p[i].b)*tot;
			break;
		}
		del+=(p[i].a-p[i].b)*p[i].sl;
		tot-=p[i].sl;
	}
	ans=max(ans,cur+del);
	printf("%I64d\n",ans);
	return 0;
}