#include <iostream>
#include <set>
using namespace std;
multiset<long long> s;
long long go(int x)
{
	long long ret=0;
	while (x--)
	{
		auto it=s.begin();
		ret+=*it;
		s.erase(it);
	}
	s.insert(ret);
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		s.insert(a);
	}
	long long ans=0;
	if (n%2==0)
	ans+=go(2);
	while (s.size()!=1)
	ans+=go(3);
	printf("%I64d",ans);
}