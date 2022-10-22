#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10,mod=1e9+7;
int a[maxn],cnt,m,n,p[maxn],t_case,tmp;
int main(){
	scanf("%d",&t_case);
	p[0]=1;
	for(ri i=1;i<=200000;++i)p[i]=1ll*p[i-1]*i%mod;
	while(t_case--){
		scanf("%d%d",&n,&a[1]);
		tmp=a[1];
		for(ri i=2;i<=n;++i)scanf("%d",a+i),tmp&=a[i];
		cnt=0;
		for(ri i=1;i<=n;++i)
			if(a[i]==tmp)
				++cnt;
		if(cnt<2)puts("0");
		else printf("%lld\n",1ll*cnt*(cnt-1)%mod*p[n-2]%mod);
	}
	return 0;
}