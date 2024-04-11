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
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
int n,m,k;
map <pair<int,int>,bool> board;

//quality not guarantee
template <typename T>
struct SegmentTreeMinIntervalAdd//[)
{
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
			data[i]=inf;
			tag[i]=0;
		}
	}
	void build(T a[],int n)
	{
		for(int i=0;i<n;i++)
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
		data[x*2]+=tag[x];
		data[x*2+1]+=tag[x];
		tag[x*2]+=tag[x];
		tag[x*2+1]+=tag[x];
		tag[x]=0;
	}
	void add(int ql,int qr,T value)
	{
		add(1,0,nn,ql,qr,value);
	}
	void add(int x,int l,int r,int ql,int qr,T value)
	{
		if(l>=qr || r<=ql) return;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			data[x]+=value;
			tag[x]+=value;
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
	//used in debug
	void print()
	{
		for(int i=0;i<nn;i++)
		{
			cout<<query(i,i+1)<<' ';
		}
		cout<<endl;
	}
};

int a[2*200005];
int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k>>m;
	SegmentTreeMinIntervalAdd <int> sgt;
	sgt.init(2*n);
	int x,y;
	for(int i=0;i<2*n;i++)
	{
		a[i]=i;
	}
	sgt.build(a,2*n);
	const int lowbound=2*n-1-n;
	multiset <int> squ;
	int curlow;
//	sgt.print();
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		int ny=y+abs(k-x);
		int apos=2*n-1-ny;
//		cout<<apos<<' '<<curlow<<endl;
		int coe;
		if(board[mp(x,y)]==1) board[mp(x,y)]=0,coe=-1;else board[mp(x,y)]=1,coe=1;
		if(coe==1) squ.insert(apos);else squ.erase(squ.find(apos));
		curlow=min((squ.empty()?lowbound:*squ.begin()),lowbound);
		sgt.add(apos,2*n,-coe);
//		sgt.print();
		cout<<max(0,lowbound-1-sgt.query(curlow,2*n))<<endl;
	}
	return 0;
}