#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
int T,n,a[N],ps[N],vl[N];ll ans;
void upd(int x) {for(;x<=n;x+=x&-x) ++vl[x];}
int qSm(int x) {int res=0;for(;x;x-=x&-x) res+=vl[x];return res;}
void slv()
{
	scanf("%d",&n);ans=0;for(int i=1;i<=n;++i) vl[i]=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),ps[a[i]]=i;
	for(int i=n,t;i;--i)
	{
		if(i>1)
		{
			t=qSm(ps[i])-qSm(ps[i-1]);
			if(ps[i]<ps[i-1]) t+=n-i;ans+=1ll*(i-1)*t;
		}upd(ps[i]);
	}printf("%lld\n",ans);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}