#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
struct item
{
	long long p,t,s,id;
	bool operator < (const item &a) const
	{
		return t<a.t;
	}
}it[55555];
long long n,x,l,r,mid,p,res,ans,en[55555],pos;
map<long long,bool> mp;
long long doit()
{
	priority_queue<pair<long long,pair<long long,long long> > > q;
	q.push(make_pair(it[1].p,make_pair(it[1].s,it[1].id)));
	long long ret,tim;
	for (long long i=2;i<=n;i++)
	{
		ret=it[i].t-it[i-1].t;
		while(!q.empty() && ret>0)
		{
			long long x=q.top().second.first,y=q.top().second.second,pp=q.top().first;
			q.pop();
			if (x<=ret)
			{
				ret-=x;
				en[y]=it[i].t-ret;
			}
			else
			{
				x-=ret;
				ret=0;
				q.push(make_pair(pp,make_pair(x,y))); 
			}
		}
		q.push(make_pair(it[i].p,make_pair(it[i].s,it[i].id)));
	}
	tim=it[n].t;
	while(!q.empty())
	{
		en[q.top().second.second]=tim+q.top().second.first;
		tim=en[q.top().second.second];
		q.pop();
	}
	return en[it[pos].id];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d%I64d%I64d",&it[i].t,&it[i].s,&it[i].p);
		it[i].id=i;
		mp[it[i].p]=1;
	}
	scanf("%I64d",&x);
	sort(it+1,it+n+1);
	for (int i=1;i<=n;i++)
	{
		if (it[i].p==-1) pos=i;
	}
	l=1;r=1e9;
	while(l<=r)
	{
		mid=(l+r)/2;p=mid;
		while(p>=l && mp[p]) p--;
		if (p<l) 
		{
			p=mid;
			while(p<=r && mp[p]) p++;
			if (p>r) break;
		}
		it[pos].p=p;
		res=doit();
		if (res==x)
		{
			ans=p;
			break;
		}
		else if (res>x) l=p+1;
		else r=p-1;
	}
	printf("%I64d\n",ans);
	for (long long i=1;i<=n;i++)
	{
		printf("%I64d ",en[i]);
	}
	printf("\n");
	return 0;
}