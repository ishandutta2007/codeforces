#include<bits/stdc++.h>
using namespace std;
int test,n,y,c,arr[4444],cr,brr[4444],crt;
int ar[]={-1,1,1,1,3,5,5,7,9,11,13,15,15};
vector<int> v[4444],candidate;
bool vis[4444],f;
int ask(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&y);
	for (int i=1;i<=y;i++)
	{
		scanf("%d",&c);
		v[x].push_back(c);
	}
	return y;
}
void confirm(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	f=1;
}
void dfs(int i)
{
	vis[i]=1;brr[++crt]=i;
	if (ask(i)==2)
	{
		confirm(i);
		return;
	}
	for (int j=0;j<v[i].size();j++)
	{
		int to=v[i][j];
		if (vis[to]) continue;
		dfs(to);
		return;
	}
}
void dft(int i,int dep)
{
	vis[i]=1;
	if (dep==1)
	{
		candidate.push_back(i);
		return;
	}
	if (ask(i)==2) 
	{
		confirm(i);
		return;
	}
	for (int j=0;j<v[i].size();j++)
	{
		int to=v[i][j];
		if (vis[to]) continue;
		dft(to,dep-1);
	}
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<(1<<n);i++) v[i].clear();
		memset(vis,0,sizeof(vis));
		vis[1]=1;f=0;
		int t=ask(1);
		if (t==2) 
		{
			confirm(1);
			continue;
		}
		if (t==1)
		{
			cr=1;
			arr[cr]=1;
		}
		else
		{
			crt=cr=0;
			dfs(v[1][0]);
			if (f) continue;
			for (int i=crt;i>=1;i--) arr[++cr]=brr[i];
			crt=0;arr[++cr]=1;
			dfs(v[1][1]);
			for (int i=1;i<=crt;i++) arr[++cr]=brr[i];
			if (f) continue;
		}
		while(1)
		{
			if (cr==2*n-1)
			{
				confirm(arr[n]);
				break;
			}
			if (cr>=ar[n]) 
			{
				int t,cu=arr[(cr+1)/2];
				for (int i=0;i<v[cu].size();i++)
				{
					if (!vis[v[cu][i]]) 
					{
						t=v[cu][i];
						break;
					}
				}
				candidate.clear();
				dft(t,(2*n-1-cr)/2);
				for (int i=0;i<(int)candidate.size()-1;i++)
				{
					if (ask(candidate[i])==2) 
					{
						confirm(candidate[i]);
						f=1;
						break;
					}
				}
				if (!f) confirm(candidate.back());
				break;
			}
			int t,cu=arr[(cr+1)/2];
			for (int i=0;i<v[cu].size();i++)
			{
				if (!vis[v[cu][i]]) 
				{
					t=v[cu][i];
					break;
				}
			}
			crt=0;
			dfs(t);cr=(cr+1)/2;
			for (int i=1;i<=crt;i++) arr[++cr]=brr[i];
			if (f) break;
		}
	}
	return 0;
}