#include<cstdio>
#include<iostream>
using namespace std;

int n,ans;
int main()
{
	scanf("%d",&n);
	int q=1;
	while (n>0)
	{
		ans+=(n%10>5?1:0)*q;
		if (q!=1)	ans+=q;
		q<<=1;
		n/=10;
	}
	printf("%d\n",ans+1);
	return 0;
}