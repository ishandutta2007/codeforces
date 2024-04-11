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
int n=20,m,mp[21],fa[21],F[1<<20];char S[100005],T[100005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
inline int count(int x) {int r=0;for(int i=0;i<n;i++) r+=(x>>i)&1;return r;}
inline char dfs(int S)
{
	if(~F[S]) return F[S];else if(!S) return F[S]=1;else F[S]=0;
	for(int i=0;i<n;i++) if((S>>i)&1&&!(mp[i]&S)) F[S]|=dfs(S^(1<<i));
	return F[S];
}
inline void solve()
{
	read(m),scanf("%s%s",S+1,T+1);for(int i=0;i<n;i++) fa[i]=i,mp[i]=0;
	for(int i=1;i<=m;i++) if(S[i]^T[i]) mp[S[i]-'a']|=1<<(T[i]-'a'),mrg(S[i]-'a',T[i]-'a');
	int rs=n*2;memset(F,-1,sizeof(F));for(int i=0;i<n;i++) rs-=getf(i)==i;
	int mx=0;for(int i=0;i<(1<<n);i++) if(dfs(i)) mx=max(mx,count(i));
	printf("%d\n",rs-mx);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}