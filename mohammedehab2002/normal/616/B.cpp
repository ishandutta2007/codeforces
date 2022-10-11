#include <iostream>
using namespace std;
int main()
{
	int n,m,maxi=0;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		int mini=(1<<30);
		for (int x=0;x<m;x++)
		{
			int a;
			scanf("%d",&a);
			mini=min(mini,a);
		}
		maxi=max(maxi,mini);
	}
	printf("%d",maxi);
}