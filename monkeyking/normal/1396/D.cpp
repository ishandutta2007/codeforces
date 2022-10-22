//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/modint>
//using namespace std;
//using Int=ModInt <1000000007>;
//int q,k;
//Int L;
//vector <int> lshx;
//vector <int> lshy;
//pair<pii,int> points[2005];
//vector <pii> dat[2005];
//vector <pii> datay[2005];
//int n,m;
//
//Int a[2005];
//multiset <int> squs[2005];
//multiset <int> tmp;
//set <int> tmp2;
//Int res;
//
////quality guarantee
//template <typename T>
//struct SegmentTreeMaxChange//[)
//{
//	const T minValue=0;
//	int* unChanged;
//	T* dat;
//	T* tag;
//	T* s;
//	T* weight;
//	int nn;
//	inline int size()
//	{
//		return nn;
//	}
//	inline void init(int size)
//	{
//		nn=1;
//		while(nn<size)
//		{
//			nn<<=1;
//		}
//		dat=new T[nn*2+5];
//		tag=new T[nn*2+5];
//		s=new T[nn*2+5];
//		weight=new T[nn*2+5];
//		unChanged=new int[nn*2+5];
//		for(int i=0;i<=nn*2;i++)
//		{
//			dat[i]=minValue;
//			unChanged[i]=true;
//			weight[i]=0;
//			s[i]=0;
//		}
//	}
//	inline void build(T a[],T _weight[],int len)
//	{
//		clear();
//		for(int i=0;i<len;i++)
//		{
//			dat[i+nn]=a[i];
//			weight[i+nn]=_weight[i];
//			s[i+nn]=a[i]*weight[i+nn];
//		}
//		for(int i=nn-1;i>=1;i--)
//		{
//			dat[i]=max(dat[i*2].x,dat[i*2+1].x);
//			weight[i]=weight[i*2]+weight[i*2+1];
//			s[i]=s[i*2]+s[i*2+1];
//		}
//	}
//	inline void pushdown(int x)
//	{
//		if(x>=nn) return;
//		if(unChanged[x]) return;
//		dat[x*2]=tag[x];
//		dat[x*2+1]=tag[x];
//		tag[x*2]=tag[x];
//		tag[x*2+1]=tag[x];
//		s[x*2]=tag[x]*weight[x*2];
//		s[x*2+1]=tag[x]*weight[x*2+1];
//		unChanged[x]=true;
//		unChanged[x*2]=false;
//		unChanged[x*2+1]=false;
//	}
//	inline void pushup(int x)
//	{
//		if(x>=nn) return;
//		dat[x]=max(dat[x*2],dat[x*2+1]);
//		s[x]=s[x*2]+s[x*2+1];
//	}
//	inline void change(int ql,int qr,T value)
//	{
//		change(1,0,nn,ql,qr,value);
//	}
//	inline void change(int x,int l,int r,int ql,int qr,T value)
//	{
//		if(l>=qr || r<=ql) return;
//		pushdown(x);
//		if(l>=ql && r<=qr)
//		{
//			if(dat[x]>=value) return;
//			dat[x]=value;
//			s[x]=value*weight[x];
////			cout<<value<<' '<<weight[x]<<' '<<s[x]<<endl;
//			tag[x]=value;
//			unChanged[x]=false;
//			return;
//		}
//		change(x*2,l,l+r>>1,ql,qr,value);
//		change(x*2+1,l+r>>1,r,ql,qr,value);
//		pushup(x);
//	}
//	inline int findfirst(int x,int l,int r,int qpos,T value)
//	{
//		pushdown(x);
////		cout<<dat[x].x<<endl;
//		if(l+1==r) return (dat[x].x>=value.x?x-nn:nn);
//		if(qpos>=l+r>>1) return findfirst(x*2+1,l+r>>1,r,qpos,value);
//		else
//		{
//			if(dat[x*2]<value) return findfirst(x*2+1,l+r>>1,r,qpos,value);
//			int t=findfirst(x*2,l,l+r>>1,qpos,value);
//			if(t!=nn) return t;
//			return findfirst(x*2+1,l+r>>1,r,qpos,value);
//		}
//	}
//	
//	inline int findfirst(int pos,T value)
//	{
//		return findfirst(1,0,nn,pos,value);
////		while(dat[pos]<value)
////		{
////			if(pos&1) pos++;else pos/=2;
////		}
////		while(pos<nn)
////		{
////			pos<<=1;
////			if(dat[pos]<value) pos++;
////		}
////		return pos-nn;
//	}
//	
//	inline void update(int l,int r,T value)//chmax(a[l,r),value) 
//	{
//		int m=findfirst(l,value);
//		chmin(m,r);
//		if(l>=m) return;
//		change(l,m,value);
//	}
//	
//	inline void clear()
//	{
//		for(int i=0;i<=nn*2;i++)
//		{
//			dat[i]=minValue;
//			unChanged[i]=true;
//			s[i]=0;
//		}
//	}
//	inline T sum(int x,int l,int r,int ql,int qr)
//	{
//		if(ql>=r || qr<=l) return 0;
//		if(l>=ql && r<=qr) return s[x];
//		pushdown(x);
//		return sum(x*2,l,l+r>>1,ql,qr)+sum(x*2+1,l+r>>1,r,ql,qr);
//	}
//	inline T sum(int l,int r)
//	{
//		return sum(1,0,nn,l,r);
//	}
//	inline T sum()
//	{
//		return s[1];
//	}
//};
//SegmentTreeMaxChange <Int> sgt;
//
//Int weight[2005];
//Int weighty[2005];
//
//inline void solve(int sy)
//{
//	for(int i=0;i<k;i++)
//	{
//		squs[i].clear();
//	}
//	tmp.clear();
//	tmp2.clear();
//	sgt.clear();
//	for(int i=0,j=0;i<n;i++)
//	{
////		cout<<tmp2<<endl;
//		while(tmp2.size()!=k && j<n)
//		{
//			for(auto x:dat[j])
//			{
//				if(x.first<sy) continue;
//				tmp.insert(x.second);
//				tmp2.insert(x.second);
//				squs[x.second].insert(j);
//			}
//			j++;
//		}
//		if(tmp2.size()!=k) j=n+1;
//		a[i]=j-1;
////		cout<<tmp2<<endl;
//		for(auto x:dat[i])
//		{
//			if(x.first<sy) continue;
//			tmp.erase(tmp.find(x.second));
//			if(!tmp.count(x.second)) tmp2.erase(x.second);
//		}
//	}
////	for(int i=0;i<n;i++)
////	{
////		cout<<a[i]<<' ';
////	}
////	cout<<endl;
//	for(int i=0;i<n;i++)
//	{
//		a[i]=lshx[a[i].x];
//		weight[i]=lshx[i]-(i?lshx[i-1]:-1);
//	}
////	for(int i=0;i<n;i++)
////	{
////		cout<<a[i]<<' ';
////	}
////	cout<<endl;
////	for(int i=0;i<n;i++)
////	{
////		cout<<weight[i]<<' ';
////	}
////	cout<<endl;
////	cout<<"*******************************"<<endl;
//	sgt.build(a,weight,n);
////	cout<<sgt.sum()<<endl;
////	cout<<(((Int)lshx[n-1]+(Int)1)*L-sgt.sum())*weighty[m]*weighty[sy]<<endl;
//	res+=(((Int)lshx[n-1]+(Int)1)*L-sgt.sum())*weighty[m]*weighty[sy];
////	cout<<res<<endl;
////	cout<<squs[0]<<' '<<squs[1]<<endl;
//	for(int ey=m-1;ey>=sy;ey--)
//	{
//		for(auto x:datay[ey])
//		{
//			int c=x.second;
//			int pos=x.first;
//			squs[c].erase(squs[c].find(pos));
//			multiset <int> :: iterator it=squs[c].lower_bound(pos);
//			Int nvalue=L;
//			if(it!=squs[c].end()) nvalue=lshx[*it];
//			int r=pos+1;
//			int l=0;
//			if(it!=squs[c].begin())
//			{
//				it--;
//				l=(*it)+1;
//			}
//			sgt.update(l,r,nvalue);
////			sgt.pushdown(1);
////			sgt.pushdown(2);
////			sgt.pushdown(3);
////			cout<<sgt.weight[1]<<endl;
////			cout<<sgt.dat[4]<<' '<<sgt.dat[5]<<' '<<sgt.dat[6]<<' '<<sgt.dat[7]<<endl;
////			cout<<sgt.weight[4]<<' '<
////			cout<<l<<' '<<r<<' '<<nvalue<<' '<<sgt.sum()<<endl;
//		}
////		cout<<((Int)lshx[n-1]+(Int)1)<<' '<<sgt.sum()<<endl;
////		cout<<(((Int)lshx[n-1]+(Int)1)*L-sgt.sum())<<endl;
////		cout<<sgt.sum()<<endl;
////		cout<<weighty[ey]*weighty[sy]<<endl;
////		cout<<(((Int)lshx[n-1]+(Int)1)*L-sgt.sum())*weighty[ey]*weighty[sy]<<endl;
////		res+=(((Int)lshx[n-1]+(Int)1)*L-sgt.sum())*weighty[ey]*weighty[sy];
//		res+=(((Int)lshx[n-1]+(Int)1)*L-sgt.sum())*weighty[ey]*weighty[sy];
//	}
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>q>>k>>L;
//	int x,y,z;
//	for(int i=0;i<q;i++)
//	{
//		cin>>x>>y>>z;
//		z--;
//		lshx.push_back(x);
//		lshy.push_back(y);
//		points[i]=mp(mp(x,y),z);
//	}
//	sort(all(lshx));
//	lshx.erase(unique(all(lshx)),lshx.end());
//	n=lshx.size();
//	lshx.push_back(L.x);
//	sort(all(lshy));
//	lshy.erase(unique(all(lshy)),lshy.end());
//	m=lshy.size();
//	lshy.push_back(L.x);
//	sgt.init(n);
//	for(int i=0;i<q;i++)
//	{
//		points[i].first.first=lower_bound(all(lshx),points[i].first.first)-lshx.begin();
//		points[i].first.second=lower_bound(all(lshy),points[i].first.second)-lshy.begin();
//		dat[points[i].first.first].push_back(mp(points[i].first.second,points[i].second));
//		datay[points[i].first.second].push_back(mp(points[i].first.first,points[i].second));
//	}
//	for(int i=0;i<=m;i++)
//	{
//		weighty[i]=lshy[i]-(i?lshy[i-1]:-1);
//	}
////	cout<<lshy[m]<<' '<<lshy[m-1]<<endl;
////	for(int i=0;i<=m;i++)
////	{
////		cout<<weighty[i]<<' ';
////	}
////	cout<<endl;
////	solve(0);
////	cout<<res<<endl;
////	return 0;
//	for(int j=m-1;j>=0;j--)
//	{
//		solve(j);
//	}
//	cout<<res<<endl;
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
template <int mod>
struct ModInt
{
	int x;
	ModInt(){x=0;}
	ModInt(int _x){x=_x;if(x<0) x+=mod;}
	ModInt <mod>& operator ++()// prefix
	{
		++x;
		if(x==mod) x=0;
		return *this;
	}
};

template <int mod>
bool operator < (ModInt <mod> a,ModInt <mod> b)
{
	return a.x<b.x;
}

template <int mod>
bool operator > (ModInt <mod> a,ModInt <mod> b)
{
	return b.x<a.x;
}

template <int mod>
bool operator == (ModInt <mod> a,ModInt <mod> b)
{
	return a.x==b.x;
}

template <int mod>
bool operator <= (ModInt <mod> a,ModInt <mod> b)
{
	return a.x<=b.x;
}

template <int mod>
bool operator >= (ModInt <mod> a,ModInt <mod> b)
{
	return b.x<=a.x;
}

template <int mod>
ModInt <mod> operator + (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x+b.x;
	if(tmp>=mod) tmp-=mod;
	return tmp;
}

template <int mod>
ModInt <mod> operator - (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x-b.x;
	if(tmp<0) tmp+=mod;
	return tmp;
}

template <int mod>
ModInt <mod> operator * (ModInt <mod> a,ModInt <mod> b)
{
	return 1LL*a.x*b.x%mod;
}

template <int mod>
void operator += (ModInt <mod> &a,ModInt <mod> b)
{
	a.x+=b.x;
	if(a.x>=mod) a.x-=mod;
}

template <int mod>
istream & operator >> (istream &cin,ModInt <mod> &x)
{
	cin>>x.x;
	return cin;
}

template <int mod>
ostream & operator << (ostream &cout,ModInt <mod> x)
{
	cout<<x.x;
	return cout;
}
using namespace std;
using Int=ModInt <1000000007>;
int q,k;
Int L;
vector <int> lshx;
vector <int> lshy;
pair<pii,int> points[2005];
vector <pii> dat[2005];
vector <pii> datay[2005];
int n,m;

Int a[2005];
multiset <int> squs[2005];
multiset <int> tmp;
set <int> tmp2;
Int res;

//quality guarantee
template <typename T>
struct SegmentTreeMaxChange//[)
{
	const T minValue=0;
	int* unChanged;
	T* dat;
	T* tag;
	T* s;
	T* weight;
	int nn;
	inline int size()
	{
		return nn;
	}
	inline void init(int size)
	{
		nn=1;
		while(nn<size)
		{
			nn<<=1;
		}
		dat=new T[nn*2+5];
		tag=new T[nn*2+5];
		s=new T[nn*2+5];
		weight=new T[nn*2+5];
		unChanged=new int[nn*2+5];
		for(int i=0;i<=nn*2;i++)
		{
			dat[i]=minValue;
			unChanged[i]=true;
			weight[i]=0;
			s[i]=0;
		}
	}
	inline void build(T a[],T _weight[],int len)
	{
		clear();
		for(int i=0;i<len;i++)
		{
			dat[i+nn]=a[i];
			weight[i+nn]=_weight[i];
			s[i+nn]=a[i]*weight[i+nn];
		}
		for(int i=nn-1;i>=1;i--)
		{
			dat[i]=max(dat[i*2].x,dat[i*2+1].x);
			weight[i]=weight[i*2]+weight[i*2+1];
			s[i]=s[i*2]+s[i*2+1];
		}
	}
	inline void pushdown(int x)
	{
		if(x>=nn) return;
		if(unChanged[x]) return;
		dat[x*2]=tag[x];
		dat[x*2+1]=tag[x];
		tag[x*2]=tag[x];
		tag[x*2+1]=tag[x];
		s[x*2]=tag[x]*weight[x*2];
		s[x*2+1]=tag[x]*weight[x*2+1];
		unChanged[x]=true;
		unChanged[x*2]=false;
		unChanged[x*2+1]=false;
	}
	inline void pushup(int x)
	{
		if(x>=nn) return;
		dat[x]=max(dat[x*2],dat[x*2+1]);
		s[x]=s[x*2]+s[x*2+1];
	}
	inline void change(int ql,int qr,T value)
	{
		change(1,0,nn,ql,qr,value);
	}
	inline void change(int x,int l,int r,int ql,int qr,T value)
	{
		if(l>=qr || r<=ql) return;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			if(dat[x]>=value) return;
			dat[x]=value;
			s[x]=value*weight[x];
//			cout<<value<<' '<<weight[x]<<' '<<s[x]<<endl;
			tag[x]=value;
			unChanged[x]=false;
			return;
		}
		change(x*2,l,l+r>>1,ql,qr,value);
		change(x*2+1,l+r>>1,r,ql,qr,value);
		pushup(x);
	}
	inline int findfirst(int x,int l,int r,int qpos,T value)
	{
		pushdown(x);
//		cout<<dat[x].x<<endl;
		if(l+1==r) return (dat[x].x>=value.x?x-nn:nn);
		if(qpos>=l+r>>1) return findfirst(x*2+1,l+r>>1,r,qpos,value);
		else
		{
			if(dat[x*2]<value) return findfirst(x*2+1,l+r>>1,r,qpos,value);
			int t=findfirst(x*2,l,l+r>>1,qpos,value);
			if(t!=nn) return t;
			return findfirst(x*2+1,l+r>>1,r,qpos,value);
		}
	}
	
	inline int findfirst(int pos,T value)
	{
		return findfirst(1,0,nn,pos,value);
//		while(dat[pos]<value)
//		{
//			if(pos&1) pos++;else pos/=2;
//		}
//		while(pos<nn)
//		{
//			pos<<=1;
//			if(dat[pos]<value) pos++;
//		}
//		return pos-nn;
	}
	
	inline void update(int l,int r,T value)//chmax(a[l,r),value) 
	{
		int m=findfirst(l,value);
		chmin(m,r);
		if(l>=m) return;
		change(l,m,value);
	}
	
	inline void clear()
	{
		for(int i=0;i<=nn*2;i++)
		{
			dat[i]=minValue;
			unChanged[i]=true;
			s[i]=0;
		}
	}
	inline T sum(int x,int l,int r,int ql,int qr)
	{
		if(ql>=r || qr<=l) return 0;
		if(l>=ql && r<=qr) return s[x];
		pushdown(x);
		return sum(x*2,l,l+r>>1,ql,qr)+sum(x*2+1,l+r>>1,r,ql,qr);
	}
	inline T sum(int l,int r)
	{
		return sum(1,0,nn,l,r);
	}
	inline T sum()
	{
		return s[1];
	}
};
SegmentTreeMaxChange <Int> sgt;

Int weight[2005];
Int weighty[2005];

inline void solve(int sy)
{
	for(int i=0;i<k;i++)
	{
		squs[i].clear();
	}
	tmp.clear();
	tmp2.clear();
	sgt.clear();
	for(int i=0,j=0;i<n;i++)
	{
//		cout<<tmp2<<endl;
		while(tmp2.size()!=k && j<n)
		{
			for(auto x:dat[j])
			{
				if(x.first<sy) continue;
				tmp.insert(x.second);
				tmp2.insert(x.second);
				squs[x.second].insert(j);
			}
			j++;
		}
		if(tmp2.size()!=k) j=n+1;
		a[i]=j-1;
//		cout<<tmp2<<endl;
		for(auto x:dat[i])
		{
			if(x.first<sy) continue;
			tmp.erase(tmp.find(x.second));
			if(!tmp.count(x.second)) tmp2.erase(x.second);
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		a[i]=lshx[a[i].x];
		weight[i]=lshx[i]-(i?lshx[i-1]:-1);
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
//	for(int i=0;i<n;i++)
//	{
//		cout<<weight[i]<<' ';
//	}
//	cout<<endl;
//	cout<<"*******************************"<<endl;
	sgt.build(a,weight,n);
//	cout<<sgt.sum()<<endl;
//	cout<<(((Int)lshx[n-1]+(Int)1)*L-sgt.sum())*weighty[m]*weighty[sy]<<endl;
	res+=(((Int)lshx[n-1]+(Int)1)*L-sgt.sum())*weighty[m]*weighty[sy];
//	cout<<res<<endl;
//	cout<<squs[0]<<' '<<squs[1]<<endl;
	for(int ey=m-1;ey>=sy;ey--)
	{
		for(auto x:datay[ey])
		{
			int c=x.second;
			int pos=x.first;
			squs[c].erase(squs[c].find(pos));
			multiset <int> :: iterator it=squs[c].lower_bound(pos);
			Int nvalue=L;
			if(it!=squs[c].end()) nvalue=lshx[*it];
			int r=pos+1;
			int l=0;
			if(it!=squs[c].begin())
			{
				it--;
				l=(*it)+1;
			}
			sgt.update(l,r,nvalue);
//			sgt.pushdown(1);
//			sgt.pushdown(2);
//			sgt.pushdown(3);
//			cout<<sgt.weight[1]<<endl;
//			cout<<sgt.dat[4]<<' '<<sgt.dat[5]<<' '<<sgt.dat[6]<<' '<<sgt.dat[7]<<endl;
//			cout<<sgt.weight[4]<<' '<
//			cout<<l<<' '<<r<<' '<<nvalue<<' '<<sgt.sum()<<endl;
		}
//		cout<<((Int)lshx[n-1]+(Int)1)<<' '<<sgt.sum()<<endl;
//		cout<<(((Int)lshx[n-1]+(Int)1)*L-sgt.sum())<<endl;
//		cout<<sgt.sum()<<endl;
//		cout<<weighty[ey]*weighty[sy]<<endl;
//		cout<<(((Int)lshx[n-1]+(Int)1)*L-sgt.sum())*weighty[ey]*weighty[sy]<<endl;
//		res+=(((Int)lshx[n-1]+(Int)1)*L-sgt.sum())*weighty[ey]*weighty[sy];
		res+=(((Int)lshx[n-1]+(Int)1)*L-sgt.sum())*weighty[ey]*weighty[sy];
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>q>>k>>L;
	int x,y,z;
	for(int i=0;i<q;i++)
	{
		cin>>x>>y>>z;
		z--;
		lshx.push_back(x);
		lshy.push_back(y);
		points[i]=mp(mp(x,y),z);
	}
	sort(all(lshx));
	lshx.erase(unique(all(lshx)),lshx.end());
	n=lshx.size();
	lshx.push_back(L.x);
	sort(all(lshy));
	lshy.erase(unique(all(lshy)),lshy.end());
	m=lshy.size();
	lshy.push_back(L.x);
	sgt.init(n);
	for(int i=0;i<q;i++)
	{
		points[i].first.first=lower_bound(all(lshx),points[i].first.first)-lshx.begin();
		points[i].first.second=lower_bound(all(lshy),points[i].first.second)-lshy.begin();
		dat[points[i].first.first].push_back(mp(points[i].first.second,points[i].second));
		datay[points[i].first.second].push_back(mp(points[i].first.first,points[i].second));
	}
	for(int i=0;i<=m;i++)
	{
		weighty[i]=lshy[i]-(i?lshy[i-1]:-1);
	}
//	cout<<lshy[m]<<' '<<lshy[m-1]<<endl;
//	for(int i=0;i<=m;i++)
//	{
//		cout<<weighty[i]<<' ';
//	}
//	cout<<endl;
//	solve(0);
//	cout<<res<<endl;
//	return 0;
	for(int j=m-1;j>=0;j--)
	{
		solve(j);
	}
	cout<<res<<endl;
	return 0;
}