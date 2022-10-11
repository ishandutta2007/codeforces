#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,pair<int,int> > > ans;
int n,arr[5][55];
pair<int,int> pre(int x,int y)
{
	if (x==2)
	{
		if (y==1)
		return {3,1};
		return {2,y-1};
	}
	if (y==n)
	return {2,n};
	return {3,y+1};
}
int main()
{
	int cnt;
	scanf("%d%d",&n,&cnt);
	for (int i=1;i<=4;i++)
	{
		for (int x=1;x<=n;x++)
		scanf("%d",&arr[i][x]);
	}
	while (cnt)
	{
		pair<int,int> f={-1,-1},t={-1,-1};
		for (int i=2;i<=3;i++)
		{
			for (int x=1;x<=n;x++)
			{
				if (arr[i][x] && arr[i][x]==arr[3*(i-2)+1][x])
				{
					f={i,x};
					t={3*(i-2)+1,x};
				}
			}
		}
		if (f!=make_pair(-1,-1))
		{
			ans.push_back({arr[f.first][f.second],t});
			arr[f.first][f.second]=0;
			cnt--;
			continue;
		}
		for (int i=2;i<=3;i++)
		{
			for (int x=1;x<=n;x++)
			{
				if (!arr[i][x])
				{
					auto p=pre(i,x);
					if (arr[p.first][p.second])
					{
						f=p;
						t={i,x};
					}
				}
			}
		}
		if (f!=make_pair(-1,-1))
		{
			ans.push_back({arr[f.first][f.second],t});
			swap(arr[f.first][f.second],arr[t.first][t.second]);
		}
		else
		{
			printf("-1");
			return 0;
		}
	}
	printf("%d\n",ans.size());
	for (auto i:ans)
	printf("%d %d %d\n",i.first,i.second.first,i.second.second);
}