#include <iostream>
#include <vector>
using namespace std;
int s[100005];
#define inf (1<<30)
vector <pair<int,int> > v[100005];
bool b[100005];
int main()
{
	int n,m,k,ans=inf;
	cin >> n >> m >> k;
	int arr[k];
	for (int i=0;i<m;i++)
	{
		int u,x,l;
		cin >> u >> x >> l;
		v[u].push_back(make_pair(l,x));
		v[x].push_back(make_pair(l,u));
	}
	for (int i=0;i<k;i++)
	cin >> arr[i],b[arr[i]]=1;
	for (int i=0;i<k;i++)
	{
		for (int x=0;x<v[arr[i]].size();x++)
		{
			if (!b[v[arr[i]][x].second])
			ans=min(ans,v[arr[i]][x].first);
		}
	}
	if (ans==inf)
	ans=-1;
	cout << ans;
}