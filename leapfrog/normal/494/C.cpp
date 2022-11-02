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
// 5000 
// <= mx  -  <= mx-1 
//
// <=mx  k 
//
// dp  k 
// dp[x] 
//
typedef long double ld;const int N=100005;int n,m,a[N],bz[N][20],lg[N],st[N],tp,mx[5005];
struct ${int l,r;ld p;char operator<($ b) {return l<b.l||(l==b.l&&r>b.r);}}q[5005];
struct edge{int to,nxt;}e[5005];int et,head[5005];ld dp[5005][5005],zy[5005][2];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int qry(int l,int r) {int g=lg[r-l+1];return max(bz[l][g],bz[r-(1<<g)+1][g]);}
inline void dfs0(int x,int fa)
{
	mx[x]=qry(q[x].l,q[x].r);for(int i=head[x];i;i=e[i].nxt) dfs0(e[i].to,x);
	dp[x][0]=1-q[x].p;for(int i=0;i<=m;i++) zy[i][0]=zy[i][1]=1;
	for(int i=head[x];i;i=e[i].nxt) for(int j=0,y=e[i].to;j<=m;j++)
		zy[j][0]*=dp[y][min(j-mx[y]+mx[x]-1,m)],zy[j][1]*=dp[y][min(j-mx[y]+mx[x],m)];
	for(int i=0;i<=m;i++) dp[x][i]=(i?q[x].p*zy[i][0]:0)+(1-q[x].p)*zy[i][1];
	//for(int i=1;i<=m;i++) printf("%.5Lf %.5Lf\n",zy[i][0],zy[i][1]);
	//for(int i=0;i<=m;i++) printf("%.5Lf%c",dp[x][i],i==m?'\n':' ');
}
int main()
{
	read(n,m),lg[0]=-1;for(int i=1;i<=n;i++) read(a[i]),bz[i][0]=a[i],lg[i]=lg[i>>1]+1;
	q[++m]=($){1,n,0};for(int i=1;i<m;i++) read(q[i].l,q[i].r),scanf("%Lf",&q[i].p);
	for(int j=1;j<=20;j++) for(int i=1;i+(1<<(j-1))<=n;i++) bz[i][j]=max(bz[i][j-1],bz[i+(1<<(j-1))][j-1]);
	sort(q+1,q+m+1),tp=0;for(int i=1;i<=m;i++) {for(;tp&&q[st[tp]].r<q[i].l;tp--);adde(st[tp],i),st[++tp]=i;}
	//putchar('\n');for(int i=1;i<=m;i++) printf("%d %d\n",q[i].l,q[i].r);
	dfs0(1,0);ld rs=0;for(int i=0;i<=m;i++) rs+=(dp[1][i]-(i?dp[1][i-1]:0))*(mx[1]+i);
	return printf("%.10Lf\n",rs),0;
}