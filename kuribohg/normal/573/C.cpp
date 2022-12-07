#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n,d[MAXN],legs[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
bool del[MAXN];
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x,int fa)
{
	del[x]=true;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa&&d[to[i]]<3) DFS(to[i],x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adde(x,y);
		d[x]++,d[y]++;
	}
	for(int i=1;i<=n;i++) if(d[i]==1) DFS(i,-1);
	for(int x=1;x<=n;x++)
		if(!del[x])
		{
			for(int i=head[x];i;i=next[i])
				if(del[to[i]]) legs[x]=min(legs[x]+1,2);
		}
	for(int x=1;x<=n;x++)
		if(!del[x])
		{
			int c=0;
			for(int i=head[x];i;i=next[i])
				if(!del[to[i]]&&d[to[i]]>legs[to[i]]+1) c++;
			if(c>2) {puts("No");return 0;}
		}
	puts("Yes");
	return 0;
}