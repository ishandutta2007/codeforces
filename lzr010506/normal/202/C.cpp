#include <bits/stdc++.h>
#define eps 1e-10
#define LL long long
#define LD long double
#define pi acos(-1.0)
using namespace std;
int n;
int main()
{
	while(scanf("%d",&n) != EOF)
	{
		if(n == 3) printf("5\n");
		else
			for(int i = 1; ; i += 2)
				if(n <= i * i / 2 + 1)
				{
					printf("%d\n",i);
					break;
				}
	}
	return 0;
}