#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int T,MOD;
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
ll fac[SZ],rfac[SZ],ans[SZ],c[SZ];
#define S 403
void operator *= (vector<int>& a,vector<int>& b)
{
	for(int i=0;i<S;++i) c[i]=0;
	for(int i=0;i<S;++i)
	{
		for(int j=0;j<=i;++j)
		{
			c[i]+=a[j]*(ll)b[i-j];
			if(!(j&7)) c[i]%=MOD;
		}
		c[i]%=MOD;
	}
	for(int i=0;i<S;++i) a[i]=c[i];
}
int main()
{
	cin>>T>>MOD;
	fac[0]=1;
	for(int i=1;i<SZ;++i)
		fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i>=1;--i)
		rfac[i-1]=rfac[i]*i%MOD;
	vector<int> v,x,a;
	a.resize(S); a[0]=1;
	x.resize(S);
	for(int i=0;i<S;++i)
		v.pb(fac[i+1]);
	for(int i=0;i<S;++i)
	{
		ll t=(i==0);
		for(int j=0;j<i;++j)
			t=(t-v[i-j]*(ll)x[j])%MOD;
		x[i]=t;
	}
	for(int i=1;i<=400;++i)
	{
		a*=x;
		ans[i]=-a[i-1]*(ll)rfac[i]%MOD*fac[i-1]%MOD;
		if((i+1)&1) ans[i]-=2;
		else ans[i]+=2;
		if(i==2) ans[i]=2;
	}
	while(T--)
	{
		int n;
		cin>>n;
		n=ans[n];
		n=(n%MOD+MOD)%MOD;
		cout<<n<<"\n";
	}
}