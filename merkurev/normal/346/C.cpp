#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;



int x[100500];

int mX[1100100];


priority_queue <pair<int, int> > qu;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &x[i] );
	int a, b;
	scanf("%d%d", &b, &a);
	sort(x, x + n);
	n = unique(x, x + n) - x;

	int d = b - a;
	for (int i = 0; i < d; i++)
		mX[i] = 2;

	for (int i = 0; i < n; i++)
	{
		int cur = x[i];
		int fst = cur * ( (a + cur - 1) / cur);
		
		for (;fst < b; fst += cur)
			mX[fst - a] = cur;
	}
if (d == 0)
printf("0");
	qu.push(make_pair(-1, 0 + mX[0] - 1) );
	for (int i = 1; i <= d; i++)
	{
		int curdp = -qu.top().first;
		int curend = qu.top().second;
		while (curend < i)
		{
			qu.pop();
			curdp = -qu.top().first;
			curend = qu.top().second;
		}
		if (i == d)
		{
			printf("%d\n", curdp);
			return 0;
		}
		qu.push(make_pair(-curdp - 1, i + mX[i] - 1) );
	}

	return 0;
}