//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=1e9+7;int T[200005],pr[1000005];vector<pair<int,int> >q[200005];
int n,Q,a[200005],p[1000005],pc,ls[1000005],rs[200005],sm[200005];char v[1000005];
inline void init()
{
	v[1]=1;for(int i=2;i<=1000000;i++)
	{
		if(!v[i]) p[++pc]=i,ls[i]=i;
		for(int j=1;j<=pc&&i*p[j]<=1000000;j++) {ls[i*p[j]]=p[j],v[i*p[j]]=1;if(i%p[j]==0) break;}
	}
}
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void add(int x,int w) {for(;x<=n;x+=x&(-x)) T[x]=1ll*T[x]*w%P;}
inline int qry(int x) {int r=1;for(;x;x-=x&(-x)) r=1ll*r*T[x]%P;return r;}
inline void upd(int i,int x)
{
	for(int p=ls[x];x^1;p=ls[x])
	{
		add(i,1ll*(p-1)*ksm(p)%P);if(pr[p]) add(pr[p],1ll*p*ksm(p-1)%P);
		pr[p]=i;while(x%p==0) x/=p;
	}
}
inline int ask(int l,int r) {return 1ll*sm[r]*ksm(sm[l-1])%P*qry(r)%P*ksm(qry(l-1))%P;}
int main()
{
	read(n),init(),sm[0]=1;for(int i=1;i<=n;i++) read(a[i]),T[i]=1,sm[i]=1ll*sm[i-1]*a[i]%P;
	read(Q);for(int i=1,x,y;i<=Q;i++) read(x),read(y),q[y].push_back(make_pair(x,i));
	for(int i=1;i<=n;i++) {upd(i,a[i]);for(auto j:q[i]) rs[j.second]=ask(j.first,i);}
	for(int i=1;i<=Q;i++) printf("%d\n",rs[i]);
	return 0;
}