#include <iostream>
#include <vector>
using namespace std;

int a[100500];


vector <int> good;

int main()
{


	int n;
	scanf("%d", &n);
	for (int i = 0;  i < n; i++)
		scanf("%d", &a[i] );

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int cur = a[i];
		while (good.size() && cur > good.back())
		{
			ans = max(ans, good.back() ^ cur);
			good.pop_back();
		}
		if (good.size() )
			ans = max(ans, good.back() ^ cur);
		good.push_back(cur);
	}
	printf("%d", ans);

	return 0;
}