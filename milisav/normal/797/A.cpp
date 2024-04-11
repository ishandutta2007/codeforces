#include<bits\stdc++.h>
using namespace std;
int n,k;
vector<int> a;
int b,c;
int main()
{
	scanf("%d %d",&n,&k);
	b=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				a.push_back(i);
				n=n/i;
			}
		}
	}
	if(n!=1) a.push_back(n);
	if(a.size()<k)
	{
		printf("-1");
		return 0;
	}
	for(int i=0;i<k-1;i++)
	{
		b=b/a[i];
		printf("%d ",a[i]);
	}
	printf("%d",b);
	return 0;
}