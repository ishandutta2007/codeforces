#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210000;
const int mod = 1e9+7;

int pw(int x,int k)
{
	int re=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1)
		re=(ll)re*x%mod;
	return re;
}

int p[maxn],pri,mu[maxn],mp[maxn];
bool v[maxn];
void pre()
{
	mu[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!v[i]) p[++pri]=i,mu[i]=-1,mp[i]=i;
		for(int j=1,k=i*p[j];k<maxn;j++,k=i*p[j])
		{
			v[k]=true; mp[k]=p[j];
			if(i%p[j]==0) break;
			mu[k]=-mu[i];
		}
	}
}
int n,m;
int di[maxn],pk[maxn],dn,oth;
int t[maxn],tc[maxn],tp;
void divide()
{
	int u=sqrt(n); int tmp=n;
	for(int i=2;i<=u;i++)
	{
		if(tmp%i==0) 
		{
			di[++dn]=i;
			while(tmp%i==0) pk[i]++,tmp/=i;
		}
	}
	if(tmp>1) oth=1;
	
	for(int i=1;(ll)i*i<=n;i++) if(n%i==0)
	{
		if(mu[i]) t[++tp]=i,tc[tp]=mu[i];
		if((ll)i*i==n) break;
		
		int tmp=i; while(tmp!=1) pk[mp[tmp]]--,tmp/=mp[tmp];
		int tm=1; if(oth) tm=-tm;
		for(int j=1;j<=dn;j++)
		{
			if(pk[di[j]]>1) { tm=0;break; }
			if(pk[di[j]]==1) tm=-tm;
		}
		if(tm) t[++tp]=n/i,tc[tp]=tm;
		tmp=i; while(tmp!=1) pk[mp[tmp]]++,tmp/=mp[tmp];
	}
}

int main()
{
	pre();
	scanf("%d%d",&n,&m);
	if(m%n) return puts("0"),0;
	n=m/n;
	
	divide();
	int re=0;
	for(int i=1;i<=tp;i++)
	{
		int tmp=pw(2,n/t[i]-1);
		tmp=tmp*tc[i];
		re=(re+tmp)%mod;
	}
	printf("%d\n",(re+mod)%mod);
	
	return 0;
}