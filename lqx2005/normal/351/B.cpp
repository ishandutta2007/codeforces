#include<bits/stdc++.h>
using namespace std;
const int N=3000;
int n;
int a[N+5];
int main()
{
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j]) sum++;
		}
	}
	printf("%d\n",sum*2-sum%2);
	return 0;
}