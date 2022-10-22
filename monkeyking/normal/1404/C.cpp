//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//
//template <typename T=int>
//struct SegmentTreeIntervalSum
//{
//	const T E=0;
//	int nn;
//	T *data;
//	T *tag;
//	void init(int _n)
//	{
//		nn=1;
//		while(nn<_n) nn<<=1;
//		data=new T[nn*2+5];
//		tag=new T[nn*2+5];
//		for(int i=0;i<2*nn;i++)
//		{
//			tag[i]=E;
//			data[i]=E;
//		}
//	}
//	void pushdown(int x,int l,int r)
//	{
//		if(x>=nn) return;
//		data[x*2]+=tag[x]*(r-l>>1);
//		data[x*2+1]+=tag[x]*(r-l>>1);
//		tag[x*2]+=tag[x];
//		tag[x*2+1]+=tag[x];
//		tag[x]=0;
//	}
//	void build(T a[],int n)
//	{
//		for(int i=0;i<n;i++)
//		{
//			data[i+nn]=a[i];
//		}
//		for(int i=nn-1;i>=1;i--)
//		{
//			data[i]=data[i*2]+data[i*2+1];
//		}
//	}
//	void add(int x,int ql,int qr,int l,int r,T delta)
//	{
//		if(l>=qr || r<=ql) return;
//		pushdown(x,l,r);
//		if(l>=ql && r<=qr)
//		{
//			tag[x]+=delta;
//			data[x]+=delta*(r-l);
//			return;
//		}
//		add(x*2,ql,qr,l,l+r>>1,delta);
//		add(x*2+1,ql,qr,l+r>>1,r,delta);
//		data[x]=data[x*2]+data[x*2+1];
//	}
//	T query(int x,int ql,int qr,int l,int r)
//	{
//		if(l>=qr || r<=ql) return E;
//		pushdown(x,l,r);
//		if(l>=ql && r<=qr)
//		{
//			return data[x];
//		}
//		return query(x*2,ql,qr,l,l+r>>1)+query(x*2+1,ql,qr,l+r>>1,r);
//	}
//	inline void add(int l,int r,int delta)
//	{
//		add(1,l,r,0,nn,delta);
//	}
//	inline T query(int l,int r)
//	{
//		return query(1,l,r,0,nn);
//	}
//};
//SegmentTreeIntervalSum <int> sgtSum;
//
//
////quality guarantee
//template <typename T=int>
//struct SegmentTreeMinAdd//[)
//{
////	#define ll int
//	T* data;
//	T* tagSum;
//	int nn;
//	T inf;
//	int size()
//	{
//		return nn;
//	}
//	void init(int size,T _inf)
//	{
//		nn=1;
//		inf=_inf;
//		while(nn<size)
//		{
//			nn<<=1;
//		}
//		data=new T[nn*2+5];
//		tagSum=new T[nn*2+5];
//		for(int i=0;i<=nn*2;i++)
//		{
//			data[i]=inf;
//			tagSum[i]=0;
//		}
//	}
//	void pushdown(int x)
//	{
//		if(x>=nn) return;
//		data[x*2]+=tagSum[x];
//		data[x*2+1]+=tagSum[x];
//		tagSum[x*2]+=tagSum[x];
//		tagSum[x*2+1]+=tagSum[x];
//		tagSum[x]=0;
//	}
//	void add(int l,int r,T value)
//	{
//		add(1,0,nn,l,r,value);
//	}
//	void add(int x,int l,int r,int ql,int qr,T value)
//	{
//		if(l>=qr || r<=ql) return;
//		pushdown(x);
//		if(l>=ql && r<=qr)
//		{
//			data[x]=data[x]+value;
//			tagSum[x]+=value;
//			return;
//		}
//		add(x*2,l,l+r>>1,ql,qr,value);
//		add(x*2+1,l+r>>1,r,ql,qr,value);
//		data[x]=min(data[x*2],data[x*2+1]);
//	}
//	T query()
//	{
//		return data[1];
//	}
//	T query(int ql,int qr)
//	{
//		return query(1,0,nn,ql,qr);
//	}
//	T query(int x,int l,int r,int ql,int qr)
//	{
//		if(l>=qr || r<=ql) return inf;
//		pushdown(x);
//		if(l>=ql && r<=qr)
//		{
//			return data[x];
//		}
//		return min(query(x*2,l,l+r>>1,ql,qr),query(x*2+1,l+r>>1,r,ql,qr));
//	}
//	void build(int a[],int len)
//	{
//		for(int i=0;i<len;i++)
//		{
//			data[i+nn]=a[i];
//		}
//		for(int i=nn-1;i>=1;i--)
//		{
//			data[i]=min(data[i*2],data[i*2+1]);
//		}
//	}
//	inline int find0()
//	{
//		if(data[1]>0) return -1;
//		int now=1;
//		while(now<nn)
//		{
//			pushdown(now);
////			cout<<now<<' '<<data[now]<<' '<<data[now*2]<<' '<<data[now*2+1]<<endl;
////			assert(data[now*2]>=0);
////			assert(data[now*2+1]>=0);
//			now*=2;
//			if(data[now]>0) now++;
//		}
//		return now-nn;
//	}
//	inline void update()
//	{
//		while(true)
//		{
//			int pos=find0();
//			if(pos==-1) break;
//			add(pos,pos+1,inf);
//			sgtSum.add(pos,pos+1,1);
//			add(pos+1,nn,-1);
//		}
//	}
//};
//SegmentTreeMinAdd <int> sgt;
//
//int n,q;
//int a[300005];
//vector <pii> queries[300005];
//int tmp[300005];
//int ans[300005];
//
//int main()
//{
//	freopen("input.txt","r",stdin);
//	scanf("%d%d",&n,&q);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",a+i);
//		a[i]--;
//	}
//	sgtSum.init(n);
//	sgt.init(n,inf);
//	int x,y;
//	for(int i=0;i<q;i++)
//	{
//		scanf("%d%d",&x,&y);
//		queries[x].push_back(mp(y,i));
//	}
//	for(int i=n;i>=0;i--)
//	{
//		for(auto task:queries[i])
//		{
//			ans[task.second]=sgtSum.query(0,n-task.first);
//		}
//		if(i==0) break;
//		int pos=i-1;
//		if(a[pos]>pos) continue;
//		sgt.add(pos,pos+1,-inf+pos-a[pos]);
//		sgt.update();
////		for(int i=1;i<sgt.nn*2;i++)
////		{
////			sgt.pushdown(i);
////			cout<<sgt.data[i]<<' ';
////		}
////		cout<<endl;
//	}
//	for(int i=0;i<q;i++)
//	{
//		printf("%d\n",ans[i]);
//	}
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
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
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int gmod=2;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
#endif

#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,set <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,multiset <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,queue <T> q)
{
	vector <T> t;
	while(q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout<<t;
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream &cout,map <T1,T2> m)
{
	for(auto &x:m)
	{
		cout<<"Key: "<<x.first<<' '<<"Value: "<<x.second<<endl;
	}
	return cout;
}

template <typename T>
T operator * (vector <T> v1,vector <T> v2)
{
	assert(v1.size()==v2.size());
	int n=v1.size();
	T res=0;
	for(int i=0;i<n;i++)
	{
		res+=v1[i]*v2[i];
	}
	return res;
}

template <typename T1,typename T2>
pair<T1,T2> operator + (pair<T1,T2> x,pair<T1,T2> y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (pair<T1,T2> x)
{
	return make_pair(-x.first,-x.second);
}

template <typename T>
vector<vector<T> > operator ~ (vector<vector <T> > vec)
{
	vector <vector<T> > v;
	int n=vec.size(),m=vec[0].size();
	v.resize(m);
	for(int i=0;i<m;i++)
	{
		v[i].resize(n);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[i][j]=vec[j][i];
		}
	}
	return v;
}
#endif

void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(int i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
#endif
using namespace std;

template <typename T=int>
struct SegmentTreeIntervalSum
{
	const T E=0;
	int nn;
	T *data;
	T *tag;
	void init(int _n)
	{
		nn=1;
		while(nn<_n) nn<<=1;
		data=new T[nn*2+5];
		tag=new T[nn*2+5];
		for(int i=0;i<2*nn;i++)
		{
			tag[i]=E;
			data[i]=E;
		}
	}
	void pushdown(int x,int l,int r)
	{
		if(x>=nn) return;
		data[x*2]+=tag[x]*(r-l>>1);
		data[x*2+1]+=tag[x]*(r-l>>1);
		tag[x*2]+=tag[x];
		tag[x*2+1]+=tag[x];
		tag[x]=0;
	}
	void build(T a[],int n)
	{
		for(int i=0;i<n;i++)
		{
			data[i+nn]=a[i];
		}
		for(int i=nn-1;i>=1;i--)
		{
			data[i]=data[i*2]+data[i*2+1];
		}
	}
	void add(int x,int ql,int qr,int l,int r,T delta)
	{
		if(l>=qr || r<=ql) return;
		pushdown(x,l,r);
		if(l>=ql && r<=qr)
		{
			tag[x]+=delta;
			data[x]+=delta*(r-l);
			return;
		}
		add(x*2,ql,qr,l,l+r>>1,delta);
		add(x*2+1,ql,qr,l+r>>1,r,delta);
		data[x]=data[x*2]+data[x*2+1];
	}
	T query(int x,int ql,int qr,int l,int r)
	{
		if(l>=qr || r<=ql) return E;
		pushdown(x,l,r);
		if(l>=ql && r<=qr)
		{
			return data[x];
		}
		return query(x*2,ql,qr,l,l+r>>1)+query(x*2+1,ql,qr,l+r>>1,r);
	}
	inline void add(int l,int r,int delta)
	{
		add(1,l,r,0,nn,delta);
	}
	inline T query(int l,int r)
	{
		return query(1,l,r,0,nn);
	}
};
SegmentTreeIntervalSum <int> sgtSum;


//quality guarantee
template <typename T=int>
struct SegmentTreeMinAdd//[)
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
	T query()
	{
		return data[1];
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
	inline int find0()
	{
		if(data[1]>0) return -1;
		int now=1;
		while(now<nn)
		{
			pushdown(now);
//			cout<<now<<' '<<data[now]<<' '<<data[now*2]<<' '<<data[now*2+1]<<endl;
//			assert(data[now*2]>=0);
//			assert(data[now*2+1]>=0);
			now*=2;
			if(data[now]>0) now++;
		}
		return now-nn;
	}
	inline void update()
	{
		while(true)
		{
			int pos=find0();
			if(pos==-1) break;
			add(pos,pos+1,inf);
			sgtSum.add(pos,pos+1,1);
			add(pos+1,nn,-1);
		}
	}
};
SegmentTreeMinAdd <int> sgt;

int n,q;
int a[300005];
vector <pii> queries[300005];
int tmp[300005];
int ans[300005];

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	sgtSum.init(n);
	sgt.init(n,inf);
	int x,y;
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&x,&y);
		queries[x].push_back(mp(y,i));
	}
	for(int i=n;i>=0;i--)
	{
		for(auto task:queries[i])
		{
			ans[task.second]=sgtSum.query(0,n-task.first);
		}
		if(i==0) break;
		int pos=i-1;
		if(a[pos]>pos) continue;
		sgt.add(pos,pos+1,-inf+pos-a[pos]);
		sgt.update();
//		for(int i=1;i<sgt.nn*2;i++)
//		{
//			sgt.pushdown(i);
//			cout<<sgt.data[i]<<' ';
//		}
//		cout<<endl;
	}
	for(int i=0;i<q;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}