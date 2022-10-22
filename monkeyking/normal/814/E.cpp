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
#define mt make_tuple
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1000000007;
const int gmod=3;
const int inf=1039074182;
const double eps=1e-9;
const double pi=3.141592653589793238462643383279;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;
int n;
int d[1005];
int f[305][305];
int dp[305][305][305];

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	d[0]++;
	dp[n][0][0]=1;
	for(int i=n;i>0;i--)
	{
		for(int d1=0;d1<=(n-i);d1++)
		{
			for(int d2=0;d2<=(n-i-d1);d2++)
			{
				if(!dp[i][d1][d2]) continue;
				ll val=dp[i][d1][d2];
				if(d[i-1]==2)
				{
					if(d1) chadd(dp[i-1][d1-1][d2],val*d1%mod);
					if(d2) chadd(dp[i-1][d1+1][d2-1],val*d2%mod);
					chadd(dp[i-1][d1+1][d2],val);
				}
				else if(d[i-1]==3)
				{
					// if(i-1==1 && d1-1==0 && d2-1==0) debug(val,d1,d2);
					if(d1 && d2) chadd(dp[i-1][d1][d2-1],val*d1*d2%mod);
					if(d1>=2) chadd(dp[i-1][d1-2][d2],val*(d1*(d1-1)/2)%mod);
					if(d2>=2) chadd(dp[i-1][d1+2][d2-2],val*(d2*(d2-1)/2)%mod);
					if(d1) chadd(dp[i-1][d1][d2],val*d1%mod);
					if(d2) chadd(dp[i-1][d1+2][d2-1],val*d2%mod);
					chadd(dp[i-1][d1][d2+1],val);
				}
				else
				{
					assert(i==1);
					if(d1+d2!=3) continue;
					chadd(dp[0][0][0],val);
				}
			}
		}
	}
	for(int l=n-1;l>=0;l--)
	{
		f[l][n-1]=dp[l][0][0];
	}
	for(int l=n-1;l>=0;l--)
	{
		for(int i=0;i<=l;i++)
		{
			for(int d1=0;d1<=(n-i);d1++)
			{
				memset(dp[i][d1],0,4*(n-i-d1+1));
			}
		}
		for(int r=l;r<=n-1;r++)
		{
			dp[l][r-l+1][0]=f[l][r];
		}
		for(int i=l;i>0;i--)
		{
			for(int d1=0;d1<=(n-i);d1++)
			{
				for(int d2=0;d2<=(n-i-d1);d2++)
				{
					if(!dp[i][d1][d2]) continue;
					ll val=dp[i][d1][d2];
					if(d[i-1]==2)
					{
						if(d1) chadd(dp[i-1][d1-1][d2],val*d1%mod);
						if(d2) chadd(dp[i-1][d1+1][d2-1],val*d2%mod);
						chadd(dp[i-1][d1+1][d2],val);
					}
					else if(d[i-1]==3)
					{
						if(d1 && d2) chadd(dp[i-1][d1][d2-1],val*d1*d2%mod);
						if(d1>=2) chadd(dp[i-1][d1-2][d2],val*(d1*(d1-1)/2)%mod);
						if(d2>=2) chadd(dp[i-1][d1+2][d2-2],val*(d2*(d2-1)/2)%mod);
						if(d1) chadd(dp[i-1][d1][d2],val*d1%mod);
						if(d2) chadd(dp[i-1][d1+2][d2-1],val*d2%mod);
						chadd(dp[i-1][d1][d2+1],val);
					}
					else
					{
						if(d1+d2!=3) continue;
						chadd(dp[0][0][0],val);
					}
				}
			}
		}
		for(int nl=l-1;nl>=0;nl--)
		{
			chadd(f[nl][l-1],dp[nl][0][0]);
		}
	}
	// cout<<tot<<endl;
	// cout<<nct<<endl;
	cout<<f[0][0]<<endl;
	return 0;
}