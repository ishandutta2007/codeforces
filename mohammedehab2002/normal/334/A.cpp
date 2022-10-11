#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int st=1,en=n*n;
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n/2;x++)
		printf("%d ",st++);
		for (int x=0;x<n/2;x++)
		printf("%d ",en--);
		printf("\n");
	}
}