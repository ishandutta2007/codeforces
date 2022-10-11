#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int l=0;
	for (int c=0;c<3;c++)
	{
		int x=0;
		for (int i=0;i<n-c;i++)
		{
			int a;
			scanf("%d",&a);
			x^=a;
		}
		if (c)
		printf("%d\n",(x^l));
		l=x;
	}
}