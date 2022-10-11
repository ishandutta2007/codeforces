#include <iostream>
#include <queue>
using namespace std;
bool vis[20005];
int main()
{
	int n,m,ans=(1<<20);
	cin >> n >> m;
	queue<pair<int,int> > q;
	q.push({n,0});
	while (!q.empty())
	{
		int i=q.front().first,l=q.front().second;
		q.pop();
		if (i<0 || vis[i])
		continue;
		vis[i]=1;
		if (i>m)
		{
			ans=min(ans,l+i-m);
			continue;
		}
		if (i==m)
		{
			cout << min(l,ans);
			return 0;
		}
		q.push({2*i,l+1});
		q.push({i-1,l+1});
	}
	cout << ans;
}