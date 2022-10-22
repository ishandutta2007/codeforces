//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n;
//int r1,r2,r3;
//int d;
//int s[1000005];
//ll a[1000005];
//ll b[1000005];
//ll suma[1000005];
//ll sumb[1000005];
//ll dp[2][1000005];
//
//void calc(ll a[],ll suf[],int n)
//{
//	suf[n-1]=a[n-1];
//	for(int i=n-2;i>=0;i--)
//	{
//		suf[i]=suf[i+1]+a[i];
//	}
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>n>>r1>>r2>>r3>>d;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",s+i);
//	}
//	for(int i=0;i<n;i++)
//	{
//		a[i]=1LL*r1*s[i]+r3;
//		b[i]=min((ll)r2,1LL*r1*(s[i]+1))+r1;
//		chmin(a[i],b[i]+2*d);
//		chmin(b[i],a[i]);
//	}
//	ll tmp=a[n-1];
//	swap(b[n-1],tmp);
//	calc(b,sumb,n);
//	swap(b[n-1],tmp);
//	memset(dp,0x3f,sizeof(dp));
//	dp[0][0]=0;
//	
//	ll res=llinf;
//	for(int i=0;i<n;i++)
//	{
//		chmin(dp[0][i+1],dp[0][i]+a[i]);
//		chmin(dp[1][i+1],dp[0][i]+b[i]+2*d);
//		chmin(dp[0][i+1],dp[1][i]+b[i]);
//		chmin(dp[1][i+1],dp[1][i]+b[i]+2*d);
////		cout<<dp[0][i]+(n-i-1)*d+sumb[i]<<' '<<dp[1][i]+(n-i-1)*d+sumb[i]<<endl;
//		chmin(res,dp[0][i]+1LL*(n-i-1)*d+sumb[i]);
//		chmin(res,dp[1][i]+1LL*(n-i-1)*d+sumb[i]);
//	}
//	chmin(res,dp[0][n]);
//	chmin(res,dp[1][n]);
//	cout<<res+1LL*d*(n-1)<<endl;
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
int n;
int r1,r2,r3;
int d;
int s[1000005];
ll a[1000005];
ll b[1000005];
ll suma[1000005];
ll sumb[1000005];
ll dp[2][1000005];

void calc(ll a[],ll suf[],int n)
{
	suf[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		suf[i]=suf[i+1]+a[i];
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>r1>>r2>>r3>>d;
	for(int i=0;i<n;i++)
	{
		scanf("%d",s+i);
	}
	for(int i=0;i<n;i++)
	{
		a[i]=1LL*r1*s[i]+r3;
		b[i]=min((ll)r2,1LL*r1*(s[i]+1))+r1;
		chmin(a[i],b[i]+2*d);
		chmin(b[i],a[i]);
	}
	ll tmp=a[n-1];
	swap(b[n-1],tmp);
	calc(b,sumb,n);
	swap(b[n-1],tmp);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	
	ll res=llinf;
	for(int i=0;i<n;i++)
	{
		chmin(dp[0][i+1],dp[0][i]+a[i]);
		chmin(dp[1][i+1],dp[0][i]+b[i]+2*d);
		chmin(dp[0][i+1],dp[1][i]+b[i]);
		chmin(dp[1][i+1],dp[1][i]+b[i]+2*d);
//		cout<<dp[0][i]+(n-i-1)*d+sumb[i]<<' '<<dp[1][i]+(n-i-1)*d+sumb[i]<<endl;
		chmin(res,dp[0][i]+1LL*(n-i-1)*d+sumb[i]);
		chmin(res,dp[1][i]+1LL*(n-i-1)*d+sumb[i]);
	}
	chmin(res,dp[0][n]);
	chmin(res,dp[1][n]);
	cout<<res+1LL*d*(n-1)<<endl;
	return 0;
}