#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
pair<int,int> s[333333];
int t[333333],del[333333],p1,p2,cnt,n;
pair<pair<int,int>,int> a[3333333];
long long sum;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s[i].first);
		s[i].second=i;
	}
	sort(s+1,s+n+1);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
	}
	sort(t+1,t+n+1);
	for (int i=1;i<=n;i++)
	{
		del[i]=s[i].first-t[i];
		sum+=del[i];
	}
	if (sum)
	{
		printf("NO\n");
		return 0;
	}
	p1=p2=1;
	while(p1<=n && del[p1]<=0) p1++;
	while(p2<=n && del[p2]>=0) p2++;
	while(p1<=n || p2<=n)
	{
		if (p1<p2) 
		{
			printf("NO\n");
			return 0;
		}
		int d=min(del[p1],-del[p2]);
		if (s[p1].first-s[p2].first<2*d)
		{
			printf("NO\n");
			return 0;
		}
		del[p1]-=d;del[p2]+=d;
		a[++cnt]=make_pair(make_pair(s[p2].second,s[p1].second),d);
		while(p1<=n && del[p1]<=0) p1++;
		while(p2<=n && del[p2]>=0) p2++;
	}
	printf("YES\n");
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
	{
		printf("%d %d %d\n",a[i].first.first,a[i].first.second,a[i].second);
	}
	return Accepted;
}