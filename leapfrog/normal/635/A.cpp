//{{{
#include<bits/stdc++.h>
#define sc second
#define fr first
#define mk make_pair
#define pb push_back
#define pi pair<int,int>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int r,c,n,K,p[3005],q[3005],t[3005],v[3005];pi a[3005];vector<pi>R[3005],C[3005];ll res=0;
inline ll cl(int i,int j,int w) {ll r=1ll*(t[w]-j+1)*(a[w].sc-a[p[w]].sc)*(c-a[v[w]].sc+1);return t[w]=j-1,r;}
int main()
{
	read(r),read(c),read(n),read(K);for(int i=1,x,y;i<=n;i++) read(x),read(y),a[i]=mk(x,y),R[x].pb(mk(y,i)),C[y].pb(mk(x,i));
	for(int i=1;i<=r;i++) sort(R[i].begin(),R[i].end());
	for(int i=1;i<=c;i++) sort(C[i].begin(),C[i].end());
	a[n+1]=mk(r+1,c+1);for(int i=1;i<=r;i++)
	{
		int w=0;for(int j=1;j<=c;j++) for(auto x:C[j]) if(x.fr>=i) q[w]=x.sc,p[x.sc]=w,w=x.sc,t[w]=r,v[w]=0;
		q[w]=q[n+1]=v[n+1]=n+1,t[n+1]=r,w=0;for(int j=1;j<=K;j++) w=q[w];
		for(int j=q[0];j^(n+1);j=q[j],w=q[w]) v[j]=w;
		for(int j=r;j>=i;j--) for(auto x:R[j])
		{
			res+=cl(i,j,q[x.sc]),w=x.sc;
			for(int l=1;w&&l<=K;l++,w=p[w]) res+=cl(i,j,w);
			q[p[x.sc]]=q[x.sc],p[q[x.sc]]=p[x.sc];
			int wh=w=q[w];for(int l=1;l<K;l++) wh=q[wh];
			while(w^q[x.sc]) v[w]=wh,w=q[w],wh=q[wh];
		}
	}
	return printf("%lld\n",res),0;
}