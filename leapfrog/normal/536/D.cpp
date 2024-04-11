//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int N=2005;struct edge{int to,w,nxt;}e[200005];int et,head[N];
int n,m,S,T,ds[N],dt[N],ut,a[N],ns[N][N],nt[N][N];
ll s[N][N],f[2][N][N],tn[N],d[N];int c[N][N],tns,tnt;
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dijk(int s,int &tt,int *ds)
{
	priority_queue<pair<ll,int> >q;memset(d,0x3f,sizeof(d)),q.push(make_pair(d[s]=0,s));
	while(!q.empty())
	{
		int x=q.top().second;ll w=-q.top().first;q.pop();if(w^d[x]) continue;
		for(int i=head[x];i;i=e[i].nxt) if(d[e[i].to]>d[x]+e[i].w)
			q.push(make_pair(-(d[e[i].to]=d[x]+e[i].w),e[i].to));
	}
	ut=0;for(int i=1;i<=n;i++) tn[++ut]=d[i];
	sort(tn+1,tn+ut+1),tt=ut=unique(tn+1,tn+ut+1)-tn-1;
	for(int i=1;i<=n;i++) ds[i]=lower_bound(tn+1,tn+ut+1,d[i])-tn;
}
int main()
{
	read(n),read(m),read(S),read(T);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),adde(x,y,w),adde(y,x,w);
	dijk(S,tns,ds),dijk(T,tnt,dt);for(int i=1;i<=n;i++) c[ds[i]][dt[i]]++,s[ds[i]][dt[i]]+=a[i];
	for(int i=tns;i;i--) for(int j=tnt;j;j--)
	{
		s[i][j]+=s[i+1][j]+s[i][j+1]-s[i+1][j+1];
		ns[i][j]=min(i==tns?tns:ns[i+1][j],j==tnt?tnt:ns[i][j+1]);
		nt[i][j]=min(i==tns?tnt:nt[i+1][j],j==tnt?tns:nt[i][j+1]);
		if(c[i][j]) ns[i][j]=i,nt[i][j]=j;
		f[0][i][j]=s[i][j]-f[1][ns[i][j]+1][j];
		f[1][i][j]=s[i][j]-f[0][i][nt[i][j]+1];
		if(i==1&&j==1) continue;
		f[0][i][j]=min(f[0][i][j],f[0][i][j+1]);
		f[1][i][j]=min(f[1][i][j],f[1][i+1][j]);
	}
	ll r=s[1][1]-f[0][1][1]*2;
	if(r>0) puts("Cry");else if(r<0) puts("Break a heart");else puts("Flowers");
	return 0;
}