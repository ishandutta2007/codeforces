#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const double eps=1e-12;
double x[111111],w,v[111111],t1[111111],t2[111111];
pair<pair<double,double>,int> a[111111];
pair<double,int> b[111111];
int n,bit[222222],pos,pre,id[111111],ct,sz;
long long ans;
int update(int p)
{
	while(p<=sz)
	{
		bit[p]++;
		p+=p&(-p);
	}
}
int query(int p)
{
	int res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%d%lf",&n,&w);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&v[i]);
		t1[i]=-x[i]/(v[i]-w);
		t2[i]=-x[i]/(v[i]+w);
		a[i]=make_pair(make_pair(t1[i],t2[i]),i);
		b[i]=make_pair(t2[i],i);
	}
	sort(b+1,b+n+1);
	pre=pos=1;
	while(pos<=n)
	{
		while(pos<n && b[pos].first-b[pos+1].first>-eps && b[pos].first-b[pos+1].first<eps) pos++;
		ct++;
		for (int i=pre;i<=pos;i++) id[b[i].second]=ct;
		pos++;
		pre=pos;
	}
	sz=1;
	while(sz<ct) sz*=2;
	sort(a+1,a+n+1);
	pre=pos=1;
	while(pos<=n)
	{
		while(pos<n && a[pos].first.first-a[pos+1].first.first>-eps && a[pos].first.first-a[pos+1].first.first<eps) pos++;
		ans+=(long long)(pos-pre)*(long long)(pos-pre+1)/2;
		for (int i=pre;i<=pos;i++)
		{
			ans+=(long long)query(sz-id[a[i].second]+1);
		} 
		for (int i=pre;i<=pos;i++)
		{
			update(sz-id[a[i].second]+1);
		}
		pos++;
		pre=pos;
	}
	printf("%I64d\n",ans);
	return 0;
}