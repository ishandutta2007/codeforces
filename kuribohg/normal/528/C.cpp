#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<iterator>
using namespace std;
const int maxn=1000010;
int n,m,d[maxn],con,a[maxn],tot,ans[maxn],top;
multiset<int> head[maxn];
inline void adde(int f,int t)
{
	head[f].insert(t);
	head[t].insert(f);
}
void dfs(int x)
{
	while(!head[x].empty())
	{
		int i=(*head[x].begin());
		head[x].erase(head[x].begin());
		head[i].erase(head[i].find(x));
		dfs(i);
	}
	ans[++top]=x;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y),d[x]++,d[y]++,con++;
	for(int i=1;i<=n;i++) if(d[i]&1) a[++tot]=i;
	for(int i=1;i<=tot;i+=2) adde(a[i],a[i+1]),con++;
	if(con&1) con++;
	printf("%d\n",con);
	dfs(1);
	for(int i=1;i<top;i++)
		if(i&1) printf("%d %d\n",ans[i],ans[i+1]);
		else printf("%d %d\n",ans[i+1],ans[i]);
	if(!(top&1)) puts("1 1");
	return 0;
}