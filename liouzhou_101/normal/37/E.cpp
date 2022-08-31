#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int MaxN=55;
const int MaxP=2510;

int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

int N,M;
char p[MaxN][MaxN];
int way[MaxN][MaxN],wayx[MaxP],wayy[MaxP],d[MaxN][MaxN];

priority_queue<pair<int,int> > v;

void init()
{
	cin>>N>>M;
	int tot=0;
	for (int i=1;i<=N;++i)
		for (int j=1;j<=M;++j)
		{
			cin>>p[i][j];
			way[i][j]=++tot;
			wayx[tot]=i;
			wayy[tot]=j;
		}
}

void work()
{
	int ans=1000000000;
	for (int i=1;i<=N;++i)
		for (int j=1;j<=M;++j)
		{
			for (int x=1;x<=N;++x)
				for (int y=1;y<=M;++y)
					d[x][y]=1000000000;
			d[i][j]=0;
			v.push(make_pair(0,way[i][j]));
			while (!v.empty())
			{
				int now=v.top().second,nowd=-v.top().first;
				v.pop();
				int nowx=wayx[now],nowy=wayy[now];
				int dis=d[nowx][nowy];
				if (nowd!=dis) continue;
				for (int k=0;k<4;++k)
				{
					int tmpx=nowx+dx[k];
					int tmpy=nowy+dy[k];
					if (tmpx>0&&tmpx<=N&&tmpy>0&&tmpy<=M)
						if (d[tmpx][tmpy]>dis+(p[tmpx][tmpy]!=p[nowx][nowy]))
						{
							d[tmpx][tmpy]=dis+(p[tmpx][tmpy]!=p[nowx][nowy]);
							v.push(make_pair(-d[tmpx][tmpy],way[tmpx][tmpy]));
						}
				}
			}
			int tmp=-1;
			for (int x=1;x<=N;++x)
				for (int y=1;y<=M;++y)
					if (p[x][y]=='B')
						tmp=max(tmp,d[x][y]);
			ans=min(ans,tmp);
		}
	cout<<ans+1<<endl;
}

int main()
{
	init();
	work();
	return 0;
}