//Original Code:
//#pragma GCC optimize(2)
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//const int basic=500000;
//int n;
//int a[300005],b[300005];
//char buf[500005];
//vector <int> sum[basic*2+5];
//int m1,m2,m3,m4;
//int b1,b2;
//int besta,bestb;
//int best;
//int res;
//int zx,nx,tx;
//
//inline void calc(int k)
//{
//	res=0;
//	chmax(res,b1);
//	chmax(res,b2);
//	zx=max(m2,m3);
//	nx=max(m1,m4);
//	tx=(nx-zx)/2;
//	chmax(tx,0);
//	chmax(res,-tx+nx);
//	if(res<best)
//	{
//		best=res;
//		besta=tx;
//		if(besta==0 && k==0) besta++;
//		bestb=besta+k;
//	}
//}
//
//inline void read(int &a,int &b)
//{
//	a=0;
//	b=0;
//	char c=0;
//	while(c!='N' && c!='B') c=getchar();
//	while(c=='N' || c=='B')
//	{
//		if(c=='B') b++;else a++;
//		c=getchar();
//	}
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>n;
//	m1=-inf,m2=-inf,m3=-inf,m4=-inf;
//	b1=-inf,b2=-inf;
//	int k=basic;
//	int maxk=-basic,mink=basic;
//	for(int i=0;i<n;i++)
//	{
//		read(a[i],b[i]);
//		chmax(maxk,b[i]-a[i]);
//		chmin(mink,b[i]-a[i]);
//	}
//	maxk++;
//	mink--;
//	k=maxk;
//	for(int i=0;i<n;i++)
//	{
//		sum[b[i]-a[i]+basic].emplace_back(i);
//		chmax(b2,a[i]+k-b[i]);
//		chmax(m3,k-b[i]);
//		chmax(m4,a[i]);
//	}
//	best=inf;
//	calc(basic);
////	cout<<maxk<<' '<<mink<<endl;
////	exit(0);
//	for(k=maxk-1;k>=mink;k--)
//	{
//		m1++;
//		b1++;
//		m3--;
//		b2--;
//		for(auto id:sum[k+basic])
//		{
//			int x0=a[id];
//			int y0=b[id];
//			chmax(m1,y0-k);
//			chmax(m2,-x0);
//			chmax(b1,y0-(x0+k));
//		}
//		calc(k);
//	}
//	cout<<best<<endl;
//	for(int i=0;i<bestb;i++)
//	{
//		putchar('B');
//	}
//	for(int i=0;i<besta;i++)
//	{
//		putchar('N');
//	}
//	return 0;
//}

//substituted with C++ Inliner
#pragma GCC optimize(2)
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
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
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
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
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
const int basic=500000;
int n;
int a[300005],b[300005];
char buf[500005];
vector <int> sum[basic*2+5];
int m1,m2,m3,m4;
int b1,b2;
int besta,bestb;
int best;
int res;
int zx,nx,tx;

inline void calc(int k)
{
	res=0;
	chmax(res,b1);
	chmax(res,b2);
	zx=max(m2,m3);
	nx=max(m1,m4);
	tx=(nx-zx)/2;
	chmax(tx,0);
	chmax(res,-tx+nx);
	if(res<best)
	{
		best=res;
		besta=tx;
		if(besta==0 && k==0) besta++;
		bestb=besta+k;
	}
}

inline void read(int &a,int &b)
{
	a=0;
	b=0;
	char c=0;
	while(c!='N' && c!='B') c=getchar();
	while(c=='N' || c=='B')
	{
		if(c=='B') b++;else a++;
		c=getchar();
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	m1=-inf,m2=-inf,m3=-inf,m4=-inf;
	b1=-inf,b2=-inf;
	int k=basic;
	int maxk=-basic,mink=basic;
	for(int i=0;i<n;i++)
	{
		read(a[i],b[i]);
		chmax(maxk,b[i]-a[i]);
		chmin(mink,b[i]-a[i]);
	}
	maxk++;
	mink--;
	k=maxk;
	for(int i=0;i<n;i++)
	{
		sum[b[i]-a[i]+basic].emplace_back(i);
		chmax(b2,a[i]+k-b[i]);
		chmax(m3,k-b[i]);
		chmax(m4,a[i]);
	}
	best=inf;
	calc(basic);
//	cout<<maxk<<' '<<mink<<endl;
//	exit(0);
	for(k=maxk-1;k>=mink;k--)
	{
		m1++;
		b1++;
		m3--;
		b2--;
		for(auto id:sum[k+basic])
		{
			int x0=a[id];
			int y0=b[id];
			chmax(m1,y0-k);
			chmax(m2,-x0);
			chmax(b1,y0-(x0+k));
		}
		calc(k);
	}
	cout<<best<<endl;
	for(int i=0;i<bestb;i++)
	{
		putchar('B');
	}
	for(int i=0;i<besta;i++)
	{
		putchar('N');
	}
	return 0;
}