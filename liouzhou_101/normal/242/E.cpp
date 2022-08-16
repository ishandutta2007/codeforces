#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=1<<17;

int n,m;

struct segment_tree
{
	pair<int,int> v[MaxN<<1];
	int p[MaxN<<1];
	void build(int k,int L,int R)
	{
		v[k].first=R-L+1;
		if (L==R) return;
		int mid=(L+R)>>1;
		build(k<<1,L,mid);
		build(k<<1|1,mid+1,R);
	}
	void clear(int k)
	{
		if (p[k])
		{
			swap(v[k<<1].first,v[k<<1].second);
			p[k<<1]^=1;
			swap(v[k<<1|1].first,v[k<<1|1].second);
			p[k<<1|1]^=1;
			p[k]=0;
		}
	}
	void deal(int k,int L,int R,int x,int y)
	{
		if (L==x&&R==y)
		{
			swap(v[k].first,v[k].second);
			p[k]^=1;
			return;
		}
		clear(k);
		int mid=(L+R)>>1;
		if (y<=mid)
			deal(k<<1,L,mid,x,y);
		else if (x>mid)
			deal(k<<1|1,mid+1,R,x,y);
		else
		{
			deal(k<<1,L,mid,x,mid);
			deal(k<<1|1,mid+1,R,mid+1,y);
		}
		v[k].first=v[k<<1].first+v[k<<1|1].first;
		v[k].second=v[k<<1].second+v[k<<1|1].second;
	}
	pair<int,int> get(int k,int L,int R,int x,int y)
	{
		if (L==x&&R==y)
			return v[k];
		clear(k);
		int mid=(L+R)>>1;
		if (y<=mid)
			return get(k<<1,L,mid,x,y);
		else if (x>mid)
			return get(k<<1|1,mid+1,R,x,y);
		else
		{
			pair<int,int> Lc=get(k<<1,L,mid,x,mid);
			pair<int,int> Rc=get(k<<1|1,mid+1,R,mid+1,y);
			return make_pair(Lc.first+Rc.first,Lc.second+Rc.second);
		}
	}
}T[20];

int main()
{
	for (int k=0;k<20;++k)
		T[k].build(1,1,MaxN);
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		for (int k=0;k<20;++k)
			if (x&(1<<k))
				T[k].deal(1,1,MaxN,i,i);
	}
	cin>>m;
	while (m--)
	{
		int flag;
		scanf("%d",&flag);
		if (flag==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			long long ans=0;
			for (int k=0;k<20;++k)
				ans+=T[k].get(1,1,MaxN,x,y).second*(1LL<<k);
			printf("%I64d\n",ans);
		}
		else
		{
			int x,y,s;
			scanf("%d%d%d",&x,&y,&s);
			for (int k=0;k<20;++k)
				if (s&(1<<k))
					T[k].deal(1,1,MaxN,x,y);
		}
	}
	return 0;
}