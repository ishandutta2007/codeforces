#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<stack>
using namespace std;
long long n,L,a[555555],b[555555],s[1111111],len[1111111],p[1111111],cnt,l,r,mid1,mid2,pos,kp[1111111],sum;
pair<pair<long long,long long>,long long> k[1111111];
long long ans[555555];
stack<pair<long long,long long> > st;
long long find(long long i)
{
	for (long long j=1;j<=n;j++) kp[j]=abs(s[j]+p[i]);
	long long res=0;
	for (long long j=1;j<=n;j++) res+=kp[j]*len[j];
	return res;
}
int main()
{
	scanf("%lld%lld",&L,&n);
	for (long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (long long i=1;i<=n;i++) scanf("%lld",&b[i]);
	for (long long i=1;i<=n;i++) k[i]=make_pair(make_pair(a[i],1),i);
	for (long long i=1;i<=n;i++) k[i+n]=make_pair(make_pair(b[i],-1),i);
	n*=2;
	sort(k+1,k+n+1);
	for (long long i=1;i<n;i++) len[i]=k[i+1].first.first-k[i].first.first;
	len[n]=k[1].first.first-k[n].first.first+L;
	for (long long i=1;i<n;i++) s[i]=s[i-1]+k[i].first.second;
	for (long long i=1;i<n;i++) p[i]=p[i-1]-k[i].first.second;
	sort(p+1,p+n+1);
	cnt=unique(p+1,p+n+1)-p-1;
	l=1;r=cnt;
	while(l<r)
	{
		mid1=l+(r-l)/3;
		mid2=r-(r-l)/3;
		if (find(mid1)<find(mid2)) r=mid2-1;
		else if (find(mid1)>find(mid2)) l=mid1+1;
		else
		{
			l=mid1+1;
			r=mid2-1;
		}
	}
	printf("%lld\n",find(l));
	if (!p[l]) pos=1;
	for (long long i=1;i<n;i++)
	{
		sum-=k[i].first.second;
		if (sum==p[l])
		{
			pos=i+1;
			break;
		}
	}
	for (long long i=pos;i<=n;i++)
	{
		if (st.empty() || st.top().first==k[i].first.second) 
		{
			st.push(make_pair(k[i].first.second,k[i].second));
			continue;
		}
		pair<long long,long long> xx=st.top();
		st.pop();
		if (k[i].first.second==1) ans[k[i].second]=xx.second;
		else ans[xx.second]=k[i].second;
	}
	for (long long i=1;i<pos;i++)
	{
		if (st.empty() || st.top().first==k[i].first.second) 
		{
			st.push(make_pair(k[i].first.second,k[i].second));
			continue;
		}
		pair<long long,long long> xx=st.top();
		st.pop();
		if (k[i].first.second==1) ans[k[i].second]=xx.second;
		else ans[xx.second]=k[i].second;
	}
	for (long long i=1;i<=n/2;i++) printf("%lld ",ans[i]);
	return 0;
}