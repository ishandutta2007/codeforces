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
#define ld long double
using namespace std;

ll gcd(ll a,ll b){return !a?b:gcd(b%a,a);}

const int maxn = 210000;
const ld eps = 1e-7;

int n;
int wn,hn;
map<int,ll>mp[maxn];
ll wi[maxn],hi[maxn],ci[maxn];

struct node
{
	ll x; ll *i;
	friend inline bool operator <(const node a,const node b){return a.x<b.x;}
}a[maxn];
void Trans()
{
	for(int i=1;i<=n;i++) a[i].x=wi[i],a[i].i=&wi[i];
	sort(a+1,a+n+1); a[0].x=a[1].x-1;
	wn=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1].x!=a[i].x) ++wn;
		(*a[i].i)=wn;
	}
	
	for(int i=1;i<=n;i++) a[i].x=hi[i],a[i].i=&hi[i];
	sort(a+1,a+n+1); a[0].x=a[1].x-1;
	hn=0;
	for(int i=1;i<=n;i++) 
	{
		if(a[i].x!=a[i-1].x) ++hn;
		(*a[i].i)=hn;
	}
}

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d",&n); ll g=0;
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld%lld%lld",&wi[i],&hi[i],&ci[i]);
		g=gcd(g,ci[i]);
	}
	Trans();
	
	if((ll)wn*hn!=n) return puts("0"),0;
	
	for(int i=1;i<=n;i++) ci[i]/=g;
	for(int i=1;i<=n;i++) mp[wi[i]][hi[i]]=ci[i];
	
	for(int i=1;i<wn;i++)
	{
		for(int j=2;j<=hn;j++)
		{
			ld t1=(ld)mp[i][j]/(ld)mp[i][j-1];
			ld t2=(ld)mp[i+1][j]/(ld)mp[i+1][j-1];
			if(abs(t1-t2)>eps) return puts("0"),0;
		}
	}
	ll ans=0;
	for(int i=1;(ll)i*i<=g;i++) if(g%i==0)
	{
		ans++;
		if((ll)i*i!=g) ans++;
	}
	printf("%lld\n",ans);
	
	return 0;
}