#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T;ll n,m,ans;
int main()
{
	scanf("%d",&T);
	while(T--) {ans=0;scanf("%lld %lld",&n,&m);while(n) ans+=n%m+1,n/=m;printf("%lld\n",ans-1);}
}