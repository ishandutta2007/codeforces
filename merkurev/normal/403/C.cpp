#include <iostream>
#include <vector>
using namespace std;
                                              

int a[2005][2005];
pair <int, int> qu[25005];
int l, r;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)          
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j] );
		}   
	int s;
	for (int i = 0; i < n; i++)
	{
		if (a[i][i] )
			s = i;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i][s] && i != s)
			qu[r++] = make_pair(0, i);
		if (a[s][i] && i != s)
			qu[r++] = make_pair(1, i);
	}
	while (r - l > 0)
	{
		int t = qu[l].first;
		int i = qu[l].second;
		l++;
		if (t == 0)
		{
			for (int j = 0; j < n; j++)
			{
				if (j == s || !a[j][i] || a[j][s] )
					continue;
				a[j][s] = 1;
				qu[r++] = make_pair(0, j);
			}
		}	
		else
		{
			for (int j = 0; j < n; j++)
			{
				if (j == s || !a[i][j] || a[s][j] )
					continue;
				a[s][j] = 1;
				qu[r++] = make_pair(1, j);
			}
		}
	}
	bool gd = true;
	for (int i = 0; i < n; i++)
		if (!a[s][i] || !a[i][s] )
			gd = false;
		
		

	if (gd)
		printf("YES");
	else
		printf("NO");


	return 0;
}