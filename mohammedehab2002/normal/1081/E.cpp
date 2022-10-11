#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool sqr(long long x)
{
	long long tmp=sqrt(x);
	return (tmp*tmp==x);
}
int main()
{
	int n;
	scanf("%d",&n);
	int cur=0;
	vector<long long> ans(1,0);
	for (int i=0;i<n/2;i++)
	{
		int a;
		scanf("%d",&a);
		cur++;
		while (1LL*cur*cur<=1e13 && !sqr(1LL*cur*cur+a))
		cur++;
		if (1LL*cur*cur>1e13)
		{
			printf("No");
			return 0;
		}
		ans.push_back(1LL*cur*cur);
		ans.push_back(1LL*cur*cur+a);
		cur=sqrt(1LL*cur*cur+a);
	}
	printf("Yes\n");
	for (int i=1;i<ans.size();i++)
	printf("%I64d ",ans[i]-ans[i-1]);
}