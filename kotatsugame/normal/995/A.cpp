#include<iostream>
#include<vector>
using namespace std;
int N,K;
vector<pair<int,pair<int,int> > >ans;
int A[4][50];
void mv(int x,int y,int z,int w)
{
	ans.push_back(make_pair(A[x][y],make_pair(z,w)));
	A[z][w]=A[x][y];
	A[x][y]=0;
}
main()
{
	cin>>N>>K;
	for(int i=0;i<4;i++)for(int j=0;j<N;j++)cin>>A[i][j];
	while(true)
	{
		for(int j=0;j<N;j++)
		{
			if(A[1][j]>0&&A[1][j]==A[0][j])
			{
				mv(1,j,0,j);
			}
			if(A[2][j]>0&&A[2][j]==A[3][j])
			{
				mv(2,j,3,j);
			}
		}
		int x=-1,y;
		bool fn=false;
		for(int j=0;j<N;j++)
		{
			if(A[1][j]==0)x=1,y=j;
			else fn=true;
			if(A[2][j]==0)x=2,y=j;
			else fn=true;
		}
		if(x==-1)
		{
			puts("-1");
			return 0;
		}
		if(!fn)break;
		if(x==1)
		{
			for(int j=y;j<N-1;j++)
			{
				if(A[1][j+1]>0)
				{
					mv(1,j+1,1,j);
				}
			}
			if(A[2][N-1]>0)
			{
				mv(2,N-1,1,N-1);
			}
			for(int j=N-2;j>=0;j--)
			{
				if(A[2][j]>0)
				{
					mv(2,j,2,j+1);
				}
			}
			if(y>0&&A[1][0]>0)
			{
				mv(1,0,2,0);
			}
			for(int j=1;j<y;j++)
			{
				if(A[1][j]>0)
				{
					mv(1,j,1,j-1);
				}
			}
		}
		else
		{
			for(int j=y;j>0;j--)
			{
				if(A[2][j-1]>0)
				{
					mv(2,j-1,2,j);
				}
			}
			if(A[1][0]>0)
			{
				mv(1,0,2,0);
			}
			for(int j=1;j<N;j++)
			{
				if(A[1][j]>0)
				{
					mv(1,j,1,j-1);
				}
			}
			if(y<N-1&&A[2][N-1]>0)
			{
				mv(2,N-1,1,N-1);
			}
			for(int j=N-2;j>y;j--)
			{
				if(A[2][j]>0)
				{
					mv(2,j,2,j+1);
				}
			}
		}
	}
	cout<<ans.size()<<endl;
	for(pair<int,pair<int,int> >p:ans)cout<<p.first<<" "<<p.second.first+1<<" "<<p.second.second+1<<"\n";
}