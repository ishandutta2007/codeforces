#include<iostream> 
#include<vector>
#include<queue>
using namespace std;
int n=0,r1=0,c1=0,r2=0,c2=0;
vector <int> v;
int d[105][100005]={0};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
const int INF=1000000009;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	int ma=-1;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
		ma=max(ma,x);
	}
	cin>>r1>>c1>>r2>>c2;
	queue <pair<int,int> > q;
	for(int i=0;i<n;i++)
	    for(int j=0;j<=ma;j++)
	        d[i][j]=INF;
	q.push(make_pair(r1-1,c1-1));
	d[r1-1][c1-1]=0;
	while(q.size())
	{
		int a=q.front().first;
		int b=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=a+dx[i],ny=b+dy[i];
			if(nx>=n||nx<0||ny<0)
			    continue;
			if(i==0||i==1)
			    ny=min(ny,v[nx]);
			if(d[nx][ny]>d[a][b]+1)
			{
				d[nx][ny]=d[a][b]+1;
				q.push(make_pair(nx,ny));
			}    
		}	
	}
	cout<<d[r2-1][c2-1];
	return 0;
}