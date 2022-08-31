#include <iostream>
using namespace std;


char a[2500500], b[2500500];
int cnt[2][2];

	int answ[2];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	n *= 2;
	scanf("%s%s", a, b);

	for (int i = 0; i < n; i++)
	{
		cnt[a[i] - '0'][b[i] - '0'] ++;
	}

	for (int i = 0; i < n; i++)
	{
		int t = i % 2;
		if (t == 0)
		{
			if (cnt[1][1] )
			{
				answ[0] ++;
				cnt[1][1] --;
				continue;
			}
			if (cnt[1][0] )
			{
				answ[0] ++;
				cnt[1][0] --;
				continue;
			}
			if (cnt[0][1] )
			{
				cnt[0][1] --;
				continue;
			}
			if (cnt[0][0] )
			{
				cnt[0][0] --;
				continue;
			}
		}
		else
		{
			if (cnt[1][1] )
			{
				answ[1] ++;
				cnt[1][1] --;
				continue;
			}
			if (cnt[0][1] )
			{
				answ[1] ++;
				cnt[0][1] --;
				continue;
			}
			if (cnt[1][0] )
			{
				cnt[1][0] --;
				continue;
			}
			if (cnt[0][0] )
			{
				cnt[0][0] --;
				continue;
			}
		}
	}
	if (answ[0] > answ[1] )
	{
		printf("First");
	}
	else if (answ[0] < answ[1] )
		printf("Second");
	else
		printf("Draw");

	return 0;
}