//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
const int N=65537;int n,m,lim,iv[N],rs[N];char v[N];
struct edge{int to,nxt;}e[N<<4];int et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void solve()
{
	read(n),m=n*(1<<(n-1)),lim=1<<n,et=0;for(int i=0;i<lim;i++) head[i]=iv[i]=v[i]=0;
	for(int i=0,x,y;i<m;i++) read(x),read(y),adde(x,y),adde(y,x);
	vector<int>ls,nw;iv[0]=0,v[0]=1;int cnt=1;
	for(int i=head[0],j=0;i;i=e[i].nxt,j++)
		iv[e[i].to]=1<<j,ls.push_back(e[i].to),cnt++,v[e[i].to]=1;
	while(cnt!=lim)
	{
		for(int x:ls) for(int i=head[x];i;i=e[i].nxt) if(!v[e[i].to]) iv[e[i].to]|=iv[x];
		for(int x:ls) for(int i=head[x];i;i=e[i].nxt)
			if(!v[e[i].to]) nw.push_back(e[i].to),v[e[i].to]=1,cnt++;
		swap(nw,ls),nw.clear();
	}
	for(int i=0;i<lim;i++) rs[iv[i]]=i;
	for(int i=0;i<lim;i++) printf("%d%c",rs[i],i==lim-1?'\n':' '),iv[i]=0;
	if((n&(-n))!=n) return puts("-1"),void();
	for(int i=0;i<lim;i++) for(int j=0;j<n;j++) if((i>>j)&1) iv[rs[i]]^=j;
	for(int i=0;i<lim;i++) printf("%d%c",iv[i],i==lim-1?'\n':' ');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}