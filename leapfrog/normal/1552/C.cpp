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
int n,K,v[205],tn[205],tt,L[205],R[205],sgt;
inline void solve()
{
	read(n),read(K),tt=0,memset(v,0,sizeof(v)),sgt=0;
	for(int i=1,x,y;i<=K;i++) read(x),read(y),++sgt,L[sgt]=x,R[sgt]=y,v[x]=v[y]=1;
	for(int i=1;i<=K;i++) if(L[i]>R[i]) swap(L[i],R[i]);
	int rs=0;for(int i=1;i<=n*2;i++) if(!v[i]) tn[++tt]=i;
	//for(int i=1;i<=tt;i++) printf("%d%c",tn[i],i==tt?'\n':' ');
	for(int i=1;i<=n-K;i++) ++sgt,L[sgt]=tn[i],R[sgt]=tn[i+tt/2];
	//for(int i=1;i<=sgt;i++) printf("%d %d\n",L[i],R[i]);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
		if(max(L[i],L[j])<min(R[i],R[j]))
		{
			if(L[i]<L[j]&&R[j]<R[i]) continue;
			if(L[j]<L[i]&&R[i]<R[j]) continue;
			rs++;
		}
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}