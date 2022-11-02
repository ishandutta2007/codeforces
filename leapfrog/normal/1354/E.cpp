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
int n,m,et,head[5005],n1,n2,n3,rs[5005][2],rt[2];struct edge{int to,nxt;}e[200005];
int cl[5005],cn[5005][2],cnt,id[5005];char pt[5005],ans[5005];bitset<5005>dp[5005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void col(int x,int cl) {cn[cnt][cl]++,::cl[x]=cl;}
inline void dfs(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt)
		if(!~cl[e[i].to]) col(e[i].to,!cl[x]),dfs(e[i].to,x);
		else if(cl[e[i].to]==cl[x]) puts("NO"),exit(0);
}
inline void pullout(int x,int c)
{
	if(pt[x]) return;else pt[x]=1,rs[++rt[c^cl[x]]][c^cl[x]]=x;
	for(int i=head[x];i;i=e[i].nxt) pullout(e[i].to,c);
}
int main()
{
	read(n),read(m),read(n1),read(n2),read(n3),memset(cl,-1,sizeof(cl));
	for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y),adde(y,x);
	for(int i=1;i<=n;i++) if(!~cl[i]) id[++cnt]=i,col(i,0),dfs(i,0);
	dp[0][0]=1;for(int i=1;i<=cnt;i++) dp[i]=dp[i-1]<<cn[i][0]|dp[i-1]<<cn[i][1];
	//for(int i=1;i<=cnt;i++) printf("%d : %d , %d\n",id[i],cn[i][0],cn[i][1]);
	if(!dp[cnt][n2]) return puts("NO"),0;
	for(int i=cnt,w=n2;i;i--)
		if(w-cn[i][0]<0||!dp[i-1][w-cn[i][0]]) pullout(id[i],1),w-=cn[i][1];
		else pullout(id[i],0),w-=cn[i][0];
	//for(int i=1;i<=rt[0];i++) printf("%d%c",rs[i][0],i==rt[0]?'\n':' ');
	//for(int i=1;i<=rt[1];i++) printf("%d%c",rs[i][1],i==rt[1]?'\n':' ');
	for(int i=1;i<=n1;i++) ans[rs[i][1]]='1';
	for(int i=n1+1;i<=n1+n3;i++) ans[rs[i][1]]='3';
	for(int i=1;i<=n2;i++) ans[rs[i][0]]='2';
	return printf("YES\n%s\n",ans+1),0;
}