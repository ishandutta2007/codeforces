#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
string A[100];
bool vis[100][100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)vis[i][j]=false;
		int ans=0;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(!vis[i][j])
		{
			int c0=0,c1=0;
			int x=i,y=j;
			for(int r=0;r<4;r++)
			{
				if(!vis[x][y])
				{
					vis[x][y]=true;
					if(A[x][y]=='0')c0++;
					else c1++;
				}
				int tx=y,ty=N-x-1;
				x=tx,y=ty;
			}
			ans+=min(c0,c1);
		}
		cout<<ans<<"\n";
	}
}