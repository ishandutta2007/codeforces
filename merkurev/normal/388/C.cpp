#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;



int m[105];
int ms = 0;

int k[105];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	int A = 0, B = 0;
	for (int i = 0; i < n; i++)
	{               
		scanf("%d", &k[i] );
		for (int j = 0; j < k[i]; j++)
		{
			int x;
			scanf("%d", &x);
			if (j < k[i] / 2)
				A += x;
			else if (j >= (k[i] + 1) / 2)
				B += x;
			else m[ms++] = x;
		}
	}
	sort(m, m + ms);
	reverse(m, m + ms);	
	for (int i = 0; i < ms; i++)
		if ( (i & 1) == 0)
			A += m[i];
		else
			B += m[i];
	printf("%d %d", A, B);
			



	return 0;
}