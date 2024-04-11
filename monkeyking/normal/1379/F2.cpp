//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n,m,q;
//set <int> seta[200005];
//set <int> setb[200005];
//int nn;
//int xiaoyu[200005*4];
//
//template <typename T>
//struct SegmentTreeMinChange//[)
//{
//	const T maxValue=1e9;
//	T* data;
//	int nn;
//	int size()
//	{
//		return nn;
//	}
//	T operator [] (int pos)
//	{
//		return data[pos];
//	}
//	void init(int size)
//	{
//		nn=1;
//		while(nn<size)
//		{
//			nn<<=1;
//		}
//		data=new T[nn*2+5];
//		for(int i=0;i<=nn*2;i++)
//		{
//			data[i]=maxValue;
//		}
//	}
//	void update(int pos)
//	{
//		data[pos]=min(data[pos*2],data[pos*2+1]);
//	}
//};
//
//template <typename T>
//struct SegmentTreeMaxChange//[)
//{
//	const T minValue=-1e9;
//	T* data;
//	int nn;
//	int size()
//	{
//		return nn;
//	}
//	T operator [] (int pos)
//	{
//		return data[pos];
//	}
//	void init(int size)
//	{
//		nn=1;
//		while(nn<size)
//		{
//			nn<<=1;
//		}
//		data=new T[nn*2+5];
//		for(int i=0;i<=nn*2;i++)
//		{
//			data[i]=minValue;
//		}
//	}
//	void update(int pos)
//	{
//		data[pos]=max(data[pos*2],data[pos*2+1]);
//	}
//};
//
//SegmentTreeMinChange <int> sgta;
//SegmentTreeMaxChange <int> sgtb;
//
//template <typename T>
//void change(int pos,int x,T &sgt)
//{
//	pos+=nn;
//	sgt.data[pos]=x;
//	xiaoyu[pos]=sgta[pos]<=sgtb[pos];
//	while(pos)
//	{
//		pos>>=1;
//		sgt.update(pos);
//		xiaoyu[pos]=xiaoyu[pos*2] | xiaoyu[pos*2+1] | (sgta[pos*2]<=sgtb[pos*2+1]);
//	}
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>n>>m>>q;
//	int x,y;
//	sgta.init(n);
//	sgtb.init(n);
//	memset(xiaoyu,0,sizeof(xiaoyu));
//	nn=1;
//	while(nn<n) nn<<=1;
//	for(int i=0;i<q;i++)
//	{
//		scanf("%d%d",&x,&y);
//		x--;
//		y--;
//		if(x&1)
//		{
//			x/=2;
//			y/=2;
//			if(setb[x].count(y)) setb[x].erase(y);else setb[x].insert(y);
//			y=(setb[x].empty()?-inf:*(--setb[x].end()));
////			cout<<'B'<<' '<<x<<' '<<y<<endl;
//			change(x,y,sgtb);
//		}
//		else
//		{
//			x/=2;
//			y/=2;
//			if(seta[x].count(y)) seta[x].erase(y);else seta[x].insert(y);
//			y=(seta[x].empty()?inf:*(seta[x].begin()));
////			cout<<"A"<<' '<<x<<' '<<y<<endl;
//			change(x,y,sgta);
//		}
//		puts(xiaoyu[1]?"NO":"YES");
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
const int mod=200003;
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
int n,m,q;
set <int> seta[200005];
set <int> setb[200005];
int nn;
int xiaoyu[200005*4];

template <typename T>
struct SegmentTreeMinChange//[)
{
	const T maxValue=1e9;
	T* data;
	int nn;
	int size()
	{
		return nn;
	}
	T operator [] (int pos)
	{
		return data[pos];
	}
	void init(int size)
	{
		nn=1;
		while(nn<size)
		{
			nn<<=1;
		}
		data=new T[nn*2+5];
		for(int i=0;i<=nn*2;i++)
		{
			data[i]=maxValue;
		}
	}
	void update(int pos)
	{
		data[pos]=min(data[pos*2],data[pos*2+1]);
	}
};

template <typename T>
struct SegmentTreeMaxChange//[)
{
	const T minValue=-1e9;
	T* data;
	int nn;
	int size()
	{
		return nn;
	}
	T operator [] (int pos)
	{
		return data[pos];
	}
	void init(int size)
	{
		nn=1;
		while(nn<size)
		{
			nn<<=1;
		}
		data=new T[nn*2+5];
		for(int i=0;i<=nn*2;i++)
		{
			data[i]=minValue;
		}
	}
	void update(int pos)
	{
		data[pos]=max(data[pos*2],data[pos*2+1]);
	}
};

SegmentTreeMinChange <int> sgta;
SegmentTreeMaxChange <int> sgtb;

template <typename T>
void change(int pos,int x,T &sgt)
{
	pos+=nn;
	sgt.data[pos]=x;
	xiaoyu[pos]=sgta[pos]<=sgtb[pos];
	while(pos)
	{
		pos>>=1;
		sgt.update(pos);
		xiaoyu[pos]=xiaoyu[pos*2] | xiaoyu[pos*2+1] | (sgta[pos*2]<=sgtb[pos*2+1]);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>q;
	int x,y;
	sgta.init(n);
	sgtb.init(n);
	memset(xiaoyu,0,sizeof(xiaoyu));
	nn=1;
	while(nn<n) nn<<=1;
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		if(x&1)
		{
			x/=2;
			y/=2;
			if(setb[x].count(y)) setb[x].erase(y);else setb[x].insert(y);
			y=(setb[x].empty()?-inf:*(--setb[x].end()));
//			cout<<'B'<<' '<<x<<' '<<y<<endl;
			change(x,y,sgtb);
		}
		else
		{
			x/=2;
			y/=2;
			if(seta[x].count(y)) seta[x].erase(y);else seta[x].insert(y);
			y=(seta[x].empty()?inf:*(seta[x].begin()));
//			cout<<"A"<<' '<<x<<' '<<y<<endl;
			change(x,y,sgta);
		}
		puts(xiaoyu[1]?"NO":"YES");
	}
	return 0;
}