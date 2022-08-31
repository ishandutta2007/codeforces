#include <iostream>
#include <set>
using namespace std;


int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a % b) );
}

                                               
set <int> bad;

int a[10500], b[10500];

int calc(int x)
{
	int ans = 0;
	for (int j = 2; j * j <= x; j++)
	{
		while (x % j == 0)
		{
			x /= j;
			if (bad.count(j) )
				ans--;				
			else
				ans++;
		}
	}	
	if (x != 1)
	{
		
		if (bad.count(x) )
  			ans--;							
		else
			ans++;
	}
	return ans;
}

int g[10500];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int ans = 0;

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i] );
		bad.insert(b[i] );
	}
	g[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		g[i] = gcd(g[i - 1], a[i] );	
	}
	int dv = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		g[i] /= dv;
		int x = calc(g[i] );
		if (x < 0)
			dv *= g[i];
		a[i] /= dv;
	}


	for (int i = 0; i < n; i++)
	{
		int x = a[i];
		ans += calc(x);
//		fprintf(stderr, "%d:%d ", a[i], calc(x) );
	}
		     
	printf("%d\n", ans);


	return 0;
}