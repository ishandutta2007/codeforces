#include <iostream>

using namespace std;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n,q[105],p=0,k=1;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if (x==k)
		{
			q[p++]=2001+i;
			k++;
		}
	}
	printf("%d\n",p);
	for (int i=0;i<p;i++)
	{
		printf("%d ",q[i]);
	}
	return 0;
}