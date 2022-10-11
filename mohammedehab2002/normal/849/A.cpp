#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	bool b=(n&1);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if (!i || i==n-1)
		b&=(a&1);
	}
	printf(b? "Yes":"No");
}