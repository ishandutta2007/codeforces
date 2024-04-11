#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
const int INF=1000000000;
int n,m,x,y,f[MAXN][2];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
void DFS(int x)
{
	for(int i=head[x];i;i=next[i]) DFS(to[i]);
	if(!head[x]) {f[x][0]=f[x][1]=1,m++;return;}
	f[x][0]=INF;
	for(int i=head[x];i;i=next[i])
	{
		f[x][0]=min(f[x][0],f[to[i]][1]);
		f[x][1]+=f[to[i]][0];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
	DFS(1);
	printf("%d %d\n",m+1-f[1][0],f[1][1]);
	return 0;
}