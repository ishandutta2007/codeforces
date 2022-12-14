#include<iostream>
#include<vector>
using namespace std;
int best,n,m,a[44][44];
int dx[5]={0,1,0,0,-1};
int dy[5]={1,0,0,-1,0};
bool In(int x,int y)
{
	return (x>=0 && x<n && y>=0 && y<m);
}
void Search(int num)
{
	bool b=0;
	int i,j;
	vector<pair<int,int> > tmp;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (!a[i][j])
			{
				b=1;
				break;
			}
		}
		if (b) break;
	}
	if (!b)
	{
		best=num;
		return;
	}
	if (num+1>=best) return;
	int x=i,y=j;
	for (int i=0;i<5;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if (!In(xx,yy)) continue;
		for (int j=0;j<5;j++)
		{
			int X=xx+dx[j];
			int Y=yy+dy[j];
			if (!In(X,Y) || a[X][Y]) continue;
			a[X][Y]=1;
			tmp.push_back(make_pair(X,Y)); 
		}
		Search(num+1);
		for (int i=0;i<tmp.size();i++)
		a[tmp[i].first][tmp[i].second]=0;
	}
}
int main()
{
	cin>>n>>m;
	best=n*m;
	Search(0);
	cout<<n*m-best<<endl;
}