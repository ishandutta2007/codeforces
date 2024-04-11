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
int ci,cd,cr,ce;
int dp[4005][4005];
char a[4005],b[4005];
int nxta[4005][26],nxtb[4005][26];
int n,m;
int ccd[5005],cci[5005];

int solve()
{
	for(int i=0;i<n;i++) a[i]-='a';
	for(int i=0;i<m;i++) b[i]-='a';
	for(int j=0;j<26;j++)
	{
		nxta[n][j]=nxtb[n][j]=n;
		for(int i=n-1;i>=0;i--)
		{
			nxta[i][j]=nxta[i+1][j];
			nxtb[i][j]=nxtb[i+1][j];
			if(a[i]==j) nxta[i][j]=i;
			if(b[i]==j) nxtb[i][j]=i;
		}
	}
	for(int i=0;i<=max(n,m);i++) ccd[i]=cd*i,cci[i]=ci*i;
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int j=0;j<=m;j++)
	{
		for(int i=0;i<=n;i++)
		{
			int f=dp[i][j];
			if(a[i]==b[j]) chmin(dp[i+1][j+1],f);
			else chmin(dp[i+1][j+1],f+cr);
			chmin(dp[i+1][j],f+cd);
			chmin(dp[i][j+1],f+ci);
			if(a[i]==b[j]) continue;
			int x=nxta[i][b[j]],y=nxtb[j][a[i]];
			int ca=ccd[(x-i-1)],cb=cci[(y-j-1)];
			f+=ce;
			chmin(dp[x+1][y+1],f+ca+cb);
			// chmin(dp[x+1][j+2],f+ca+cr);
			// chmin(dp[i+2][y+1],f+cb+cr);
		}
	}
	return dp[n][m];
}

int main()
{
	cin>>ci>>cd>>cr>>ce;
	scanf("%s",a);
	scanf("%s",b);
	n=strlen(a);
	m=strlen(b);
	a[n]=1,a[n+1]=2;
	b[m]=3,b[m+1]=4;
	cout<<solve()<<endl;
	return 0;
}