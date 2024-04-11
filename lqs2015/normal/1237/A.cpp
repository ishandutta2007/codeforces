#include<bits/stdc++.h>
using namespace std;
int n,a[22222];
bool f1,f2;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		if (a[i]%2==0) printf("%d\n",a[i]/2);
		else
		{
			if (a[i]<0) 
			{
				if (!f1) printf("%d\n",a[i]/2-1);
				else printf("%d\n",a[i]/2);
				f1=!f1;
			}
			else
			{
				if (!f2) printf("%d\n",a[i]/2+1);
				else printf("%d\n",a[i]/2);
				f2=!f2;
			}
		}
	}
	return 0;
}