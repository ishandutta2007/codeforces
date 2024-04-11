#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<vector>
#define next next2
using namespace std;
const int MAXN=500010;
int n,m,p[MAXN],a[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
int BIT[MAXN];
char str[MAXN];
struct PII
{
	int first,second,id;
}Q[MAXN];
vector<int> v[MAXN];
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
inline void Change(int x,int tar)
{
	for(int i=x;i<=n;i+=(i&(-i)))
		BIT[i]^=tar;
}
inline int Query(int x)
{
	int con=0;
	for(int i=x;i;i^=(i&(-i)))
		con^=BIT[i];
	return con;
}
bool cmp(const PII &p,const PII &q)
{
	return p.second<q.second;
}
int L[MAXN],R[MAXN],dep[MAXN],dfs_clock;
void DFS(int x)
{
	v[dep[x]].push_back(x);
	L[x]=++dfs_clock;
	for(int i=head[x];i;i=next[i])
	{
		dep[to[i]]=dep[x]+1;
		DFS(to[i]);
	}
	R[x]=dfs_clock;
}
int now;
bool ans[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++) scanf("%d",&p[i]),adde(p[i],i);
	scanf("%s",str);
	for(int i=1;i<=n;i++) a[i]|=(1<<(str[i-1]-'a'));
	for(int i=1;i<=m;i++) scanf("%d%d",&Q[i].first,&Q[i].second),Q[i].id=i;
	sort(Q+1,Q+m+1,cmp);
	dep[1]=1;
	DFS(1);
	for(int i=1;i<=m;i++)
	{
		while(Q[i].second!=now)
		{
			for(int i=0;i<v[now].size();i++)
				Change(L[v[now][i]],a[v[now][i]]);
			now++;
			for(int i=0;i<v[now].size();i++)
				Change(L[v[now][i]],a[v[now][i]]);
		}
		int x=Query(L[Q[i].first]-1)^Query(R[Q[i].first]);
		int res=0;
		for(int k=0;k<26;k++)
			if(x&(1<<k)) res++;
		if(res<=1) ans[Q[i].id]=true;
	}
	for(int i=1;i<=m;i++)
		if(ans[i]) puts("Yes");
		else puts("No");
	return 0;
}