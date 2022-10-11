#include <iostream>
#include <vector>
using namespace std;
vector <int> v[200005],v2[200005];
int ans[200005],n;
bool vis[200005];
void cons(int depth)
{
	if (depth==n+1)
	return;
	for (int i=0;i<v2[depth-1].size();i++)
	{
		for (int x=0;x<v[v2[depth-1][i]].size();x++)
		{
			if (!vis[v[v2[depth-1][i]][x]])
			{
				v2[depth].push_back(v[v2[depth-1][i]][x]);
				vis[v[v2[depth-1][i]][x]]=true;
			}
		}
	}
	cons(depth+1);
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		if (i!=n)
		v[i].push_back(i+1);
		if (i!=1)
		v[i].push_back(i-1);
		int a;
		cin >> a;
		if (a!=i)
		v[i].push_back(a);
	}
	v2[1].push_back(1);
	vis[1]=true;
	cons(2);
	for (int i=1;i<=n;i++)
	{
		for (int x=0;x<v2[i].size();x++)
		ans[v2[i][x]]=i-1;
	}
	for (int i=1;i<=n;i++)
	cout << ans[i] << ' ';
}