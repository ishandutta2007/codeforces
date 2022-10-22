#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int T,n,m,s,t,cnt[N<<1];ll ans;char a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		t=ans=0;scanf("%d %d %s",&n,&m,a+1);
		for(int i=-n;i<=n;++i) cnt[i+n]=0;++cnt[n];
		for(int i=1;i<=n;++i) {if(a[i]=='0') ++t;else --t;if(i<n) ++cnt[t+n];}
		if(!t) {if(m<=n && m>=-n && cnt[m+n]) puts("-1");else puts("0");continue;}
		for(int i=-n;i<=n;++i) if(!((m-i)%t) && (m-i)/t>=0) ans+=cnt[i+n];
		printf("%lld\n",ans);
	}return 0;
}