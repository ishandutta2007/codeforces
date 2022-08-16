#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

typedef long long ll;

const int MaxN=1<<18;

int n;
vector<pair<int,int> > v[MaxN];
int deep[MaxN],first[MaxN];
long long dis[MaxN];

int len;
int LCA[MaxN<<1];

int LCA_min(int x,int y)
{
	return (deep[x]<deep[y])?x:y;
}

void LCA_add(int k,int x)
{
	LCA[k+=MaxN-1]=x;
	for (k>>=1;k;k>>=1)
		LCA[k]=LCA_min(LCA[k<<1],LCA[k<<1|1]);
}

int LCA_get(int k,int L,int R,int x,int y)
{
	if (L==x&&R==y)
		return LCA[k];
	int mid=(L+R)>>1;
	if (y<=mid)
		return LCA_get(k<<1,L,mid,x,y);
	if (x>mid)
		return LCA_get(k<<1|1,mid+1,R,x,y);
	return LCA_min(LCA_get(k<<1,L,mid,x,mid),LCA_get(k<<1|1,mid+1,R,mid+1,y));
}

int LCA_get(int x,int y)
{
	return LCA_get(1,1,MaxN,min(first[x],first[y]),max(first[x],first[y]));
}

void build(int x,int p)
{
	LCA_add(first[x]=++len,x);
	for (vector<pair<int,int> >::iterator it=v[x].begin();it!=v[x].end();++it)
	{
		if (it->first==p) continue;
		dis[it->first]=dis[x]+it->second;
		deep[it->first]=deep[x]+1;
		build(it->first,x);
		LCA_add(++len,x);
	}
}

int k;

void init()
{
	cin>>n>>k;
	for (int i=1;i<n;++i)
	{
		int x,y,c=1;
		scanf("%d%d",&x,&y);
		v[x].push_back(make_pair(y,c));
		v[y].push_back(make_pair(x,c));
	}
	build(1,0);
}

long long getdis(int x,int y)
{
	return dis[x]+dis[y]-2*dis[LCA_get(x,y)];
}

set<pair<int,int> > H;

int ans=0;

void jia(int x)
{
	set<pair<int,int> >::iterator itx,ity;
			itx=ity=H.insert(make_pair(first[x],x)).first;
			--itx;
			++ity;
			if (itx->second&&ity->second)
				ans-=getdis(itx->second,ity->second);
			if (itx->second)
				ans+=getdis(x,itx->second);
			if (ity->second)
				ans+=getdis(x,ity->second);
}

void jian(int x)
{
	set<pair<int,int> >::iterator it,itx,ity;
			it=itx=ity=H.find(make_pair(first[x],x));
			--itx;
			++ity;
			if (itx->second&&ity->second)
				ans+=getdis(itx->second,ity->second);
			if (itx->second)
				ans-=getdis(x,itx->second);
			if (ity->second)
				ans-=getdis(x,ity->second);
			H.erase(it);
}

int wen()
{
	if (H.size()==2)
				return 0;
			else
			{
				set<pair<int,int> >::iterator x=H.begin();
				set<pair<int,int> >::reverse_iterator y=H.rbegin();
				++x;
				++y;
				return (ans+getdis(x->second,y->second))>>1;
			}
}

void hehe()
{
	
	H.insert(make_pair(0,0));
	H.insert(make_pair(len+1,0));
	int x=1,y=1;
	jia(1);
	ll aans=1;
	while (y<=n)
	{
		if (wen()<k)
		{
			aans=max(aans,(ll)y-x+1);
			++y;
			if (y>n) break;
			jia(y);
		}
		else
		{
			jian(x);
			++x;
		}
	}
	cout<<aans<<endl;
}

int main()
{
	init();
	//work();
	hehe();
	return 0;
}