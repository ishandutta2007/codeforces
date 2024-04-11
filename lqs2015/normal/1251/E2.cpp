#include<bits/stdc++.h>
using namespace std;
int test,n,cnt;
pair<int,int> a[222222];
multiset<int> s;
long long ans;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i].first,&a[i].second);
			a[i].second=-a[i].second;
		}
		sort(a+1,a+n+1);cnt=0;ans=0;
		s.clear();
		for (int i=n;i>=1;i--)
		{
			if (cnt+i-1>=a[i].first) 
			{
				s.insert(-a[i].second);
			}
			else
			{
				ans+=(*s.begin());
				s.erase(s.begin());
				cnt++;
				s.insert(-a[i].second);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}