#include<bits/stdc++.h>
using namespace std;
long long n,x,pos;
int main()
{
	scanf("%I64d",&n);
	if (n%2==0) printf("%I64d\n",n/2);
	else
	{
		x=sqrt(n);
		bool f=0;
		for (int i=2;i<=x;i++)
		{
			if (n%i==0) 
			{
				f=1;
				break;
			}
		}
		if (!f) printf("1\n");
		else
		{
			for (int i=2;i<=x;i++)
			{
				if (n%i==0)
				{
					pos=i;
					break;
				}
			}
			printf("%I64d\n",1+(n-pos)/2);
		}
	}
	return 0;
}