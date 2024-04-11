//???
#include <bits/stdc++.h>
using namespace std;
#define N 55
#define M 200005
#define ll long long
#define lll __int128
const int B=2e5;
int n,ps;ll w,z1[M],z2[M];char a[N];map<ll,int> vs;
ll f(ll x1,ll x2)
{
	lll t=0;
	for(int i=0;i<n-1;++i) if(x1>>i&1) t^=(lll)(x2)<<i;
	for(int i=n-3;i>=0;--i) if(t>>n+i-1&1) t^=(lll)(w)<<i;
	return t;
}
int main()
{
	scanf("%s",a+1);n=strlen(a+1);
	for(int i=1;i<=n;++i) if(a[i]=='1') {ps=i;break;}
	if(!ps) {printf("-1\n");return 0;}
	for(int i=1;i<=n;++i) if(a[i]=='1') w|=1ll<<n-i+ps-1;
	if(w==(1ll<<n-1)) {printf("%d %d\n",ps,ps+1);return 0;}
	z1[0]=z2[0]=1;for(int i=1;i<=B;++i) z1[i]=f(z1[i-1],2);
	for(int i=1;i<=B;++i) z2[i]=f(z2[i-1],z1[B]);
	for(int i=0;i<B;++i) vs[z1[i]]=i;
	for(int i=1;i<=B;++i) if(vs.count(z2[i]))
	{printf("%d %lld\n",ps,ps+1ll*i*B-vs[z2[i]]);break;}
	return 0;
}