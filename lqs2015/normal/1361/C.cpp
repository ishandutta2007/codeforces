#include<bits/stdc++.h>
using namespace std;
int n,a[555555],b[555555],id[1111111],cnt,msk,all,head[1111111],nxt[1111111],to[1111111],deg[1111111];
int x,y,cur[1111111];
bool used[1111111];
void addedge(int x,int y)
{
	++all;
	nxt[all]=head[x];head[x]=all;
	to[all]=y;
}
stack<int> s,num,ans;
void solve1(int kk)
{
	all=1;memset(deg,0,sizeof(deg));
	for (int i=1;i<=n;i++)
	{
		x=id[a[i]&msk];y=id[b[i]&msk];
		addedge(x,y);
		addedge(y,x);
		deg[x]++;
		deg[y]++;
	}
	while(!s.empty()) s.pop();
	while(!num.empty()) num.pop();
	while(!ans.empty()) ans.pop();
	for (int i=1;i<=cnt;i++)
	{
		if (deg[i]&1) return;
	}
	for (int i=1;i<=cnt;i++) cur[i]=head[i];
	for (int i=1;i<=cnt;i++)
	{
		if (deg[i]) 
		{
			s.push(i);
			break; 
		}
	}
	memset(used,0,sizeof(used));
	while(!s.empty())
	{
		int x=s.top();
		while(used[cur[x]]) cur[x]=nxt[cur[x]];
		if (!cur[x])
		{
			s.pop();
			if (!num.empty())
			{
				ans.push(num.top());
				num.pop(); 
			}
			continue;
		}
		s.push(to[cur[x]]);
		num.push(cur[x]&1 ? -cur[x]/2 : cur[x]/2);
		used[cur[x]]=used[cur[x]^1]=1; 
	}
	if (ans.size()!=n) return;
	else
	{
		printf("%d\n",kk);
		while(!ans.empty())
		{
			x=ans.top();
			if (x<0)
			{
				x=-x;
				printf("%d %d ",2*x,2*x-1);
			}
			else
			{
				printf("%d %d ",2*x-1,2*x);
			}
			ans.pop();
		}
		printf("\n");
		exit(0);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	memset(id,-1,sizeof(id));
	for (int i=20;i>=1;i--)
	{
		cnt=0;msk=(1<<i)-1;
		for (int j=1;j<=n;j++)
		{
			if (!~id[a[j]&msk]) id[a[j]&msk]=++cnt;
			if (!~id[b[j]&msk]) id[b[j]&msk]=++cnt;
		}
		solve1(i);
		memset(nxt,0,sizeof(nxt));memset(head,0,sizeof(head));
		for (int j=1;j<=n;j++) 
		{
			id[a[j]&msk]=id[b[j]&msk]=-1;
		}
	}
	printf("0\n");
	for (int i=1;i<=2*n;i++) printf("%d ",i);
	printf("\n");
	return 0;
}