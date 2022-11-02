#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int x,y;}e[100005];
int n,m,h,t,dg[100005],tz[100005],s[100005];vector<int>v[100005];char vs[100005];
inline void adde(int x,int y) {v[x].push_back(y),v[y].push_back(x),dg[x]++,dg[y]++;}
inline void chck(int x,int y)
{
	int T=t,H=h;if(dg[x]<=H||dg[y]<=T) return;
	if(dg[x]>H+T)
	{
		puts("YES"),printf("%d %d\n",x,y);int cnt=0;
		for(int i=0;i<(int)v[y].size()&&T;i++) if(v[y][i]!=x) tz[++cnt]=v[y][i],vs[v[y][i]]=1,T--;
		for(int i=0;i<(int)v[x].size()&&H;i++) if(v[x][i]!=y&&!vs[v[x][i]]) printf("%d ",v[x][i]),H--;
		putchar('\n');for(int i=1;i<=cnt;i++) printf("%d ",tz[i]);
		putchar('\n'),exit(0);
	}
	if(dg[y]>H+T)
	{
		puts("YES"),printf("%d %d\n",x,y);
		for(int i=0;i<(int)v[x].size()&&H;i++) if(v[x][i]!=y) printf("%d ",v[x][i]),vs[v[x][i]]=1,H--;
		for(int i=0;i<(int)v[y].size()&&T;i++) if(v[y][i]!=x&&!vs[v[y][i]]) printf("%d ",v[y][i]),T--;
		exit(0);
	}
	int cnt=0;for(int i=0;i<(int)v[y].size();i++) if(v[y][i]!=x) s[v[y][i]]=1,cnt++;
	for(int i=0;i<(int)v[x].size();i++) if(v[x][i]!=y&&!s[v[x][i]]) cnt++;
	if(cnt<H+T) {for(int i=0;i<(int)v[y].size();i++) s[v[y][i]]=0;return;}else puts("YES"),printf("%d %d\n",x,y);
	for(int i=0;i<(int)v[x].size()&&H;i++) if(v[x][i]!=y&&!s[v[x][i]]) printf("%d ",v[x][i]),H--;
	for(int i=0;i<(int)v[x].size()&&H;i++) if(v[x][i]!=y&&s[v[x][i]]) printf("%d ",v[x][i]),H--,s[v[x][i]]=0;
	putchar('\n');for(int i=0;i<(int)v[y].size()&&T;i++) if(v[y][i]!=y&&s[v[y][i]]) printf("%d ",v[y][i]),T--;
	putchar('\n'),exit(0);
}
int main()
{
	read(n),read(m),read(h),read(t),memset(dg,0,sizeof(dg));
	for(int i=1;i<=m;i++) read(e[i].x),read(e[i].y),adde(e[i].x,e[i].y);
	random_shuffle(e+1,e+m+1);
	for(int i=1;i<=m;i++) chck(e[i].x,e[i].y),chck(e[i].y,e[i].x);
	return puts("NO"),0;
}