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
#define inf 1e9
using namespace std;

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
const int maxn = 1010000;
const int mod = 1e9+7;
inline void add(int &a,const int &b){a+=b;if(a>=mod)a-=mod;}

int pw(int x,int k)
{
	int re=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1)
		re=(ll)re*x%mod;
	return re;
}
int inv(int x){return pw(x,mod-2);}

int p[maxn],pri,mp[maxn],pn[maxn];
int r0[maxn];
int s[maxn],invs[maxn];
void pre()
{
	r0[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!mp[i]) p[++pri]=i,mp[i]=i,pn[i]=1;
		for(int j=1,k=p[j]*i;k<maxn;j++,k=p[j]*i)
		{
			mp[k]=p[j];
			if(i%p[j]==0) { pn[k]=pn[i]; break; }
			pn[k]=pn[i]+1;
		}
		r0[i]=(1ll<<pn[i])%mod;
	}
	
	s[0]=1; for(int i=1;i<maxn;i++) s[i]=(ll)s[i-1]*i%mod;
	invs[maxn-1]=inv(s[maxn-1]);
	for(int i=maxn-2;i>=0;i--) invs[i]=(ll)invs[i+1]*(i+1)%mod;
}
int C(const int n,const int m){return (ll)s[n]*invs[m]%mod*invs[n-m]%mod;}

int t[maxn],tp,tu[maxn];
int m,r,n;
int solve()
{
	int re=1;
	for(int i=1;i<=tp;i++)
	{
		int tmp=0;
		for(int j=0;j<=t[i];j++)
		{
			int now=!j?1:2;
			if(j<t[i]) now=(ll)now*C(t[i]-j+1+r-2,r-1)%mod;
			add(tmp,now);
		}
		re=(ll)re*tmp%mod;
	}
	return re;
}

int main()
{
	pre();
	read(m);
	while(m--)
	{
		read(r),read(n);
		if(n<=0) { puts("0");continue; }
		if(!r) { printf("%d\n",r0[n]); continue; }
		if(n==1) { puts("1"); continue; }
		tp=0; int tmp=n;
		while(tmp>1)
		{
			int pi=mp[tmp]; t[++tp]=0;
			while(mp[tmp]==pi) tmp/=pi,t[tp]++;
		}
		printf("%d\n",solve());
	}
	
	return 0;
}