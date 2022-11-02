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
const int P=1e9+7;int n=1048576,m,f[1048576],sz[1048576],rs=0;
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(m);for(int i=1,x;i<=m;i++) read(x),f[x]++;
	for(int d=1;d<n;d<<=1) for(int i=0;i<n;i+=d+d) for(int j=0;j<d;j++) f[i|j]+=f[i|j|d];
	for(int i=0;i<n;i++) f[i]=ksm(2,f[i]),sz[i]=sz[i>>1]^(i&1);
	for(int i=0;i<n;i++) rs=(rs+(sz[i]?P-1ll:1ll)*f[i]%P)%P;
	return printf("%d\n",rs),0;
}