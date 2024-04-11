#include <iostream>
#include <vector>
using namespace std;


vector <int> q[100500];
int n, m;



void tryCicle()
{
	for (int i = 0; i < n; i++)
	{
		if (q[i].size() != 2)
		{
			printf("unknown topology");
			exit(0);
		}
	}
	printf("ring topology");
	exit(0);
}

void tryStar(int v)
{
	for (int i = 0; i < n; i++)
	{
		if (i == v)
			continue;
		if (q[i].size() != 1)
		{
			printf("unknown topology");
			exit(0);
		}
	}
	printf("star topology");
	exit(0);
}
void tryLine()
{
	for (int i = 0; i < n; i++)
	{
		if (q[i].size() > 2)
		{
			tryStar(i);
		}
	}
	printf("bus topology");
	exit(0);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		q[x].push_back(y);
		q[y].push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		if (q[i].size() == 1)
			tryLine();
	}
	
	
	tryCicle();



	return 0;
}