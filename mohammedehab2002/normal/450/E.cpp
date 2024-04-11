#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int lp[100005];
bool vis[100005];
bool cmp(int a,int b)
{
	return lp[a]>lp[b];
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		if (!lp[i])
		{
			for (int j=i;j<=n;j+=i)
			{
				if (!lp[j])
				lp[j]=i;
			}
		}
	}
	vector<pair<int,int> > ans;
	for (int i=n;i>1;i--)
	{
		if (lp[i]==i)
		{
			vector<int> v;
			for (int j=i;j<=n;j+=i)
			{
				if (!vis[j])
				v.push_back(j);
			}
			sort(v.begin(),v.end(),cmp);
			for (int i=0;i+1<v.size();i+=2)
			{
				ans.push_back({v[i],v[i+1]});
				vis[v[i]]=1;
				vis[v[i+1]]=1;
			}
		}
	}
	printf("%d\n",ans.size());
	for (auto p:ans)
	printf("%d %d\n",p.first,p.second);
}