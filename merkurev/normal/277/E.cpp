#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


pair <int, int> q[405];
int sqr(int x)
{
	return x * x;
}

double dist(int i, int j)
{
	return sqrt( (double) (sqr(q[i].first - q[j].first) + sqr(q[i].second - q[j].second) ) );
}
struct Edge
{
	int from, to, cap, curflow, revi;
	double price;
	Edge() : from(), to(), cap(), curflow(), revi(), price() {}
	Edge(int from, int to, int cap, int curflow, int revi, double price) : from(from), to(to), cap(cap), curflow(curflow), revi(revi), price(price) {}
};

vector <Edge> a[1005];

void addEdge(int from, int to, double price, int cap)
{
	a[from].push_back(Edge(from, to, cap, 0, a[to].size(), price) );
	a[to].push_back(Edge(to, from, 0, 0, a[from].size() - 1, -price) );
}



double dst[1005];
int prv[1005], prvi[1005];

void findFlow(int n)
{
	int st = 2 * n, fin = 2 * n + 1;
	int needFlow = n - 1;

	int flow = 0;
	double ans = 0;

	while (true)
	{
		memset(prv, -1, sizeof prv);
		prv[st] = 0;
		dst[st] = 0;
		bool ch = true;
		for (int t = 0; t <= fin && ch; t++)
		{
			ch = false;
			for (int v = 0; v <= fin; v++)
			{
				if (prv[v] == -1)
					continue;
				int len = a[v].size();
				for (int i = 0; i < len; i++)
				{
					if (a[v][i].cap == a[v][i].curflow)
						continue;
					int nx = a[v][i].to;
					double nxd = dst[v] + a[v][i].price;
					if (prv[nx] == -1 || dst[nx] > nxd)
					{
						dst[nx] = nxd;
						prv[nx] = v;
						prvi[nx] = i;
						ch = true;
					}
				}
			}
		}
		if (prv[fin] == -1)
			break;
		int cur = fin;
		while (cur != st)
		{
			int nx = prv[cur];
			int ni = prvi[cur];
			a[nx][ni].curflow++;
			a[cur][a[nx][ni].revi].curflow--;
			cur = nx;
		}
		flow ++;
		ans += dst[fin];
	}
	if (flow == needFlow)
	{
		printf("%.10lf", ans);
		return;
	}
	printf("-1");
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		q[i] = make_pair(x, y);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (q[j].second >= q[i].second)
				continue;
			addEdge(i + n, j, dist(i, j), 1);
		}
	for (int i = 0; i < n; i++)
	{
		addEdge(2 * n, n + i, 0, 2);
		addEdge(i, 2 * n + 1, 0, 1);
	}
	findFlow(n);



	return 0;
}