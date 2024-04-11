#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		if (a)
		s.insert(a);
	}
	printf("%d",s.size());
}