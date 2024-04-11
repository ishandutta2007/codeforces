#include <iostream>
#include <deque>
using namespace std;
deque<int> v[105];
int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		for (int x=i+1;x<=n;x++)
		v[i].push_back(x);
	}
	int ans=0;
	while (1)
	{
		int cur=-1;
		for (int i=0;i<n;i++)
		{
			if (v[i].size() && cur<=i)
			{
				cur=v[i].front();
				v[i].pop_front();
			}
		}
		if (cur==-1)
		break;
		ans++;
	}
	printf("%d",ans);
}