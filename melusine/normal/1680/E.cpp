#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dq[200005][2],dh[200005][2];
char s[2][200005];
int main()
{
	int t,n,minx,maxx;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s[0]+1);
		scanf("%s",s[1]+1);
		minx=1;
		while(minx<=n&&s[0][minx]=='.'&&s[1][minx]=='.')minx++;
		maxx=n;
		while(maxx>=1&&s[0][maxx]=='.'&&s[1][maxx]=='.')maxx--;
		if(s[0][minx]=='*'&&s[1][minx]=='*')
		{
			dq[minx][0]=dq[minx][1]=1;
		}
		else if(s[0][minx]=='*')
		{
			dq[minx][0]=0;
			dq[minx][1]=1;
		}
		else
		{
			dq[minx][0]=1;
			dq[minx][1]=0;
		}
		//printf("%d %d %d\n",minx,dq[minx][0],dq[minx][1]);
		for(int i=minx+1;i<=maxx;i++)
		{
			if(s[0][i]=='.'&&s[1][i]=='.')
			{
				dq[i][0]=min(dq[i-1][0]+1,dq[i-1][1]+2);
				dq[i][1]=min(dq[i-1][1]+1,dq[i-1][0]+2);
			}
			else if(s[0][i]=='.')
			{
				dq[i][0]=min(dq[i-1][0]+2,dq[i-1][1]+2);
				dq[i][1]=min(dq[i-1][1]+1,dq[i-1][0]+2);
			}
			else if(s[1][i]=='.')
			{
				dq[i][0]=min(dq[i-1][0]+1,dq[i-1][1]+2);
				dq[i][1]=min(dq[i-1][1]+2,dq[i-1][0]+2);
			}
			else
			{
				dq[i][0]=min(dq[i-1][0]+2,dq[i-1][1]+2);
				dq[i][1]=min(dq[i-1][1]+2,dq[i-1][0]+2);
			}
			//printf("%d %d %d\n",i,dq[i][0],dq[i][1]);
		}
		if(s[0][maxx]=='*'&&s[1][maxx]=='*')
		{
			dh[maxx][0]=dh[maxx][1]=1;
		}
		else if(s[0][maxx]=='*')
		{
			dh[maxx][0]=0;
			dh[maxx][1]=1;
		}
		else
		{
			dh[maxx][0]=1;
			dh[maxx][1]=0;
		}
		for(int i=maxx-1;i>=minx;i--)
		{
			if(s[0][i]=='.'&&s[1][i]=='.')
			{
				dh[i][0]=min(dh[i+1][0]+1,dh[i+1][1]+2);
				dh[i][1]=min(dh[i+1][1]+1,dh[i+1][0]+2);
			}
			else if(s[0][i]=='.')
			{
				dh[i][0]=min(dh[i+1][0]+2,dh[i+1][1]+2);
				dh[i][1]=min(dh[i+1][1]+1,dh[i+1][0]+2);
			}
			else if(s[1][i]=='.')
			{
				dh[i][0]=min(dh[i+1][0]+1,dh[i+1][1]+2);
				dh[i][1]=min(dh[i+1][1]+2,dh[i+1][0]+2);
			}
			else
			{
				dh[i][0]=min(dh[i+1][0]+2,dh[i+1][1]+2);
				dh[i][1]=min(dh[i+1][1]+2,dh[i+1][0]+2);
			}
			//printf("%d %d %d\n",i,dh[i][0],dh[i][1]);
		}
		int ans=1000000000;
		for(int i=minx;i<=maxx-1;i++)
		{
			ans=min(ans,dq[i][0]+dh[i+1][0]+1);
			ans=min(ans,dq[i][1]+dh[i+1][1]+1);
		}
		if(minx==maxx)
		{
			if(s[0][minx]=='*'&&s[1][minx]=='*')ans=1;
			else ans=0;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)dq[i][0]=dq[i][1]=dh[i][0]=dh[i][1]=0;
	}
	return 0;
}