#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
using namespace std;
int n,q;
int nn;
vector <pair<int,int> > vec[500005];
ll dis[500005];
vector <int> leaves;
ll ans[500005];
vector <pair<pii,int> > query[500005];
int Lleaf[500005],Rleaf[500005];

//may not completely correct
template <typename T>
struct SegmentTreeMinInterval//[)
{
//	#define ll int
	T* data;
	T* tagSum;
	int nn;
	T inf;
	int size()
	{
		return nn;
	}
	void init(int size,T _inf)
	{
		nn=1;
		inf=_inf;
		while(nn<size)
		{
			nn<<=1;
		}
		data=new T[nn*2+5];
		tagSum=new T[nn*2+5];
		for(int i=0;i<=nn*2;i++)
		{
			data[i]=inf;
			tagSum[i]=0;
		}
	}
	void pushdown(int x)
	{
		if(x>=nn) return;
		data[x*2]+=tagSum[x];
		data[x*2+1]+=tagSum[x];
		tagSum[x*2]+=tagSum[x];
		tagSum[x*2+1]+=tagSum[x];
		tagSum[x]=0;
	}
	void add(int l,int r,T value)
	{
		add(1,0,nn,l,r,value);
	}
	void add(int x,int l,int r,int ql,int qr,T value)
	{
		if(l>=qr || r<=ql) return;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			data[x]=data[x]+value;
			tagSum[x]+=value;
			return;
		}
		add(x*2,l,l+r>>1,ql,qr,value);
		add(x*2+1,l+r>>1,r,ql,qr,value);
		data[x]=min(data[x*2],data[x*2+1]);
	}
	T query(int ql,int qr)
	{
		return query(1,0,nn,ql,qr);
	}
	T query(int x,int l,int r,int ql,int qr)
	{
		if(l>=qr || r<=ql) return inf;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			return data[x];
		}
		return min(query(x*2,l,l+r>>1,ql,qr),query(x*2+1,l+r>>1,r,ql,qr));
	}
	void build()
	{
		for(int i=0;i<leaves.size();i++)
		{
			data[i+nn]=dis[i];
		}
		for(int i=nn-1;i>=1;i--)
		{
			data[i]=min(data[i*2],data[i*2+1]);
		}
	}
//	#undef ll
};
SegmentTreeMinInterval <ll> sgt;

void dfs(int x,int par=-1,ll depth=0)
{
	Lleaf[x]=n;
	Rleaf[x]=0;
	int son=0;
	for(auto u:vec[x])
	{
		if(u.first==par) continue;
		son++;
		dfs(u.first,x,depth+u.second);
		Lleaf[x]=min(Lleaf[x],Lleaf[u.first]);
		Rleaf[x]=max(Rleaf[x],Rleaf[u.first]);
	}
	if(son==0) dis[leaves.size()]=depth,Lleaf[x]=leaves.size(),Rleaf[x]=Lleaf[x]+1,leaves.push_back(x);
}

void go(int x,int p=-1)
{
	for(auto &Q:query[x])
	{
		ans[Q.second]=sgt.query(Q.first.first,Q.first.second);
	}
	for(auto u:vec[x])
	{
		if(u.first==p) continue;
		sgt.add(0,leaves.size(),u.second);
		sgt.add(Lleaf[u.first],Rleaf[u.first],-2*u.second);
		go(u.first,x);
		sgt.add(0,leaves.size(),-u.second);
		sgt.add(Lleaf[u.first],Rleaf[u.first],2*u.second);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>q;
	int p,cost;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&p,&cost);
		p--;
		vec[p].push_back(mp(i,cost));
		vec[i].push_back(mp(p,cost));
	}
	dfs(0);
	int x,y,z;
	for(int i=0;i<q;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		x--;
		y--;
		z--;
		int l=lower_bound(all(leaves),y)-leaves.begin();
		int r=upper_bound(all(leaves),z)-leaves.begin();
		assert(l!=r);
		query[x].push_back(mp(mp(l,r),i));
	}
	sgt.init((int)leaves.size(),1LL*inf*inf);
	sgt.build();
	go(0);
	for(int i=0;i<q;i++)
	{
		printf("%I64d\n",ans[i]);
	}
	return 0;
}