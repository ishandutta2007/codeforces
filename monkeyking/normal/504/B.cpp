//Original Code:
//#include <numeric>
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//#include <map>
//#include <queue>
//#include <set>
//#include <string>
//#include <string.h>
//#include <stack>
//#include <assert.h>
//#include <bitset>
//#include <time.h>
//#define Endl endl
//#define mp make_pair
//#define ll long long 
//#define ull unsigned long long
//#define pii pair<int,int>
//#define over(A) {cout<<A<<endl;exit(0);}
//#define all(A) A.begin(),A.end()
//#define quickcin ios_base::sync_with_stdio(false);
//const int mod=1e9+7;
//const int gmod=5;
//const int inf=1039074182;
//const double eps=1e-9;
//const ll llinf=1LL*inf*inf;
//template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
//template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
//inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
//template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
//template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
//template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
//template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
//using namespace std;
//int bit[200005];
//int n;
//int a[200005];
//int b[200005];
//int c[200005];
//int ra[200005];
//int rb[200005];
//int rc[200005];
//
//int query(int x)
//{
//	x++;
//	int res=0;
//	while(x)
//	{
//		res+=bit[x];
//		x&=(x-1);
//	}
//	return res;
//}
//
//void add(int x)
//{
//	x++;
//	while(x<=n)
//	{
//		bit[x]++;
//		x+=x&(-x);
//	}
//}
//
//inline void getRank(int a[],int rk[],int n)
//{
//	memset(bit,0,sizeof(bit));
//	for(int i=0;i<n;i++)
//	{
//		rk[n-1-i]=a[i]-query(a[i]);
//		add(a[i]);
//	}
//}
//
//inline int getHavingLess(int k)
//{
//	int l=0,r=n-1,mid,res=-1;
//	while(l<=r)
//	{
//		mid=l+r>>1;
//		if(mid-query(mid)>=k)
//		{
//			r=mid-1;
//			res=mid;
//		}
//		else
//		{
//			l=mid+1;
//		}
//	}
//	return res;
//}
//
//inline void genRank(int a[],int ra[],int n)
//{
//	memset(bit,0,sizeof(bit));
//	for(int i=0;i<n;i++)
//	{
//		a[i]=getHavingLess(ra[n-1-i]);
//		add(a[i]);
//	}
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//// 	freopen("b.in","r",stdin);
//// 	freopen("b.out","w",stdout);
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",a+i);
//	}
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",b+i);
//	}
//	getRank(a,ra,n);
//	getRank(b,rb,n);
//	for(int i=0;i<n;i++)
//	{
//		rc[i]+=ra[i]+rb[i];
//		while(rc[i]>i)
//		{
//			rc[i]-=(i+1);
//			rc[i+1]++;
//		}
//	}
//	genRank(c,rc,n);
//	for(int i=0;i<n;i++)
//	{
//		printf("%d ",c[i]);
//	}
//	return 0;
//}

//substituted with C++ Inliner
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
#include <time.h>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int gmod=5;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;
int bit[200005];
int n;
int a[200005];
int b[200005];
int c[200005];
int ra[200005];
int rb[200005];
int rc[200005];

int query(int x)
{
	x++;
	int res=0;
	while(x)
	{
		res+=bit[x];
		x&=(x-1);
	}
	return res;
}

void add(int x)
{
	x++;
	while(x<=n)
	{
		bit[x]++;
		x+=x&(-x);
	}
}

inline void getRank(int a[],int rk[],int n)
{
	memset(bit,0,sizeof(bit));
	for(int i=0;i<n;i++)
	{
		rk[n-1-i]=a[i]-query(a[i]);
		add(a[i]);
	}
}

inline int getHavingLess(int k)
{
	int l=0,r=n-1,mid,res=-1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(mid-query(mid)>=k)
		{
			r=mid-1;
			res=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return res;
}

inline void genRank(int a[],int ra[],int n)
{
	memset(bit,0,sizeof(bit));
	for(int i=0;i<n;i++)
	{
		a[i]=getHavingLess(ra[n-1-i]);
		add(a[i]);
	}
}

int main()
{
//	// freopen("input.txt","r",stdin);
// 	freopen("b.in","r",stdin);
// 	freopen("b.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",b+i);
	}
	getRank(a,ra,n);
	getRank(b,rb,n);
	for(int i=0;i<n;i++)
	{
		rc[i]+=ra[i]+rb[i];
		while(rc[i]>i)
		{
			rc[i]-=(i+1);
			rc[i+1]++;
		}
	}
	genRank(c,rc,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",c[i]);
	}
	return 0;
}