#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> e;
pair<int,int> arr[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d%d",&arr[i].first,&arr[i].second);
	sort(arr,arr+n);
	for (int i=0;i<n;i++)
	{
		if (e.size()==2)
		{
			if (e.front()<arr[i].first)
			e.pop_front();
			if (e.back()<arr[i].first)
			e.pop_back();
		}
		if (e.size()==2)
		{
			printf("NO");
			return 0;
		}
		e.push_back(arr[i].second);
	}
	printf("YES");
}