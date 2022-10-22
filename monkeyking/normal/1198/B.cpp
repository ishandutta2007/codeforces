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
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,q;
int a[200005];

//may not completely correct
struct SegmentTreeMaxInterval//[)
{
	int* data;
	int* tag;
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
		data=new int[nn*2+5];
		tag=new int[nn*2+5];
		for(int i=0;i<=nn*2;i++)
		{
			data[i]=0;
			tag[i]=0;
		}
	}
	void build(int x)
	{
		if(x>=nn) return;
		build(x*2);
		build(x*2+1);
		data[x]=max(data[x*2],data[x*2+1]);
	}
	void init(int size,int a[])
	{
		nn=1;
		while(nn<size)
		{
			nn<<=1;
		}
		data=new int[nn*2+5];
		tag=new int[nn*2+5];
		for(int i=0;i<=nn*2;i++)
		{
			data[i]=0;
			tag[i]=0;
		}
		for(int i=nn;i<nn+size;i++)
		{
			data[i]=a[i-nn];
		}
		build(1);
	}
	void pushdown(int x)
	{
		if(x>=nn) return;
		data[x*2]=max(data[x*2],tag[x]);
		data[x*2+1]=max(data[x*2+1],tag[x]);
		tag[x*2]=max(tag[x*2],tag[x]);
		tag[x*2+1]=max(tag[x*2+1],tag[x]);
		tag[x]=0;
	}
	void update(int ql,int qr,int value)
	{
		update(1,0,nn,ql,qr,value);
	}
	void update(int x,int l,int r,int ql,int qr,int value)
	{
		if(l>=qr || r<=ql) return;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			data[x]=max(data[x],value);
			tag[x]=max(tag[x],value);
			return;
		}
		update(x*2,l,l+r>>1,ql,qr,value);
		update(x*2+1,l+r>>1,r,ql,qr,value);
		data[x]=max(data[x*2],data[x*2+1]);
	}
	int query(int ql,int qr)
	{
		return query(1,0,nn,ql,qr);
	}
	int query(int x,int l,int r,int ql,int qr)
	{
		if(l>=qr || r<=ql) return 0;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			return data[x];
		}
		return max(query(x*2,l,l+r>>1,ql,qr),query(x*2+1,l+r>>1,r,ql,qr));
	}
	void change(int x,int l,int r,int pos,int value)
	{
		if(pos>=r || pos<l) return;
		pushdown(x);
		if(l==pos && r==l+1)
		{
			data[x]=value;
			tag[x]=0;
			return;
		}
		change(x*2,l,l+r>>1,pos,value);
		change(x*2+1,l+r>>1,r,pos,value);
		data[x]=max(data[x*2],data[x*2]+1);
	}
}sgt;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	cin>>q;
	sgt.init(n,a);
	int type;
	int x,y;
	for(int i=0;i<q;i++)
	{
		scanf("%d",&type);
		if(type==2)
		{
			scanf("%d",&x);
			sgt.update(0,n,x);
		}
		else
		{
			scanf("%d%d",&x,&y);
			sgt.change(1,0,sgt.size(),x-1,y);
		}
	}
	for(int j=0;j<n;j++)
	{
		printf("%d ",sgt.query(j,j+1));
	}
	cout<<endl;
	return 0;
}