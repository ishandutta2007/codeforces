#include <iostream>
#include <set>
using namespace std;
multiset<int> sus,sold;
int main()
{
	int n;
	scanf("%d",&n);
	long long ans=0;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		int x=(1<<30),y=(1<<30);
		if (!sus.empty())
		x=min(x,*sus.begin());
		if (!sold.empty())
		y=min(y,*sold.begin());
		if (a<x && a<y)
		sus.insert(a);
		else 
		{
			ans+=a-min(x,y);
			if (x<y)
			sus.erase(sus.begin());
			else
			{
				sus.insert(*sold.begin());
				sold.erase(sold.begin());
			}
			sold.insert(a);
		}
	}
	printf("%I64d",ans);
}