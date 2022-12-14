#include <stdio.h>
#include <queue>
using namespace std;

priority_queue <int, vector <int>, greater <int> > heap;
int pile[101][101], n, pile_size = 0;

int init()
{
	int i, t;
	scanf("%d", &n);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d", &t);
		heap.push(t);
	}
	return 0;
}
int solve()
{
	int i, j, max, maxi;
	for(i = 1; i <= n; i ++)
	{
		int now = heap.top();
		heap.pop();
		max = -1;
		for(j = 1; j <= pile_size; j ++)
			if(pile[j][0] <= now && pile[j][0] > max)
			{
				max = pile[j][0];
				maxi = j;
			}
		if(max == -1)
		{
			pile_size ++;
			pile[pile_size][0] = 1;
			pile[pile_size][1] = now;
		}
		else
		{
			pile[maxi][0] ++;
			pile[maxi][pile[maxi][0]] = now;
		}
	}
	printf("%d", pile_size);
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}