#include <bits/stdc++.h>
using namespace std;
int arr[1000005],vis[1000005];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
			vis[i]=-1;
		}
		vector<int> v;
		v.push_back(1);
		vis[1]=0;
		while (1)
		{
			int tmp=v.back()-arr[v.back()];
			if (vis[tmp]!=-1)
			{
				printf("%d\n",(int)v.size()-vis[tmp]);
				for (int i=vis[tmp];i<v.size();i++)
				printf("%d ",v[i]);
				printf("\n");
				break;
			}
			vis[tmp]=v.size();
			v.push_back(tmp);
		}
	}
}