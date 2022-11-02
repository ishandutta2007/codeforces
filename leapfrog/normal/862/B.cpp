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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005;
struct edge{int to,nxt;}e[N];int n,et,head[N],cl[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa) {cl[x]=cl[fa]^1;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x);}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	int cn[2]={0,0};dfs(1,0);for(int i=1;i<=n;i++) cn[cl[i]]++;
	return printf("%lld\n",1ll*cn[0]*cn[1]-n+1),0;
}