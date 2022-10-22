#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
int p[N];ll n,t,tg[N];bool vs[N];
void sieve(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) p[++p[0]]=i;
		for(int j=1;i*p[j]<=n;++j) {vs[i*p[j]]=1;if(!(i%p[j])) break;}
	}
}
bool chk(int x)
{
	if(n%x) return 0;
	for(int i=1;i<=p[0] && 1ll*p[i]*p[i]<=n;++i) if(!(x%p[i]) && x%tg[i]) return 0;
	return 1;
}
int main()
{
	sieve(1e6);for(int i=1;i<=1e6;++i) tg[i]=1;scanf("%lld",&n);t=n;
	for(int i=1;i<=p[0] && 1ll*p[i]*p[i]<=n;++i) while(!(t%p[i])) t/=p[i],tg[i]*=p[i];
	for(int i=sqrt(n);i>=1;--i) if(chk(i)) {printf("%d %lld\n",i,n/i);break;}
	return 0;
}