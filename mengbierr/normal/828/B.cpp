#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=(f<<1)+(f<<3)+ch-'0';
	ch=getchar();}
	return f;
}
bool a[105][105];int minx=200000,maxx=0,miny=200000,maxy=0,tot;
int main()
{
	int n=read(),m=read();char c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c;
			if(c=='W')
			a[i][j]=0;
			else a[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])
			{
				minx=min(minx,i);
				miny=min(miny,j);
				maxx=max(maxx,i);
				maxy=max(maxy,j);
				tot++;
			}
		}
		
	}
	int x=max(maxx-minx,maxy-miny);
	if(!tot)
	printf("%d",1);
	else if(x+1>m||x+1>n)
	printf("-1");
	else
	{
		int ans=(x+1)*(x+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j])
				ans--;
			}
		}
		cout<<ans;
	}
}