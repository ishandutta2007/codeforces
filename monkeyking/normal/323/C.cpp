//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n;
//int pa[1000005];
//int pb[1000005];
//
//inline int getnum()
//{
//	static int res;
//	static char c;
//	res=0;
//	c=0;
//	while(!isdigit(c)) c=getchar();
//	while(isdigit(c))
//	{
//		res=(res<<3)+(res<<1)+c-'0';
//		c=getchar();
//	}
//	return res;
//}
//
//int a[1000005];
//vector <int> data[4000005];
//int nn;
//
//inline int calc(vector <int> &vec,int l,int r)
//{
//	return lower_bound(all(vec),r)-lower_bound(all(vec),l);
//}
//
//inline int query(int x,int l,int r,int ql,int qr,int vl,int vr)
//{
//	if(r<=ql || l>=qr) return 0;
//	if(l>=ql && r<=qr)
//	{
//		return calc(data[x],vl,vr);
//	}
//	return query(x*2,l,l+r>>1,ql,qr,vl,vr)+query(x*2+1,l+r>>1,r,ql,qr,vl,vr);
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		a[i]=getnum()-1;
//		pa[a[i]]=i;
//	}
//	for(int i=0;i<n;i++)
//	{
//		a[i]=getnum()-1;
//		pb[a[i]]=i;
//	}
////	for(int i=0;i<n;i++)
////	{
////		cout<<pa[i]<<' '<<pb[i]<<endl;
////	}
//	vector <pii> vSort;
//	for(int i=0;i<n;i++)
//	{
//		vSort.push_back(mp(pa[i],i));
//	}
//	sort(all(vSort));
//	for(int i=0;i<n;i++)
//	{
//		a[i]=pb[vSort[i].second];
//	}
//	nn=1;
//	while(nn<n) nn<<=1;
//	for(int i=nn;i<nn+n;i++)
//	{
//		data[i].push_back(a[i-nn]);
//	}
//	for(int i=nn-1;i>=1;i--)
//	{
//		data[i].resize(data[i*2].size()+data[i*2+1].size());
//		merge(all(data[i*2]),all(data[i*2+1]),data[i].begin());
//	}
////	cout<<data[2]<<endl;
//	int q;
//	cin>>q;
//	int a,b,c,d;
//	int res=0;
//	for(int i=0;i<q;i++)
//	{
//		a=getnum();
//		b=getnum();
//		c=getnum();
//		d=getnum();
//		a--;
//		b--;
//		c--;
//		d--;
//		a=(a+res)%n;
//		b=(b+res)%n;
//		c=(c+res)%n;
//		d=(d+res)%n;
//		if(a>b) swap(a,b);
//		if(c>d) swap(c,d);
//		b++;
//		d++;
//		res=query(1,0,nn,a,b,c,d);
//		printf("%d\n",res);
//		res++;
//	}
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <numeric>
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
	for(int i=0;i<(int)vec.size();i++)
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

template <typename T,typename T2>
ostream & operator << (ostream & cout,set <T,T2> s)
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
void operator += (pair<T1,T2> &x,pair<T1,T2> y)
{
	x.first+=y.first;
	x.second+=y.second;
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
	for(int i=0;i<(int)vec.size();i++)
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
int n;
int pa[1000005];
int pb[1000005];

inline int getnum()
{
	static int res;
	static char c;
	res=0;
	c=0;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c))
	{
		res=(res<<3)+(res<<1)+c-'0';
		c=getchar();
	}
	return res;
}

int a[1000005];
vector <int> data[4000005];
int nn;

inline int calc(vector <int> &vec,int l,int r)
{
	return lower_bound(all(vec),r)-lower_bound(all(vec),l);
}

inline int query(int x,int l,int r,int ql,int qr,int vl,int vr)
{
	if(r<=ql || l>=qr) return 0;
	if(l>=ql && r<=qr)
	{
		return calc(data[x],vl,vr);
	}
	return query(x*2,l,l+r>>1,ql,qr,vl,vr)+query(x*2+1,l+r>>1,r,ql,qr,vl,vr);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		a[i]=getnum()-1;
		pa[a[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		a[i]=getnum()-1;
		pb[a[i]]=i;
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<pa[i]<<' '<<pb[i]<<endl;
//	}
	vector <pii> vSort;
	for(int i=0;i<n;i++)
	{
		vSort.push_back(mp(pa[i],i));
	}
	sort(all(vSort));
	for(int i=0;i<n;i++)
	{
		a[i]=pb[vSort[i].second];
	}
	nn=1;
	while(nn<n) nn<<=1;
	for(int i=nn;i<nn+n;i++)
	{
		data[i].push_back(a[i-nn]);
	}
	for(int i=nn-1;i>=1;i--)
	{
		data[i].resize(data[i*2].size()+data[i*2+1].size());
		merge(all(data[i*2]),all(data[i*2+1]),data[i].begin());
	}
//	cout<<data[2]<<endl;
	int q;
	cin>>q;
	int a,b,c,d;
	int res=0;
	for(int i=0;i<q;i++)
	{
		a=getnum();
		b=getnum();
		c=getnum();
		d=getnum();
		a--;
		b--;
		c--;
		d--;
		a=(a+res)%n;
		b=(b+res)%n;
		c=(c+res)%n;
		d=(d+res)%n;
		if(a>b) swap(a,b);
		if(c>d) swap(c,d);
		b++;
		d++;
		res=query(1,0,nn,a,b,c,d);
		printf("%d\n",res);
		res++;
	}
	return 0;
}