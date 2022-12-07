#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1000010;
int n,m,col[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
vector<int> v[2];
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x)
{
	for(int i=head[x];i;i=next[i])
	{
		if(col[to[i]]!=-1&&col[to[i]]==col[x]) {puts("-1");exit(0);}
		if(col[to[i]]==-1) col[to[i]]=col[x]^1,DFS(to[i]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y);
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n;i++)
		if(col[i]==-1) col[i]=0,DFS(i);
	for(int i=1;i<=n;i++) v[col[i]].push_back(i);
	printf("%d\n",(int)v[0].size());
	for(int i=0;i<v[0].size();i++)
		printf("%d ",v[0][i]);
	printf("\n%d\n",(int)v[1].size());
	for(int i=0;i<v[1].size();i++)
		printf("%d ",v[1][i]);
	return 0;
}