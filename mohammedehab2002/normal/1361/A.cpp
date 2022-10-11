#include <bits/stdc++.h>
using namespace std;
int a[500005];
vector<int> v[500005],d[500005];
bool ex[500005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d[a[i]].push_back(i);
	}
	vector<int> ans;
	for (int i=1;i<=n;i++)
	{
		for (int j:d[i])
		{
			for (int k=1;k<=v[j].size()+1;k++)
			ex[k]=0;
			for (int k:v[j])
			{
				if (a[k]<=i)
				ex[a[k]]=1;
			}
			int cur=1;
			while (ex[cur])
			cur++;
			if (cur!=i)
			{
				printf("-1");
				return 0;
			}
			ans.push_back(j);
		}
	}
	for (int i:ans)
	printf("%d ",i);
}