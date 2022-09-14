#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int H,W;
int A[1000][1000];
bool usd[999][999];
vector<pair<pair<int,int>,int> >ans;
int check(int i,int j)
{
	int t=-1;
	for(int x=i;x<=i+1;x++)for(int y=j;y<=j+1;y++)
	{
		if(A[x][y]!=0)
		{
			if(t!=-1&&t!=A[x][y])return -1;
			t=A[x][y];
		}
	}
	if(t==-1)t=1;
	return t;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>H>>W;
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>A[i][j];
	queue<pair<pair<int,int>,int> >Q;
	for(int i=0;i<H-1;i++)for(int j=0;j<W-1;j++)
	{
		int r=check(i,j);
		if(r!=-1)
		{
			Q.push(make_pair(make_pair(i,j),r));
			usd[i][j]=true;
		}
	}
	int cnt=0;
	while(!Q.empty())
	{
		cnt++;
		ans.push_back(Q.front());
		int x=Q.front().first.first,y=Q.front().first.second;
		Q.pop();
		for(int i=x;i<=x+1;i++)for(int j=y;j<=y+1;j++)A[i][j]=0;
		for(int i=x-1;i<=x+1;i++)if(i>=0&&i<H-1)
		{
			for(int j=y-1;j<=y+1;j++)if(j>=0&&j<W-1&&!usd[i][j])
			{
				int r=check(i,j);
				if(r!=-1)
				{
					Q.push(make_pair(make_pair(i,j),r));
					usd[i][j]=true;
				}
			}
		}
	}
	if(cnt<(H-1)*(W-1))cout<<"-1\n";
	else
	{
		cout<<ans.size()<<"\n";
		for(int i=ans.size();i--;)cout<<ans[i].first.first+1<<" "<<ans[i].first.second+1<<" "<<ans[i].second<<"\n";
	}
}