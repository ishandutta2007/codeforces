#include<bits/stdc++.h>
using namespace std;
int n,a[22],ans;
bool f;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			if (j-i!=1 && j-i!=0 && j-i!=3 && j-i!=7 && j-i!=15) continue;
			f=0;
			for (int k=i+1;k<=j;k++)
			{
				if (a[k]<a[k-1]) 
				{
					f=1;
					break;
				}
			}
			if (!f && j%(j-i+1)==0) ans=max(ans,j-i+1);
		}
	}
	printf("%d\n",ans);
	return 0;
}