#include<bits/stdc++.h>
#define LL long long
using namespace std;

void work()
{
	LL a, b;
	scanf("%I64d%I64d", &a, &b);
	if(__gcd(a, b) != 1)
	{
		printf("Impossible\n");
		return;
	}
	while(a && b)
		if(a < b)
		{
			LL t = b / a;
			if(a * t == b) printf("%I64dB", t-1);
			else printf("%I64dB", t);
			b -= t * a;
		}
		else {
			LL t = a / b;
			if(b * t == a) printf("%I64dA", t-1);
			else printf("%I64dA", t);
			a -= t * b;
		}
	printf("\n");
}

int main()
{
	work();
	return 0;
}