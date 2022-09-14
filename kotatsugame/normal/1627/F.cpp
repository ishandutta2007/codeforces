#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int T,N,K;
int yokod[501][501];
int tated[501][501];
int dist[501][501];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<=K;i++)
		{
			for(int j=0;j<=K;j++)
			{
				yokod[i][j]=0;
				tated[i][j]=0;
				dist[i][j]=1e9;
			}
		}
		for(int i=0;i<N;i++)
		{
			int a,b,c,d;cin>>a>>b>>c>>d;
			a--,b--,c--,d--;
			if(a!=c)
			{
				if(a>c)swap(a,c);
				tated[c][b]++;
				a=K-1-a;
				b=K-1-b;
				c=K-1-c;
				swap(a,c);
				tated[c][b]++;
			}
			else
			{
				if(b>d)swap(b,d);
				yokod[a][d]++;
				a=K-1-a;
				b=K-1-b;
				d=K-1-d;
				swap(b,d);
				yokod[a][d]++;
			}
		}
		dist[0][0]=0;
		priority_queue<pair<int,pair<int,int> > >P;
		P.push(make_pair(0,make_pair(0,0)));
		while(!P.empty())
		{
			int c=-P.top().first;
			int x=P.top().second.first,y=P.top().second.second;
			P.pop();
			if(dist[x][y]<c)continue;
			if(x<K)
			{
				int tx=x+1,ty=y;
				int nc=c+yokod[x][y];
				if(dist[tx][ty]>nc)
				{
					dist[tx][ty]=nc;
					P.push(make_pair(-nc,make_pair(tx,ty)));
				}
			}
			if(x>0)
			{
				int tx=x-1,ty=y;
				int nc=c+yokod[x-1][y];
				if(dist[tx][ty]>nc)
				{
					dist[tx][ty]=nc;
					P.push(make_pair(-nc,make_pair(tx,ty)));
				}
			}
			if(y<K)
			{
				int tx=x,ty=y+1;
				int nc=c+tated[x][y];
				if(dist[tx][ty]>nc)
				{
					dist[tx][ty]=nc;
					P.push(make_pair(-nc,make_pair(tx,ty)));
				}
			}
			if(y>0)
			{
				int tx=x,ty=y-1;
				int nc=c+tated[x][y-1];
				if(dist[tx][ty]>nc)
				{
					dist[tx][ty]=nc;
					P.push(make_pair(-nc,make_pair(tx,ty)));
				}
			}
		}
		cout<<N-dist[K/2][K/2]<<"\n";
	}
}