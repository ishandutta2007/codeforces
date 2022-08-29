#include <iostream>
using namespace std;

int needValue[10500];
int curValue[10500];
int addValue[10500];
int ans[10500];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n - 1; i++)
	{
		needValue[i] = n - i - 1;
		curValue[i] = 1;
	}
	for (int i = 0; i < k; i++)
	{
		int curpos = n - 1;
		for (int j = n - 1; j >= 0; j--)
		{
			while (curValue[j] + curValue[curpos] < needValue[j] && curpos > 0)
				curpos--;
			addValue[j] = curValue[curpos];
			ans[j] = curpos + 1;
		}
		for (int j = 0; j < n; j++)
		{
			printf("%d ", ans[j] );
			curValue[j] += addValue[j];
		}
		printf("\n");
	}



	return 0;
}