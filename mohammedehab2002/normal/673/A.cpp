#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int l=0;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if (a-l>15)
		break;
		l=a;
	}
	printf("%d",min(l+15,90));
}