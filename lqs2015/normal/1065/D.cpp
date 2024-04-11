#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,a[22][22],dist[5][111][22][22],num[5][111][22][22],x,d,y,z,ans,ansnum;
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
queue<pair<pair<int,int>,pair<int,int> > > q;
void upd(int x,int d,int y,int z,int dis,int nu,int del)
{
	if (y<1 || z<1 || y>n || z>n) return;
	if (a[y][z]==d) d++;
	if (!~dist[x][d][y][z]) 
	{
		dist[x][d][y][z]=dis;
		num[x][d][y][z]=nu+del;
		if (d>n*n) return;
		q.push(make_pair(make_pair(x,d),make_pair(y,z))); 
	}
	else if (dist[x][d][y][z]==dis) num[x][d][y][z]=min(num[x][d][y][z],nu+del);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=3;i++)
	{
		for (int p=1;p<=n*n+1;p++)
		{
			for (int j=1;j<=n;j++)
			{
				for (int k=1;k<=n;k++)
				{
					dist[i][p][j][k]=-1;
					num[i][p][j][k]=1e9;
				}
				
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if (a[i][j]==1)
			{
				dist[1][2][i][j]=dist[2][2][i][j]=dist[3][2][i][j]=0;
				num[1][2][i][j]=num[2][2][i][j]=num[3][2][i][j]=0;
				q.push(make_pair(make_pair(1,2),make_pair(i,j)));q.push(make_pair(make_pair(2,2),make_pair(i,j)));q.push(make_pair(make_pair(3,2),make_pair(i,j)));   
			}
		}
	}
	while(!q.empty())
	{
		x=q.front().first.first;d=q.front().first.second;y=q.front().second.first;z=q.front().second.second;
		q.pop();
		upd(1,d,y,z,dist[x][d][y][z]+1,num[x][d][y][z],1);
		upd(2,d,y,z,dist[x][d][y][z]+1,num[x][d][y][z],1);
		upd(3,d,y,z,dist[x][d][y][z]+1,num[x][d][y][z],1);
		if (x==1)
		{
			for (int i=0;i<8;i++)
			{
				int yy=y+dx[i],zz=z+dy[i];
				upd(x,d,yy,zz,dist[x][d][y][z]+1,num[x][d][y][z],0);
			}
		}
		else if (x==2)
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				{
					if (i==y || j==z) upd(x,d,i,j,dist[x][d][y][z]+1,num[x][d][y][z],0);
				}
			}
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				{
					if (i-j==y-z || i+j==y+z) upd(x,d,i,j,dist[x][d][y][z]+1,num[x][d][y][z],0);
				}
			}
		}
	}
	//cout<<dist[2][5][2][3]<<" "<<num[2][5][2][3]<<endl;
	ans=1e9;ansnum=1e9;
	for (int i=1;i<=3;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=n;k++)
			{
				if (dist[i][n*n+1][j][k]==-1) continue; 
				if (dist[i][n*n+1][j][k]<ans)
				{
					ans=dist[i][n*n+1][j][k];
					ansnum=num[i][n*n+1][j][k];
				}
				else if (dist[i][n*n+1][j][k]==ans)
				{
					ansnum=min(ansnum,num[i][n*n+1][j][k]);
				}
			}
		}
	}
	printf("%d %d\n",ans,ansnum);
	return 0;
}