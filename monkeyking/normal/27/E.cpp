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
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
ll n;
vector <ll> vec;
int p[1000];
int ps;
int can[1000];
int cs;
ll road[1000];
ll ans=1e18*2;


long long kuaism(long long n,long long m)
{
	if(n==1)
	{
		return m;
	}
	else if(!n)
	{
		return 1;
	}
	else
	{
		if(n%2)
		{
			long long a=kuaism(n/2,m);
			return m*a*a;
		}
		else
		{
			long long a=kuaism(n/2,m);
			return a*a;
		}
	}
}

long long jiec(long long n)
{
	if(n==1)
	{
		return 1;
	}
	else 
	{
		return jiec(n-1)*n;
	}
}

long long kuaism(long long n,long long m,long long mod)
{
	if(n==1)
	{
		return m%mod;
	}
	else if(!n)
	{
		return 1;
	}
	else
	{
		if(n%2)
		{
			long long a=kuaism(n/2,m,mod)%mod;
			return m*a*a%mod;
		}
		else
		{
			long long a=kuaism(n/2,m,mod)%mod;
			return a*a%mod;
		}
	}
}

long long jiec(long long n,long long mod)
{
	if(n==1)
	{
		return 1;
	}
	else 
	{
		return jiec(n-1,mod)%mod*n%mod;
	}
}

unsigned long long C(int a,int k,long long mod)
{
	if (a==k) return 1;
	if (k==0) return 1;
	if (a==0) return 0;
	int b=k;
	b=a<b*2?a-b:b;
	int d[b]={0};
	int i,j;
	long long s=1;
	for(i=a;i>a-b;i--)
	{
		s*=i;
		for(j=1;j<=b;j++)
		{
			if(!d[j-1])
			{
				if(s%j==0)
				{
					s/=j;
					d[j-1]=1;
				}
			}
		}
		s%=mod;
	}
	return s;
}

unsigned long long C(int a,int k)
{
	if (a==k) return 1;
	if (k==0) return 1;
	if (a==0) return 0;
	int b=k;
	b=a<b*2?a-b:b;
	int d[b]={0};
	int i,j;
	long long s=1;
	for(i=a;i>a-b;i--)
	{
		s*=i;
		for(j=1;j<=b;j++)
		{
			if(!d[j-1])
			{
				if(s%j==0)
				{
					s/=j;
					d[j-1]=1;
				}
			}
		}
	}
	return s;
}

int print_0x(int x)
{
	int res=0;
	while(x)
	{
		res=res*10+x&1;
		x/=2;
	}
	return res;
}

int shaiprime(int a[],int n)
{
	bool b[n];
	for(int i=0;i<n;i++)
	{
		b[i]=true;
	}
	for(int i=2;i<n;i++)
	{
		if(!b[i]) continue;
		for(int j=i+i;j<n;j+=i)
		{
			b[j]=false;
		}
	}
	int k=0;
	for(int i=2;i<n;i++)
	{
		if(b[i]) a[k++]=i;
	}
	return k;
}


ll cf(ll n,ll m)
{
	ll ans=1;
	rep(m)
	{
		ans*=n;
	}
	return ans;
}

void dfs(ll now,ll least,ll s)
{
//	cout<<now<<endl;
//	printf("%d%d:\n",s,now);
	if(now==1LL)
	{
		ll t=1LL;
		for(int i=0;i<s;i++)
		{
			t*=cf(p[i],can[road[s-i-1]]-1);
			if(t>1e18) return;
			if(t<=0) return;
		}
		if(t<ans)
		{
			ans=t;
//			for(int i=0;i<s;i++)
//			{
//				cout<<p[road[i]]<<' ';
//				cout<<p[i]<<' '<<p[road[s-i-1]]-1<<endl;
//			}
//			cout<<endl;
		}
	}
	for(ll i=least;i<cs;i++)
	{
		if(now%can[i]==0LL)
		{
//			cout<<p[i]<<' ';
			road[s]=i;
			dfs(now/can[i],i,s+1);
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ps=shaiprime(p,1000);
	cin>>n;
	cs=0;
	for(int i=2;i<=n;i++)
	{
		if(n%i==0) can[cs++]=i;
	}
	dfs(n,0LL,0LL);
	cout<<ans<<endl;
	return 0;
}