#include<iostream>
#include<set>
#include<cstdio>
using namespace std;
set<pair<int,int> > s;
int n,a[111111],ans[111111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n;i>=1;i--)
	{
		set<pair<int,int> >::iterator it=s.lower_bound(make_pair(a[i],0));
		if (it==s.begin()) ans[i]=-1;
		else 
		{
			it--;
			ans[i]=it->second-i-1;
		}
		if (s.empty() || a[i]<s.begin()->first)
		{
			s.insert(make_pair(a[i],i));
		}
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}