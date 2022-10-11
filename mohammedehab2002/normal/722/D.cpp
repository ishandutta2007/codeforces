#include <iostream>
#include <set>
using namespace std;
set<int> s;
bool go(int x)
{
	if (!x)
	return 0;
	if (s.find(x)==s.end())
	return 1;
	if (go(x/2))
	{
		s.erase(x);
		s.insert(x/2);
		return 1;
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		s.insert(a);
	}
	while (go(*prev(s.end())));
	for (int i:s)
	printf("%d ",i);
}