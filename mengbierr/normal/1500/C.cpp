#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
queue<int> q;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int a[1505][1505],b[1505][1505],inv[1505][1505],n,m,num[1505],ok[1505];
int ans[5005],cnt,cou[1505],rk[1505],id[1505];
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) a[i][j]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) b[i][j]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]<b[i-1][j]) inv[i][j]=1,num[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(!num[i]) q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		//cout<<x<<endl;
		ans[++cnt]=x;
		for(int i=1;i<=n;i++)
		{
			if(b[i][x]>b[i-1][x]&&!ok[i])
			{
				ok[i]=1;
				for(int j=1;j<=m;j++)
				{
					if(inv[i][j])
					{
						inv[i][j]=0;
						num[j]--;
						if(!num[j]) q.push(j);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		id[i]=i;rk[i]=i;
	}
	for(int i=cnt;i;i--)
	{
		//cout<<ans[i]<<" ";
		memset(cou,0,sizeof(cou));
		for(int j=1;j<=n;j++)
		{
			cou[a[j][ans[i]]]++;
		}
		for(int j=1;j<=n;j++) cou[j]+=cou[j-1];
		for(int j=n;j;j--)
		{
			rk[id[j]]=cou[a[id[j]][ans[i]]]--;
		}
		for(int j=1;j<=n;j++) id[rk[j]]=j;
		//cout<<endl;
	}
	bool ok=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[id[i]][j]!=b[i][j]) ok=0;
		}
	}
	if(!ok) puts("-1");
	else
	{
		cout<<cnt<<endl;
		for(int i=cnt;i;i--)
		printf("%d ",ans[i]);
	}
}