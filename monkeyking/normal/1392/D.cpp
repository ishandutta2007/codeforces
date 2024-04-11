//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n;
//char s[200005];
//int c[200005];
//int dp[200005][2][2];
//
//int solve(int first,int last)
//{
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<2;j++)
//		{
//			for(int k=0;k<2;k++)
//			{
//				dp[i][j][k]=inf;
//			}
//		}
//	}
////	memset(dp,0x3f,sizeof(dp));
////	cout<<c[0]<<endl;
//	dp[1][first][last]=(c[0]!=first);
////	cout<<dp[1][1][0]<<endl;
//	for(int i=1;i<n;i++)
//	{
//		for(int fpre=0;fpre<2;fpre++)
//		{
//			for(int cntpre=0;cntpre<2;cntpre++)
//			{
//				for(int fnow=0;fnow<2;fnow++)
//				{
//					int cnt=cntpre+(fnow==0);
//					if(cnt==1)
//					{
//						if(cntpre && fpre==1) continue;
//						if(!cntpre && fpre==0) continue;
//					}
//					chmin(dp[i+1][fnow][(fpre==1)],dp[i][fpre][cntpre]+(fnow!=c[i]));
//				}
//			}
//		}
//	}
////	cout<<dp[2][0][1]<<endl;
////	cout<<dp[4][0][1]<<endl;
//	int res=inf;
//	for(int cntpre=0;cntpre<2;cntpre++)
//	{
//		int cnt=cntpre+(first==0);
//		if(cnt==1)
//		{
//			if(cntpre && (last!=0)) continue;
//			if(!cntpre && (last!=1)) continue;
//		}
//		chmin(res,dp[n][last][cntpre]);
//	}
//	return res;
//}
//
//void solve()
//{
//	scanf("%d",&n);
//	scanf("%s",s);
//	for(int i=0;i<n;i++)
//	{
//		c[i]=(s[i]=='R');
//	}
//	int res=inf;
////	cout<<solve(1,0)<<endl;
////	return;
//	for(int first=0;first<2;first++)
//	{
//		for(int last=0;last<2;last++)
//		{
//			chmin(res,solve(first,last));
//		}
//	}
//	printf("%d\n",res);
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	int T;
//	cin>>T;
//	while(T--)
//	{
//		solve();
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
char s[200005];
int c[200005];
int dp[200005][2][2];

int solve(int first,int last)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				dp[i][j][k]=inf;
			}
		}
	}
//	memset(dp,0x3f,sizeof(dp));
//	cout<<c[0]<<endl;
	dp[1][first][last]=(c[0]!=first);
//	cout<<dp[1][1][0]<<endl;
	for(int i=1;i<n;i++)
	{
		for(int fpre=0;fpre<2;fpre++)
		{
			for(int cntpre=0;cntpre<2;cntpre++)
			{
				for(int fnow=0;fnow<2;fnow++)
				{
					int cnt=cntpre+(fnow==0);
					if(cnt==1)
					{
						if(cntpre && fpre==1) continue;
						if(!cntpre && fpre==0) continue;
					}
					chmin(dp[i+1][fnow][(fpre==1)],dp[i][fpre][cntpre]+(fnow!=c[i]));
				}
			}
		}
	}
//	cout<<dp[2][0][1]<<endl;
//	cout<<dp[4][0][1]<<endl;
	int res=inf;
	for(int cntpre=0;cntpre<2;cntpre++)
	{
		int cnt=cntpre+(first==0);
		if(cnt==1)
		{
			if(cntpre && (last!=0)) continue;
			if(!cntpre && (last!=1)) continue;
		}
		chmin(res,dp[n][last][cntpre]);
	}
	return res;
}

void solve()
{
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++)
	{
		c[i]=(s[i]=='R');
	}
	int res=inf;
//	cout<<solve(1,0)<<endl;
//	return;
	for(int first=0;first<2;first++)
	{
		for(int last=0;last<2;last++)
		{
			chmin(res,solve(first,last));
		}
	}
	printf("%d\n",res);
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}