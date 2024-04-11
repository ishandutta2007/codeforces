//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n,m;char v1[1<<22],v2[1<<22];
inline void dfs(int x,int typ)
{
	if((typ&&v2[x])||(!typ&&v1[x])) return;
	if(!typ) return v1[x]=1,dfs(((1<<n)-1)^x,1);
	v2[x]=1,dfs(x,0);for(int i=1<<n;i;i>>=1) if(x&i) dfs(x^i,1);
}
int main()
{
	read(n,m);for(int i=0;i<(1<<n);i++) v1[i]=1;
	int cnt=0;for(int i=1,x;i<=m;i++) read(x),v1[x]=0;
	for(int i=0;i<(1<<n);i++) if(!v1[i]) dfs(i,0),cnt++;
	return printf("%d\n",cnt),0;
}