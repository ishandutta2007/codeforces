//Coded by Kamiyama_Shiki on 2021.11.03 {{{
//
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
const int N=200005;char vs[N][2];int n,m,rs[N],rst;
struct edge{int to,nxt;}e[N<<1];int et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void solve()
{
	read(n,m),et=0;for(int i=1;i<=n;i++) vs[i][0]=vs[i][1]=head[i]=0;
	rst=0;for(int i=1,x,y;i<=m;i++) read(x,y),adde(x,y);
	for(int i=1;i<=n;i++) if(vs[i][1]) rs[++rst]=i;
	else for(int j=head[i];j;j=e[j].nxt) vs[e[j].to][vs[i][0]]=1;
	printf("%d\n",rst);for(int i=1;i<=rst;i++) printf("%d%c",rs[i],i==rst?'\n':' ');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}