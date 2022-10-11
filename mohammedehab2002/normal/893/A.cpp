#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int spec=3;
	while (n--)
	{
		int a;
		scanf("%d",&a);
		if (spec==a)
		{
			printf("NO");
			return 0;
		}
		int tmp=a%3+1;
		if (tmp==spec)
		tmp=tmp%3+1;
		spec=tmp;
	}
	printf("YES");
}