#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
int T,n,a[N],vl[N],w[N];ll ans;
void upd(int x) {for(;x<=n;x+=x&-x) ++vl[x];}
int qSm(int x)
{int res=0;for(;x;x-=x&-x) res+=vl[x];return res;}
void slv()
{
	scanf("%d",&n);ans=0;for(int i=1;i<=n;++i) vl[i]=0;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),upd(a[i]),ans+=i-qSm(a[i]);
	for(int i=1;i<=n;++i) w[i]=a[i]*2-i;sort(w+1,w+n+1);
	for(int i=0;i<=n;++i)
		ans+=w[i],printf("%lld ",ans-1ll*i*(i+1)/2);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}