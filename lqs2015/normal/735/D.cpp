#include<bits/stdc++.h>
using namespace std;
int test;
long long n;
bool is_prime(long long n)
{
	int x=sqrt(n)+10;
	for (int i=2;i<=x && i<n;i++)
	{
		if (n%i==0) return 0;
	}
	return 1;
}
int main()
{
	//scanf("%d",&test);
	test=1;
	while(test--)
	{
		scanf("%lld",&n);
		if (is_prime(n)) printf("1\n");
		else 
		{
			if (n%2==0) printf("2\n");
			else 
			{
				if (is_prime(n-2)) printf("2\n");
				else printf("3\n");
			}
		}
	}
	return 0;
}