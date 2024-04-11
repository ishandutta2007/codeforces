#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;
const long long mod=1e9+7;
long long n,k,l[1111111],r[1111111],L,R,mid,ans,a[1111111];
deque<pair<long long,long long> > q;
pair<long long,long long> add;
long long calc(long long n)
{
	return (n+n%k)*(n/k+1)/2;
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	k--;
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (long long i=1;i<=n;i++)
	{
		if (!q.size() || q[0].first<a[i]) l[i]=1;
		else if (q[q.size()-1].first>=a[i]) l[i]=i;
		else
		{
			L=0;R=q.size()-1;
			while(L<=R)
			{
				mid=(L+R)/2;
				if (q[mid].first>=a[i]) L=mid+1;
				else R=mid-1;
			}
			l[i]=q[R].second+1;
		}
		add=make_pair(a[i],i);
		while(!q.empty() && a[i]>=q.back().first) q.pop_back();
		q.push_back(add); 
	}
	q.clear();
	for (long long i=n;i>=1;i--)
	{
		if (!q.size() || q[0].first<=a[i]) r[i]=n;
		else if (q[q.size()-1].first>a[i]) r[i]=i;
		else
		{
			L=0;R=q.size()-1;
			while(L<=R)
			{
				mid=(L+R)/2;
				if (q[mid].first>a[i]) L=mid+1;
				else R=mid-1;
			}
			r[i]=q[R].second-1;
		}
		add=make_pair(a[i],i);
		while(!q.empty() && a[i]>q.back().first) q.pop_back();
		q.push_back(add);
	}
	for (long long i=1;i<=n;i++)
	{
		ans=(ans+a[i]*((calc(r[i]-l[i]+1)-calc(i-l[i])-calc(r[i]-i)-1)%mod))%mod;
	}
	printf("%I64d\n",ans);
	return 0;
}