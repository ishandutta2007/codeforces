#include <iostream>
#include <vector>
using namespace std;
vector <int> v[2005],v2;
int ans=1;
int dfs(int s,int maxi)
{
	if (!v[s].size())
	return maxi;
	for (int i=0;i<v[s].size();i++)
	ans=max(ans,dfs(v[s][i],maxi+1));
	return ans;
}
int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		if (a!=-1)
		v[a].push_back(i+1);
		else
		v2.push_back(i+1);
	}
	for (int i=0;i<v2.size();i++)
	ans=max(ans,dfs(v2[i],1));
	cout << ans;
}