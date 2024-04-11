#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	int ans=-1;
	for(int i=a+b;i>=1;i--)
	{
		if(a/i==0||b/i==0) continue;
		if(a/i+b/i>=n)
		{
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}