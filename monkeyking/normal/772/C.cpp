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
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
map <int,int> id;
int n,k;
int phi,mod;
vector <int> prime;
int dp[200005];
int a[200005];
vector <int> vec[200005];
int trace[200005];

inline int mutiply(int a,int b)
{
	return (1LL*a*b)%mod;
}

int fastpow(int basic,int x)
{
	int res=1;
	while(x)
	{
		if(x&1)
		{
			res=mutiply(res,basic);
		}
		basic=mutiply(basic,basic);
		x>>=1;
	}
	return res;
}

pair<int,int> exgcd(int a,int b)
{
	if(b==0) return mp(1,0);
	pii t=exgcd(b,a%b);
	return mp(t.second,t.first-(int)(a/b)*t.second);
}

int inv(int x,int mod)
{
	pii t=exgcd(x,mod);
	return ((t.first)%mod+mod)%mod;
//	return fastpow(x,phi-1);
}

void init()
{
	for(int i=1;i<=k;i++)
	{
		a[i]=1;
	}
	mod=k;
	for(int i=1;i<=k;i++)
	{
		if(__gcd(i,k)==1) phi++;
	}
	int tk=k;
	for(int i=2;i*i<=k;i++)
	{
		if(k%i==0)
		{
			prime.push_back(i);
		}
		while(tk%i==0)
		{
			tk/=i;
		}
	}
	if(tk!=1) prime.push_back(tk);
}

void prework()
{
	for(int i=1;i<=k;i++)
	{
		if(!a[i]) continue;
		vec[__gcd(i,k)].push_back(i);
	}
}

void solve()
{
	for(int i=1;i<=k;i++)
	{
		if(k%i) continue;
		dp[i]+=vec[i].size();
		for(int j=i+i;j<=k;j+=i)
		{
			if(k%j) continue;
			if(dp[j]<dp[i])
			{
				dp[j]=dp[i];
				trace[j]=i;
			}
		}
	}
}

int calc(int x,int y)
{
	int gcd=__gcd(__gcd(x,mod),__gcd(y,mod));
//	cout<<gcd<<endl;
	x/=gcd;
	y/=gcd;
	return mutiply(y,inv(x,mod/gcd));
}

void print()
{
	cout<<dp[k]<<endl;
	vector <int> res;
	int now=k;
	while(now)
	{
		res.push_back(now);
		now=trace[now];
	}
	reverse(all(res));
	vector <int> muti;
	for(auto i:res)
	{
		for(auto j:vec[i])
		{
			muti.push_back(j);
		}
	}
	cout<<muti[0]%mod;
	for(int i=1;i<muti.size();i++)
	{
		printf(" %d",calc(muti[i-1],muti[i]));
	}
}

int main()
{
//	freopen("input.txt","w",stdout);
	cin>>n>>k;
	init();
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x==0) x=k;
		a[x]=0;
	}
	prework();
	solve();
	print();
	return 0;
}