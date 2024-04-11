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
const ll llinf=1LL*inf*inf;
using namespace std;
int a[200005];
int st[20][100005];
int n,k;
int minOfAll;

template <typename T>
struct SegmentTreeMinInterval//[)
{
	const T unchanged=-1;
	const T maxValue=1e9;
	T* data;
	T* tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn=1;
		while(nn<size)
		{
			nn<<=1;
		}
		data=new T[nn*2+5];
		tag=new T[nn*2+5];
		for(int i=0;i<=nn*2;i++)
		{
			data[i]=maxValue;
			tag[i]=unchanged;
		}
	}
	void build(int a[],int len)
	{
		for(int i=0;i<len;i++)
		{
			data[i+nn]=a[i];
		}
		for(int i=nn-1;i>=1;i--)
		{
			data[i]=min(data[i*2],data[i*2+1]);
		}
	}
	void pushdown(int x)
	{
		if(x>=nn) return;
		if(tag[x]==unchanged) return;
		data[x*2]=tag[x];
		data[x*2+1]=tag[x];
		tag[x*2]=tag[x];
		tag[x*2+1]=tag[x];
		tag[x]=unchanged;
	}
	void change(int ql,int qr,T value)
	{
		change(1,0,nn,ql,qr,value);
	}
	void change(int x,int l,int r,int ql,int qr,T value)
	{
		if(l>=qr || r<=ql) return;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			data[x]=value;
			tag[x]=value;
			return;
		}
		change(x*2,l,l+r>>1,ql,qr,value);
		change(x*2+1,l+r>>1,r,ql,qr,value);
		data[x]=min(data[x*2],data[x*2+1]);
	}
	T query(int ql,int qr)
	{
		return query(1,0,nn,ql,qr);
	}
	T query(int x,int l,int r,int ql,int qr)
	{
		if(l>=qr || r<=ql) return maxValue;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			return data[x];
		}
		return min(query(x*2,l,l+r>>1,ql,qr),query(x*2+1,l+r>>1,r,ql,qr));
	}
};

SegmentTreeMinInterval <int> sgt;

struct Query
{
	int type;
	int l,r;
	int x;
	void input()
	{
		cin>>type;
		cin>>l>>r;
		if(type==1) cin>>x;
		l--;
	}
	void process()
	{
		if(type==1) sgt.change(l,r,x);
		else cout<<sgt.query(l,r)<<endl;
	}
};

Query queries[100005];

void buildst()
{
	minOfAll=inf;
	for(int i=0;i<n;i++)
	{
		st[0][i]=a[i];
		chmin(minOfAll,a[i]);
	}
	for(int k=1;k<20;k++)
	{
		for(int i=0;i<n-(1<<k)+1;i++)
		{
			st[k][i]=min(st[k-1][i],st[k-1][i+(1<<(k-1))]);
//			cout<<k<<' '<<i<<' '<<st[k][i]<<'\n';
		}
	}
}

inline int queryst(int l,int r)
{
	if(l==r) return inf;
	int k;
	for(k=0;k<20;k++)
	{
		if((1<<(k+1))>=r-l) break;
	}
//	cout<<l<<' '<<r<<' '<<min(st[k][l],st[k][r-(1<<k)])<<endl;
	return min(st[k][l],st[k][r-(1<<k)]);
}

inline int querylr(int l,int r)
{
	if(r-l>=n) return minOfAll;
	l%=n;
	r%=n;
	assert(l!=r);
	if(l<r) return queryst(l,r);
	return min(queryst(l,n),queryst(0,r));
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		queries[i].input();
	}
	vector <int> lsh;
	for(int i=0;i<q;i++)
	{
		lsh.push_back(queries[i].l);
		lsh.push_back(queries[i].r);
	}
	sort(all(lsh));
	lsh.erase(unique(all(lsh)),lsh.end());
	for(int i=0;i<q;i++)
	{
		queries[i].l=lower_bound(all(lsh),queries[i].l)-lsh.begin();
		queries[i].r=lower_bound(all(lsh),queries[i].r)-lsh.begin();
	}
	buildst();
	//an 
	for(int i=0;i<(int)lsh.size()-1;i++)
	{
		a[i]=querylr(lsh[i],lsh[i+1]);
	}
	n=(int)lsh.size()-1;
	sgt.init(n);
	sgt.build(a,n);
	for(int i=0;i<q;i++)
	{
		queries[i].process();
	}
	return 0;
}