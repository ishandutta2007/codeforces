#include <stdio.h>

int t[160000];
int window[10];
int n, k, q;

void add(int a)
{	
	int mx = window[0], mxi = 0;
	for (int i = 1; i < k; i++)
	{
		if (mx > window[i])
		{
			mxi = i;
			mx = window[i];
		}
	}
	if (mx < a)
	{
		window[mxi] = a;
	}
}

bool check(int a)
{
	for (int i = 0; i < k; i++)
	{
		if (a==window[i])
		{
			return true;
		}
	}
	return false;
}


int main()
{
	const int inf = 0;
	scanf("%d%d%d\n", &n, &k, &q);
	for (int i = 0; i < k; i++)
	{
		window[i] = inf;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t[i]);
	}
	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == 1)
			add(t[b]);
		else
		{
			printf(check(t[b]) ? "YES\n" : "NO\n");
		}
	}

}