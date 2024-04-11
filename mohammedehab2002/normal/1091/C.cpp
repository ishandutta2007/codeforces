#include <iostream>
#include <set>
using namespace std;
int n;
set<long long> ans;
void go(int x)
{
	long long tmp=n/x;
	ans.insert(x*tmp*(tmp-1)/2+tmp);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i*i<=n;i++)
	{
		if (n%i==0)
		{
			go(i);
			go(n/i);
		}
	}
	for (long long i:ans)
	printf("%I64d ",i);
}