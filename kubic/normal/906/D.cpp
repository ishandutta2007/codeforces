#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int n,m,p,a[N],c[N];struct node {ll v;bool fl;};
int phi(int x)
{
	int res=x,t=x;
	for(int i=2;i*i<=x;++i) if(!(t%i)) {res-=res/i;while(!(t%i)) t/=i;}
	if(t>1) res-=res/t;return res; 
}
node qPow(ll x,ll y,int p)
{
	ll res=1;bool fl=0;if(x>=p) fl=1,x%=p;
	for(;y;y>>=1) {if(y&1) {res*=x;if(res>=p) fl=1,res%=p;}x*=x;if(x>=p) fl=1,x%=p;}
	return (node) {res,fl};
}
node slv(int l,int r,int x)
{
	if(c[x]==1) return (node) {0,1};if(l==r) return (node) {a[l]%c[x],a[l]>=c[x]};
	node t=slv(l+1,r,x+1);if(t.fl) t.v+=c[x+1];return qPow(a[l],t.v,c[x]);
}
int main()
{
	scanf("%d %d",&n,&p);for(int i=1;i<=n;++i) scanf("%d",&a[i]);scanf("%d",&m);
	c[1]=p;for(int i=2;;++i) {c[i]=phi(c[i-1]);if(c[i]==1) break;}
	for(int i=1,l,r;i<=m;++i) scanf("%d %d",&l,&r),printf("%lld\n",slv(l,r,1).v);
	return 0;
}