#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n,m,x,y,k,banned[MAXN],d[MAXN],c[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
bool used[MAXN];
double L,R,mid;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int q[MAXN],l,r;
bool check()
{
	l=1,r=0;
	for(int i=1;i<=n;i++) used[i]=false,c[i]=0;
	for(int i=1;i<=k;i++) q[++r]=banned[i],used[q[r]]=true;
	while(l<=r)
	{
		int x=q[l++];
		used[x]=true;
		for(int i=head[x];i;i=next[i])
			if(!used[to[i]])
			{
				c[to[i]]++;
				if((d[to[i]]-c[to[i]])*1.0/d[to[i]]<mid) q[++r]=to[i],used[to[i]]=true;
			}
	}
	for(int i=1;i<=n;i++) if(!used[i]) return true;
	return false;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++) scanf("%d",&banned[i]);
	for(int i=1;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y),d[x]++,d[y]++;
	R=1;
	for(int T=1;T<=40;T++)
	{
		mid=(L+R)/2;
		for(int i=1;i<=n;i++) c[i]=0;
		if(check()) L=mid;
		else R=mid;
	}
	mid=L;
	check();
	int tot=0;
	for(int i=1;i<=n;i++) if(!used[i]) ++tot;
	printf("%d\n",tot);
	for(int i=1;i<=n;i++) if(!used[i]) printf("%d ",i);
	puts("");
	return 0;
}