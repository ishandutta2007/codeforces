#include<bits/stdc++.h>
using namespace std;

int n;
int main()
{
	scanf("%d",&n);
	int ans=n+1,pos=1;
	for (int i=2;i<=n;i++)
	{
		int sum=i+(n+i-1)/i;
		if (sum<ans)	ans=sum,pos=i;
	}
	int blo=(n+pos-1)/pos;
	for (int i=1;i<=blo;i++)
	{
		int l=(i-1)*blo+1;
		int r=i*blo;
		if (r>n)	r=n;
		for (int j=r;j>=l;j--)
			printf("%d ",j);
	}
	printf("\n");
	return 0;
}