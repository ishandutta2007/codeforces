#include <iostream>
using namespace std;
int arr[1005];
int main()
{
	int n,m,c;
	scanf("%d%d%d",&n,&m,&c);
	while (m--)
	{
		int a;
		scanf("%d",&a);
		if (a<=c/2)
		{
			int i=0;
			while (arr[i] && arr[i]<=a)
			i++;
			arr[i]=a;
			printf("%d\n",i+1);
			fflush(stdout);
		}
		else
		{
			int i=n-1;
			while (arr[i] && arr[i]>=a)
			i--;
			arr[i]=a;
			printf("%d\n",i+1);
			fflush(stdout);
		}
		bool b=0;
		for (int i=0;i<n;i++)
		{
			if (!arr[i])
			b=1;
			if (!i)
			continue;
			if (arr[i]<arr[i-1])
			b=1;
		}
		if (!b)
		return 0;
	}
}