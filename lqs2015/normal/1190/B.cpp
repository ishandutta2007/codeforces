#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
map<int,int> mp;
int n,x,r;
long long all;
bool f;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		mp[x]++;
	}
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if ((it->second)>2) 
		{
			printf("cslnb\n");
			return 0;
		}
		if ((it->second)==2)
		{
			r=it->first;
		}
	}
	if (mp[0]>=2)
	{
		printf("cslnb\n");
		return 0;
	}
	mp[r]--;mp[r-1]++;
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if ((it->second)>=2)
		{
			printf("cslnb\n");
			return 0;
		}
	}
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		all+=(long long)(it->first);
	}
	for (int i=0;i<n;i++) all-=i;
	if (all%2) printf("cslnb\n");
	else printf("sjfnb\n");
	return Accepted;
}