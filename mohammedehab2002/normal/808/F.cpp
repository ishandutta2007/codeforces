#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int mat[105][105],rmat[105][105],n,k;
int par[105];
bool vis[105];
vector<int> v[105];
int arr[105][3];
bool bfs(int s,int t)
{
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int cur=q.front();
		q.pop();
		if (cur==t)
		return 1;
		vis[cur]=1;
		for (int i=0;i<v[cur].size();i++)
		{
			if (!vis[v[cur][i]] && rmat[cur][v[cur][i]]>0)
			{
				q.push(v[cur][i]);
				par[v[cur][i]]=cur;
			}
		}
	}
	return 0;
}
int maxFlow(int s,int t)
{
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n;x++)
		rmat[i][x]=mat[i][x];
	}
	int ans=0;
	while (bfs(s,t))
	{
		int cur=t,flow=(1<<30);
		while (cur!=s)
		{
			flow=min(flow,rmat[par[cur]][cur]);
			cur=par[cur];
		}
		ans+=flow;
		cur=t;
		while (cur!=s)
		{
			rmat[par[cur]][cur]-=flow;
			rmat[cur][par[cur]]+=flow;
			cur=par[cur];
		}
	}
	return ans;
}
bool isprime(int x)
{
	for (int i=2;i*i<=x;i++)
	{
		if (x%i==0)
		return false;
	}
	return true;
}
bool check(int m)
{
	memset(mat,0,sizeof(mat));
	for (int i=0;i<n;i++)
	v[i].clear();
	vector<int> odd,even;
	int best1=-1,sum=0;
	for (int i=0;i<n;i++)
	{
		if (arr[i][2]<=m)
		{
			if (arr[i][1]==1)
			{
				if (best1==-1)
				best1=i;
				else if (arr[best1][0]<arr[i][0])
				best1=i;
			}
			else
			{
				if (arr[i][1]%2)
				odd.push_back(i);
				else
				even.push_back(i);
				sum+=arr[i][0];
			}
		}
	}
	if (best1!=-1)
	{
		odd.push_back(best1);
		sum+=arr[best1][0];
	}
	for (int i=0;i<odd.size();i++)
	{
		for (int x=0;x<even.size();x++)
		{
			if (isprime(arr[odd[i]][1]+arr[even[x]][1]))
			{
				v[odd[i]].push_back(even[x]);
				v[even[x]].push_back(odd[i]);
				mat[odd[i]][even[x]]=(1<<30);
			}
		}
	}
	for (int i=0;i<odd.size();i++)
	{
		v[n].push_back(odd[i]);
		v[odd[i]].push_back(n);
		mat[n][odd[i]]=arr[odd[i]][0];
	}
	for (int i=0;i<even.size();i++)
	{
		v[n+1].push_back(even[i]);
		v[even[i]].push_back(n+1);
		mat[even[i]][n+1]=arr[even[i]][0];
	}
	n+=2;
	bool b=((sum-maxFlow(n-2,n-1))>=k);
	n-=2;
	return b;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
	int st=0,en=n+1;
	while (st!=en)
	{
		int mid=(st+en)/2;
		if (check(mid))
		en=mid;
		else
		st=mid+1;
	}
	if (st==n+1)
	st=-1;
	printf("%d",st);
}