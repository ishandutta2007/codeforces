#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int T , n;
char c[maxn] , f[maxn];

bool check(int p)
{
	int i , x = 0 , y = p+1 , xx = 0 , yy = n+1;
	for (i = 1 ; i <= n ; i++)
	{
		if (c[i]-'0' < p)
		{
			if (c[i]-'0' < x) return 0;
			x = c[i]-'0';
			f[i] = '1';
			xx = i;
		}
		if (c[i]-'0' > p)
		{
			if (c[i]-'0' < y) return 0;
			y = c[i]-'0';
			f[i] = '2';
			if (yy == n+1) yy = i;
		}
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (c[i]-'0' == p)
		{
			if (i > xx) f[i] = '1';
			else if (i < yy) f[i] = '2';
			else return 0;
		}
	}
	f[n+1] = '\0';
	printf("%s\n",f+1);
	return 1;
}

bool check1(int p)
{
	int i , x = 0 , y = p+1;
	for (i = 1 ; i <= n ; i++)
	{
		if (c[i]-'0' <= p)
		{
			if (c[i]-'0' < x) return 0;
			x = c[i]-'0';
			f[i] = '1';
		}
		else
		{
			if (c[i]-'0' < y) return 0;
			y = c[i]-'0';
			f[i] = '2';
		}
	}
	f[n+1] = '\0';
	printf("%s\n",f+1);
	return 1;
}

void work()
{
	for (int i = 0 ; i <= 9 ; i++)
		if (check(i)) return;
	for (int i = 0 ; i <= 9 ; i++)
		if (check1(i)) return;
	printf("-\n");
}

int main()
{
	int i , j;
	cin >> T;
	while (T--)
	{
		scanf("%d",&n);
		scanf("%s",c+1);
		work();
	}
	return 0;
}