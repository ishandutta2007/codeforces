#include <iostream>
#include <map>
using namespace std;
map<int,int> m[55];
int arr[55][55];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n;x++)
		{
			scanf("%d",&arr[i][x]);
			m[i][arr[i][x]]=1;
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n;x++)
		{
			bool b=0;
			for (int j=0;j<n;j++)
			{
				if (m[i][arr[i][x]-arr[j][x]])
				b=1;
			}
			if (!b && arr[i][x]!=1)
			{
				printf("No");
				return 0;
			}
		}
	}
	printf("Yes");
}