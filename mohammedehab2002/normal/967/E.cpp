#include <iostream>
#include <deque>
using namespace std;
deque<long long> v[65],ans;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		long long a;
		scanf("%I64d",&a);
		v[__builtin_clzll(a)].push_back(a);
	}
	for (int i=0;i<65;i++)
	{
		long long cur=0;
		deque<long long> tmp;
		while (!ans.empty() || !v[i].empty())
		{
			if (!v[i].empty() && (cur^v[i].back())>cur)
			{
				tmp.push_back(v[i].back());
				v[i].pop_back();
			}
			else if (!ans.empty())
			{
				tmp.push_back(ans.front());
				ans.pop_front();
			}
			else
			{
				printf("No");
				return 0;
			}
			cur^=tmp.back();
		}
		ans=tmp;
	}
	printf("Yes\n");
	for (long long i:ans)
	printf("%I64d ",i);
}