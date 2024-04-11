#include <iostream>
#include <set>
using namespace std;
multiset<int> s;
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
	int ans=0;
	while (s.size())
	{
		ans++;
		int l=0;
		for (multiset<int>::iterator it=s.begin();it!=s.end();)
		{
			if (*it!=l)
			{
				l=*it;
				multiset<int>::iterator tmp=it;
				it++;
				s.erase(tmp);
			}
			else
			it++;
		}
	}
	printf("%d",n-ans);
}