#include<bits/stdc++.h>
using namespace std;
int tp,head[222222],nxt[444444],to[444444],cnt,deg[222222],n,m,x,y,Cur[222222],b[222222],a[222222],all,cntu,cntd,c1,c2,cur[222222],anp[222222],cnp,ac;
bool used[444444];
map<int,int> mp;
void addedge(int x,int y)
{
	++cnt;
	nxt[cnt]=head[x];head[x]=cnt;
	to[cnt]=y;
}
stack<int> s,num,ans;
void out()
{
	printf("-1\n");
	exit(0);
}
void solve()
{
	c1=c2=-1;
	for (int i=1;i<=all;i++)
	{
		if (deg[i]&1)
		{
			if (!~c1) c1=i;
			else if (!~c2) c2=i;
			else out();
		}
	}
	if (~c1)
	{
		addedge(c1,c2);
		addedge(c2,c1);
		deg[c1]++;deg[c2]++;
	}
	for (int i=1;i<=all;i++) cur[i]=head[i];
	for (int i=1;i<=all;i++)
	{
		if (deg[i]) 
		{
			s.push(i);
			break; 
		}
	}
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
	if (!~c1)
	{
		if (ans.size()!=n) out();
		else
		{
			if (ans.top()<0) ac=Cur[b[-ans.top()]];
			else ac=Cur[a[ans.top()]];
			while(!ans.empty())
			{
				if (ans.top()<0) printf("%d ",Cur[b[-ans.top()]]);
				else printf("%d ",Cur[a[ans.top()]]);
				ans.pop();
			}
			printf("%d\n",ac);
		}
	}
	else
	{
		if (ans.size()!=n+1) out();
		else
		{
			while(!ans.empty())
			{
				anp[++cnp]=ans.top();
				ans.pop();
			}
			int fp=0;
			for (int i=1;i<=n+1;i++)
			{
				if (anp[i]==n+1 || anp[i]==-n-1) 
				{
					fp=i;
					break;
				}
			}
			for (int i=fp+1;i<=n+1;i++)
			{
				if (anp[i]<0) printf("%d ",Cur[b[-anp[i]]]);
				else printf("%d ",Cur[a[anp[i]]]);
			}
			for (int i=1;i<fp;i++)
			{
				if (anp[i]<0) printf("%d ",Cur[b[-anp[i]]]);
				else printf("%d ",Cur[a[anp[i]]]);
			}
			if (anp[fp]==n+1) printf("%d\n",Cur[c1]);
			else printf("%d\n",Cur[c2]);
		}
	}
	
}
int main()
{
	scanf("%d",&n);n--;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
	{
		if (a[i]>b[i]) out();
	}
	for (int i=1;i<=n;i++) Cur[i]=a[i];
	for (int i=1;i<=n;i++) Cur[n+i]=b[i];
	sort(Cur+1,Cur+n*2+1);
	all=unique(Cur+1,Cur+n*2+1)-Cur-1;
	for (int i=1;i<=all;i++) mp[Cur[i]]=i;
	for (int i=1;i<=n;i++) a[i]=mp[a[i]]; 
	for (int i=1;i<=n;i++) b[i]=mp[b[i]]; 
	cnt=1;
	for (int i=1;i<=n;i++)
	{
		addedge(a[i],b[i]);
		addedge(b[i],a[i]);
		deg[a[i]]++;deg[b[i]]++;
	}
	solve();
	return 0;
}