#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int> > l[200005];
int main()
{
	int n,len;
	scanf("%d%d",&n,&len);
	for (int i=0;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		l[b-a+1].push_back(make_pair(a,c));
	}
	for (int i=0;i<=len;i++)
	sort(l[i].begin(),l[i].end());
	long long ans=(1LL<<40);
	for (int i=0;i<=len;i++)
	{
		if (!l[i].size() || !l[len-i].size())
		continue;
		int r=l[len-i].size();
		long long cur=(1LL<<40);
		for (int x=l[i].size()-1;x>=0;x--)
		{
			if (r==l[len-i].size())
			r--;
			while (l[len-i][r].first>l[i][x].first+i-1)
			{
				cur=min(cur,(long long)l[len-i][r].second);
				r--;
				if (r<0)
				break;
			}
			r++;
			ans=min(cur+l[i][x].second,ans);
		}
	}
	if (ans==(1LL<<40))
	ans=-1;
	printf("%I64d",ans);
}