#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
typedef long long LL;
const int MAXN=200010;
int n,m,x,y;
pair<int,int> A[MAXN];
int col[MAXN],c[MAXN],b[MAXN],w[MAXN],col_tot;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
bool ok;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x,int C)
{
	col[x]=C;
	if(c[x]==0) b[C]++;
	else w[C]++;
	for(int i=head[x];i;i=next[i])
		if(!col[to[i]])
		{
			c[to[i]]=c[x]^1;
			DFS(to[i],C);
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y),A[i]=make_pair(x,y);
	for(int i=1;i<=n;i++)
	if(!col[i]) DFS(i,++col_tot);
	for(int i=1;i<=m;i++)
		if(col[A[i].first]==col[A[i].second]&&c[A[i].first]==c[A[i].second])
			{puts("0 1");return 0;}
	ok=false;
	for(int i=1;i<=col_tot;i++)
		if(b[i]+w[i]>=3) ok=true;
	if(ok)
	{
		LL ans=0;
		for(int i=1;i<=col_tot;i++)
			ans+=(LL)b[i]*(LL)(b[i]-1)/2LL+(LL)w[i]*(LL)(w[i]-1)/2LL;
		printf("1 %I64d\n",ans);
		return 0;
	}
	ok=false;
	for(int i=1;i<=col_tot;i++)
		if(b[i]+w[i]>=2) ok=true;
	if(ok)
	{
		LL ans=0;
		for(int i=1;i<=col_tot;i++)
			if(b[i]+w[i]>=2) ans+=(LL)(n-2);
		printf("2 %I64d\n",ans);
		return 0;
	}
	LL ans=(LL)n*(LL)(n-1)*(LL)(n-2)/6LL;
	printf("3 %I64d\n",ans);
	return 0;
}