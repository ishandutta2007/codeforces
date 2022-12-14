#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const long long lmax=2e18;
long long prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
long long num,q,ans,fl,fr,l,r,Log[66];
long long cnt,ll,rr,L,R;
vector<pair<long long,long long> > v;
long long binary(long long n,long long p,bool f)
{
	long long l=1,r=Log[p];
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if (pow(mid,p)>=n) r=mid-1;
		else l=mid+1;
	}
	if (!f) return l;
	if (pow(l,p)==n) return l;
	return r;
}
bool check(long long a,long long s)
{
	long long res=1;
	for (long long i=1;i<=s;i++)
	{
		if (lmax/a<res) return 0;
		res*=a;
	}
	return (res<=1e18);
}
int main()
{
	for (long long i=1;i<(1<<17);i++)
	{
		cnt=1;num=0;
		for (long long j=0;j<17;j++)
		{
			if (i&(1<<j)) 
			{
				if (lmax/prime[j]<cnt) cnt=0;
				cnt*=prime[j];
				num++;
			}
		}
		if (!cnt || cnt>=60) continue;
		if (num&1) v.push_back(make_pair(cnt,1));
		else v.push_back(make_pair(cnt,-1));  
	}
	Log[2]=1e9;Log[3]=1e6;
	for (long long i=4;i<=59;i++)
	{
		for (long long j=2;j<=1e6;j++)
		{
			if (!check(j,i)) 
			{
				Log[i]=j-1;
				break;
			}
		}
	}
	scanf("%I64d",&q);
	while(q--)
	{
		scanf("%I64d%I64d",&l,&r);
		ans=0;
		if (l==1) 
		{
			l++;
			ans++;
		}
		for (long long i=0;i<v.size();i++)
		{
			fl=binary(l,v[i].first,0);
			fr=binary(r,v[i].first,1); 
			ans=ans+v[i].second*(fr-fl+1);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}