#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;


const int maxn = (int) 1e5 + 100;
int a[maxn];
int t[maxn];
int r[maxn];
bool ans[maxn];
bool askAfter[maxn];

void solve()
{
	int m, n;
	scanf("%d%d", &m, &n);
	m--;
	for (int i = 0; i < n; i++)
	{
		ans[i] = false;
		scanf("%d", &a[i] );
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &t[i], &r[i] );
		t[i]--;
	}

	bool fst = true;
	int numFree = 0;

	for (int i = 0; i < m; i++)
	{
		if (r[i] == 1 && fst)
		{
			fst = false;
			for (int j = 0; j < n; j++)
			{
				if (a[j] <= numFree)
					ans[j] = true;
				askAfter[j] = false;
			}
			for (int j = i; j < m; j++)
			{
				if (t[j] != -1)
				{
					askAfter[t[j] ] = true;
					ans[t[j] ] = false;	
				}
			}
			int mn = -1;
			for (int j = 0; j < n; j++)
			{
				if (askAfter[j] == false && (mn == -1 || a[j] < a[mn] ) )
					mn = j;
			}
			numFree -= a[mn];
			a[mn] = 0;
		}
		if (t[i] != -1)
			a[t[i] ]--;
		else
			numFree++;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= numFree)
			ans[i] = true;
	}
	for (int i = 0; i < n; i++)
		printf(ans[i] ? "Y" : "N");
	printf("\n");
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
		solve();


	return 0;
}