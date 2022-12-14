#include<bits/stdc++.h>
using namespace std;
int n,a[111],res;
bool used[111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		if (used[i]) continue;
		res++;
		for (int j=i;j<=n;j++)
		{
			if (a[j]%a[i]==0) used[j]=1;
		}
	}
	printf("%d\n",res);
	return 0;
}