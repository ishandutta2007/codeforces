#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
multiset<int> s;
int arr[505];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n*n;i++)
	{
		int a;
		scanf("%d",&a);
		s.insert(a);
	}
	for (int i=0;i<n;i++)
	{
		multiset<int>::iterator it=s.end();
		it--;
		arr[i]=*it;
		for (int x=0;x<=i;x++)
		{
			s.erase(s.find(__gcd(arr[i],arr[x])));
			if (x!=i)
			s.erase(s.find(__gcd(arr[i],arr[x])));
		}
		printf("%d ",arr[i]);
	}
}