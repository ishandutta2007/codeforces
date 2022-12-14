#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
long long n,k,ss,d,ans;
multiset<long long> s;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for (int i=1;i<=k;i++)
	{
		s.insert(-1e18);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&ss,&d);
		multiset<long long>::iterator it=s.begin();
		ans=max(*it,ss)+d;
		s.erase(it);
		s.insert(ans);
		printf("%I64d\n",ans);
	}
	return 0;
}