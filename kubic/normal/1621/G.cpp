#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 1000000007
#define pb push_back
int T,n,s,ans,a[N],ord[N],ps[N],vl[N],w1[N],w2[N],w[N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
bool cmp(int x,int y) {return a[x]==a[y]?x>y:a[x]<a[y];}
void clear() {s=0;for(int i=1;i<=n;++i) vl[i]=0;}
void upd(int x,int w) {s=add(s,w);for(;x<=n;x+=x&-x) vl[x]=add(vl[x],w);}
int qSm(int x) {int res=0;for(;x;x-=x&-x) res=add(res,vl[x]);return res;}
void slv()
{
	scanf("%d",&n);ans=0;for(int i=1;i<=n;++i) ord[i]=i,scanf("%d",&a[i]);
	sort(ord+1,ord+n+1,cmp);for(int i=1;i<=n;++i) a[ord[i]]=i;
	clear();for(int i=1;i<=n;++i) w1[i]=qSm(a[i])+1,upd(a[i],w1[i]); 
	clear();for(int i=n;i;--i) w2[i]=add(s,MOD-qSm(a[i]))+1,upd(a[i],w2[i]);
	for(int i=1,t=n;i<=n;++i) {while(t && a[t]<i) --t;ps[i]=t;}clear();
	for(int i=n;i;--i) if(ps[a[i]]<=i) w[i]=1;else
		w[i]=add(qSm(a[ps[a[i]]]),MOD-qSm(a[i]-1))+1,upd(a[i],w[i]);
	for(int i=1;i<=n;++i) ans=add(ans,1ll*w1[i]*add(w2[i],MOD-w[i])%MOD);
	printf("%d\n",ans);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}