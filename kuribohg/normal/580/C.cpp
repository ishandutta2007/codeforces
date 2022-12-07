#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
typedef long long LL;
const int MAXN=1000010;
int n,k,a[MAXN],s[MAXN],d[MAXN],fa[MAXN],ans;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x,int f)
{
	for(int i=head[x];i;i=next[i])
		if(to[i]!=f)
		{
			fa[to[i]]=x;
			if(a[to[i]]) s[to[i]]+=s[x];
			else s[to[i]]=0;
			DFS(to[i],x);
		}
}
void DFS2(int x,int f)
{
	for(int i=head[x];i;i=next[i])
		if(to[i]!=f)
		{
			s[to[i]]=max(s[to[i]],s[x]);
			DFS2(to[i],x);
		}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=a[i];
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y),d[x]++,d[y]++;
	DFS(1,-1);
	DFS2(1,-1);
	for(int i=2;i<=n;i++)
		if(d[i]==1&&s[i]<=k) ans++;
	printf("%d\n",ans);
	return 0;
}