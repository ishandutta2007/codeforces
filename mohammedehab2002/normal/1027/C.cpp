#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1000005],freq[1000005];
double go(double x,double y)
{
	return x/y+y/x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> v;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			freq[arr[i]]++;
			if (freq[arr[i]]==2 || freq[arr[i]]==4)
			v.push_back(arr[i]);
		}
		pair<int,int> ans={-1,-1};
		sort(v.begin(),v.end());
		for (int i=0;i<v.size()-1;i++)
		{
			int st=i+1,en=v.size()-1;
			while (st!=en)
			{
				int sz=(en-st)/3;
				if (go(v[i],v[st+sz])<go(v[i],v[en-sz]))
				en=en-sz-1;
				else
				st=st+sz+1;
			}
			if (ans.first==-1 || go(v[i],v[st])<go(ans.first,ans.second))
			ans={v[i],v[st]};
		}
		printf("%d %d %d %d\n",ans.first,ans.first,ans.second,ans.second);
		for (int i=0;i<n;i++)
		freq[arr[i]]=0;
	}
}