#include<iostream>
#include<algorithm>
#include<utility>
#include<cstdio>
#include<vector>
using namespace std;
int n;long long T;
pair<long long,pair<int,int> >a[1<<18];
main()
{
	scanf("%d%lld",&n,&T);
	for(int i=0;i<n;i++)
	{
		scanf("%d%lld",&a[i].second.first,&a[i].first);
		a[i].second.second=i+1;
	}
	sort(a,a+n);
	int f=-1,l=n+1;
	for(int i=0;i<99;i++)
	{
		int m=(f+l)/2;
		long long now=T;int cnt=0,j=0;
		while(cnt<m&&now>0&&j<n)
		{
			if(a[j].second.first>=m)
			{
				now-=a[j].first;
				cnt++;
			}
			j++;
		}
		if(now<0||cnt<m)l=m;
		else f=m;
	}
	vector<int>ans;
	int j=0,cnt=0;
	while(cnt<f&&T>0&&j<n)
	{
		if(a[j].second.first>=f)
		{
			T-=a[j].first;
			cnt++;
			ans.push_back(a[j].second.second);
		}
		j++;
	}
	printf("%d\n%d\n",f,ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d",ans[i]);
		if(i<ans.size()-1)putchar(' ');
	}
	puts("");
}