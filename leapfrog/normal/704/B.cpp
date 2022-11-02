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
int n,S,T,nx[5005];ll X[5005],a[5005],b[5005],c[5005],d[5005],rs;
inline ll cal(int x,int y) {return x<y?X[y]-X[x]+d[x]+a[y]:X[x]-X[y]+c[x]+b[y];}
int main()
{
	read(n),read(S),read(T);
	for(int i=1;i<=n;i++) read(X[i]);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
	for(int i=1;i<=n;i++) read(c[i]);
	for(int i=1;i<=n;i++) read(d[i]);
	rs=cal(S,T),nx[S]=T;for(int i=1;i<=n;i++) if(i^S&&i^T)
	{
		pair<ll,int>mn=make_pair(1000000000000000000ll,0);
		for(int j=S;j^T;j=nx[j]) mn=min(mn,make_pair(cal(j,i)+cal(i,nx[j])-cal(j,nx[j]),j));
		nx[i]=nx[mn.second],nx[mn.second]=i,rs+=mn.first;
	}
	return printf("%lld\n",rs),0;
}