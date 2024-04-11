#include <iostream>
using namespace std;
const int inf=1<<29;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
char s[1005][1005];
int x[1000005],y[1000005];
int dist[1005][1005];

int main()
{
	int m,n,i,j;
	cin>>m>>n;
	for(i=0;i<m;i++)
	{
		cin>>s[i];
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			dist[i][j]=inf;
			if(s[i][j]=='E')
			{
				x[1]=i;
				y[1]=j;
				dist[i][j]=0;
			}
		}
	}
	int b=1,e=1;
	while(b<=e)
	{
		for(i=0;i<4;i++)
		{
			int xk=x[b]+dx[i];
			int yk=y[b]+dy[i]; 
			if(xk>=0 && yk>=0 && xk<m && yk<n)
			{
				if(s[xk][yk]!='T' && dist[xk][yk]==inf)
				{
					e++;
					x[e]=xk;
					y[e]=yk;
					dist[xk][yk]=dist[x[b]][y[b]]+1;
				}
			}
		}
		b++;
	}
	int thr=-1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(s[i][j]=='S') thr=dist[i][j];
		}
	}
	int ans=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(s[i][j]>='0'&& s[i][j]<='9')
			{
				if(dist[i][j]<=thr) ans+=s[i][j]-'0';
				
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}