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
const int mod=998244353;
const int gmod=5;
const int inf=1039074182;
const double eps=1e-9;
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
vector<int> edges[3005]; //


struct Value
{
	int f[305];
	Value() {memset(f,0,sizeof(f));}
	Value& operator += (const Value &oth){
		for(int i=0;i<=n;i++) chadd(f[i],oth.f[i]);
		return (*this);
	}
	Value& operator -= (const Value &oth){
		for(int i=0;i<=n;i++) chadd(f[i],mod-oth.f[i]);
		return (*this);
	}
	Value& operator *= (const Value &oth){
		for(int i=0;i<=n;i++) f[i]=(1LL*f[i]*oth.f[i])%mod;
		return (*this);
	}
	Value operator + (const Value &oth)const{
		return Value(*this)+=oth;
	}
	Value operator - (const Value &oth)const{
		return Value(*this)-=oth;
	}
	Value operator * (const Value &oth)const{
		return Value(*this)*=oth;
	}
	inline void add(int pos,int w)
	{
		for(int i=pos;i<=n;i++) chadd(f[i],w);
	}
};
Value dp[305][305][2];//00<=mxmn1
Value f[305];//mx0

void dfs(int x,int par=-1)
{
	int leaf=1;
	for(auto u:edges[x])
	{
		if(u==par) continue;
		dfs(u,x);
		leaf=0;
	}
	if(leaf)
	{
		f[x].add(0,1);
		for(int k=1;k<=n;k++)
		{
			dp[x][k][0].add(k,1);
		}
		return;
	}

	//0
	f[x].add(0,1);
	// if(x==0) cout<<f[1].f[1]<<' '<<dp[1][1][0].f[1]<<' '<<dp[1][1][1].f[1]<<endl;
	for(auto u:edges[x])
	{
		if(u==par) continue;
		f[x]*=(f[u]+dp[u][1][0]+dp[u][1][1]);
	}
	// if(x==0)
	// {
	// 	cout<<("SHIT")<<endl;
	// 	cout<<f[x].f[0]<<endl;
	// 	cout<<f[x].f[1]<<endl;
	// }

	//1

	//
	{
		Value res,sub;
		res.add(1,1);
		sub.add(1,1);
		for(auto u:edges[x])
		{
			if(u==par) continue;
			Value dif=f[u];
			Value sme=dp[u][1][1]+dp[u][2][0]+dp[u][2][1];
			res=res*(dif+sme);
			sub=sub*sme;
		}
		dp[x][1][1]=res-sub;
		// if(x==0)
		// {
		// 	cout<<dp[0][1][1].f[0]<<' '<<dp[0][1][1].f[1]<<endl;
		// }
	}

	//
	{
		for(int k=1;k<=n;k++)
		{
			Value h0,h1;
			h0.add(k,1);h1.add(k,1);
			for(auto u:edges[x])
			{
				if(u==par) continue;
				Value com=dp[u][k][1]+dp[u][k+1][0]+dp[u][k+1][1];
				Value spe=dp[u][k-1][1];
				h1=h1*(com+spe);
				h0=h0*com;
			}
			dp[x][k][0]+=h0;
			dp[x][k][1]+=h1-h0;
		}
	}
}

inline int fastpow(ll basic,int x)
{
	ll res=1;
	while(x)
	{
		if(x&1) (res*=basic)%=mod;
		(basic*=basic)%=mod;
		x>>=1;
	}
	return res;
}

int main()
{
	// freopen("tree.in","r",stdin);
	// freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		edges[x].emplace_back(y);
		edges[y].emplace_back(x);
	}
	dfs(0);
	int res=0;
	Value v=f[0];
	for(int k=1;k<=n;k++)
	{
		v+=dp[0][k][1];
	}
	for(int d=1;d<=n;d++)
	{
		// cout<<v.f[d]-v.f[d-1]<<endl;
		res=(1LL*(v.f[d]-v.f[d-1]+mod)*(d-1)+res)%mod;
	}
	cout<<1LL*(res+n-1)*fastpow(2,mod-1-n)%mod<<endl;
	return 0;
}