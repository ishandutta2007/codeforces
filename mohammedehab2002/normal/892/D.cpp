#include <iostream>
#include <set>
using namespace std;
int arr[22];
set<int> s;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		s.insert(arr[i]);
	}
	for (int i=0;i<n;i++)
	{
		auto it=s.upper_bound(arr[i]);
		if (it==s.end())
		it=s.begin();
		printf("%d ",*it);
	}
}