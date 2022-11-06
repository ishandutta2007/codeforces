#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int cnt;
int a[1000];

int main()
{
	cin >> n;
	while(n)
	{
		int sq = int(sqrt(n));
		bool flag = 0;
		for(int i = 2; i <= sq; i ++)
			if(n % i == 0)
			{
				a[++ cnt] = i;
				flag = 1;
				n /= i;
				break;
			}
        if(!flag) break;
	}
	a[++ cnt] = n;

	if(cnt == 2)
	{
		printf("2");
		return 0;
	}
	if(cnt == 1)
	{
		printf("1\n0");
		return 0;
	}
	printf("1\n");
	printf("%d", a[1] * a[2]);
	return 0;
}