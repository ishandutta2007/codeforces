#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
int n,pos,cp;
pair<int,int> a[222222];
long long ans,sum;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].first);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].second);
	}
	sort(a+1,a+n+1);
	pos=1;
	while(pos<=n)
	{
		cp=a[pos].first;
		while(pos<=n && a[pos].first==cp)
		{
			s.insert(a[pos].second);
			sum+=a[pos].second;
			pos++;
		}
		while(!s.empty())
		{
			ans+=(sum-(*s.rbegin()));
			multiset<int>::iterator it=s.end();it--;
			sum-=(*it);
			s.erase(it);cp++;
			while(pos<=n && a[pos].first==cp)
			{
				s.insert(a[pos].second);
				sum+=a[pos].second;
				pos++;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}