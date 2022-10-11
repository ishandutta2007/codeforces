#include <iostream>
using namespace std;
int main()
{
	long long n;
	int q;
	scanf("%I64d%d",&n,&q);
	while (q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if ((x+y)%2==0)
		{
			long long tmp=(x%2? x-1:x-2);
			tmp*=n;
			tmp/=2;
			if (x%2==0)
			tmp+=(n+1)/2;
			tmp+=((y+x%2)/2);
			printf("%I64d\n",tmp);
		}
		else
		{
			long long tmp=(x%2? x-1:x-2);
			tmp*=n;
			tmp/=2;
			if (x%2==0)
			tmp+=n/2;
			tmp+=((y+!(x%2))/2);
			printf("%I64d\n",tmp+(n*n+1LL)/2);
		}
	}
}