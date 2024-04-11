#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int x,d;
	scanf("%d%d",&x,&d);
	vector<long long> v;
	long long cur=1;
	for (int i=0;i<=30;i++)
	{
		if (x&(1<<i))
		{
			for (int x=0;x<i;x++)
			v.push_back(cur);
			cur+=d;
			v.push_back(cur);
			cur+=d;
		}
	}
	printf("%d\n",v.size());
	for (long long u:v)
	printf("%I64d ",u);
}