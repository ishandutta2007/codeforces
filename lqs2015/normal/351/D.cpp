#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,a[111111],nex[111111],bod[111111],ind[111111],sz,m,x,y,ans[111111];
int bit1[222222],bit2[222222];
vector<pair<int,int> > que[111111];
void add(int p,int x,int *bit)
{
	while(p<=sz)
	{
		*(bit+p)+=x;
		p+=p&(-p);
	}
}
int get(int p,int *bit)
{
	int res=0;
	while(p>=1)
	{
		res+=*(bit+p);
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=100000;i++) ind[i]=1e9;
	for (int i=n;i>=1;i--)
	{
		nex[i]=ind[a[i]];
		ind[a[i]]=i;
	}
	for (int i=n;i>=1;i--)
	{
		if (nex[i]==1e9) bod[i]=n+1;
		else if (nex[i]-i==nex[nex[i]]-nex[i]) bod[i]=bod[nex[i]];
		else 
		{
			bod[i]=nex[nex[i]];
			if (bod[i]==1e9) bod[i]=n+1;
		}
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		que[x].push_back(make_pair(y,i)); 
	}
	sz=1;
	while(sz<n+2) sz*=2;
	for (int i=n;i>=1;i--)
	{
		add(i,1,bit1);
		if (nex[i]!=1e9) add(nex[i],-1,bit1);
		add(i,1,bit2);
		add(bod[i],-1,bit2);
		if (nex[i]!=1e9)
		{
			add(nex[i],-1,bit2);
			add(bod[nex[i]],1,bit2);
		}
		for (int j=0;j<que[i].size();j++)
		{
			int r=que[i][j].first,id=que[i][j].second;
			ans[id]=get(r,bit1);
			if (!get(r,bit2)) ans[id]++;
		}
	}
	for (int i=1;i<=m;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}