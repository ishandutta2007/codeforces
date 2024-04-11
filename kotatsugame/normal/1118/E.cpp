#include<iostream>
#include<utility>
#include<cstdio>
using namespace std;
long long n,k;
main()
{
	cin>>n>>k;
	if(n>k*(k-1))
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int a=1,b=2;
	while(n)
	{
		printf("%d %d\n",a,b);
		n--;
		a^=b^=a^=b;
		if(a<b)
		{
			if(b<k)b++;
			else
			{
				a++;
				b=a+1;
			}
		}
	}
}