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
const int N=200005;struct edge{int to,nxt;}e[N<<2];int et,head[N];
int n,a[N],c[N],ct,mu[N],pr[N],pc;ll F[N],G[N];char pv[N],v[N];vector<int>vc[N];
inline int gcd(int x,int y) {return y?gcd(y,x%y):x;}
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int dfs(int x) {int cnt=v[x]=1;for(int i=head[x];i;i=e[i].nxt) if(!v[e[i].to]) cnt+=dfs(e[i].to);return cnt;}
inline ll get(int val)
{
	ct=0;for(int i=val;i<=200000;i+=val) for(auto x:vc[i]) c[++ct]=x;
	ll res=0;for(int i=1;i<=ct;i++) v[c[i]]=0;
	for(int i=1;i<=ct;i++) if(!v[c[i]]) {ll tot=dfs(c[i]);res+=1ll*tot*(tot+1)/2;}
	return res;
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),vc[a[i]].push_back(i);
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	for(int i=1;i<=200000;i++) F[i]=get(i);
	pv[1]=mu[1]=1;for(int i=1;i<=200000;i++)
	{
		if(!pv[i]) pr[++pc]=i,mu[i]=-1;
		for(int j=1;j<=pc&&i*pr[j]<=200000;j++)
		{
			mu[i*pr[j]]=i%pr[j]?-mu[i]:0;
			pv[i*pr[j]]=1;if(i%pr[j]==0) break;
		}
	}
	for(int i=1;i<=200000;i++) for(int j=1;j*i<=200000;j++) G[i]+=mu[j]*F[i*j];
	for(int i=1;i<=200000;i++) if(G[i]) printf("%d %lld\n",i,G[i]);
	return 0;
}