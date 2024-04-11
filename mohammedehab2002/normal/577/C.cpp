#include <iostream>
#include <vector>
using namespace std;
bool prime[100005];
vector<int> v;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		if (!prime[i])
		{
			for (int x=i;x<=n;x*=i)
			v.push_back(x);
			for (int x=i;x<=n;x+=i)
			prime[x]=1;
		}
	}
	printf("%d\n",v.size());
	for (int i=0;i<v.size();i++)
	printf("%d ",v[i]);
}