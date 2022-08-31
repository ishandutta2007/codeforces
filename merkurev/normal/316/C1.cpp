#include <iostream>
#include <vector>
using namespace std;




vector <int> g[10500], cost[10500], rev[10500], cap[10500], flow[10500];


int n, m;

int dist[10500];
int prv[10500];
int prvi[10500];
const int inf = 1e9;

int findFlow(int from, int to)
{
	int valueX = n * m / 2;
	int ans = 0;
	for (int t = 0; t < valueX; t++)
	{
		for (int i = 0; i <= to; i++)
			dist[i] = inf;
		dist[from] = 0;
		
		while (true)
		{
			bool ch = false;
			for (int i = 0; i <= to; i++)
			{
				for (int j = 0; j < g[i].size(); j++)
				{
					int nx = g[i][j];
					if (cap[i][j] == flow[i][j] )
						continue;
					int nd = dist[i] + cost[i][j];
					if (nd < dist[nx] )
					{
						ch = true;
						dist[nx] = nd;
						prv[nx] = i;
						prvi[nx] = j;
					}
				}
			}
			if (!ch)
				break;

		}
		int cur = to;
		while (cur != from)
		{
			int nv = prv[cur];
			int i = prvi[cur];

			flow[nv][i]++;
			flow[cur][rev[nv][i] ]--;
			cur = nv;
		}


		ans += dist[to];
	}
	return ans;
}



void addEdge(int from, int to, int cst)
{
	g[from].push_back(to);
	cost[from].push_back(cst);
	cap[from].push_back(1);
	flow[from].push_back(0);
	rev[from].push_back(g[to].size() );
	
	g[to].push_back(from);
	cost[to].push_back(-cst);
	cap[to].push_back(0);
	flow[to].push_back(0);
	rev[to].push_back(g[from].size() - 1);
}



int q[105][105];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};


int getPos(int x, int y)
{
	return x * m + y;
}

bool inF(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &q[i][j] );

	int st = n * m;
	int fin = st + 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int curPos = getPos(i, j);
			if ( (i + j) % 2 == 0)
			{
				addEdge(st, curPos, 0);
				for (int h = 0; h < 4; h++)
				{
					int ni = i + dx[h], nj = j + dy[h];
					if (!inF(ni, nj) ) 
						continue;
					int cst = 1;
					if (q[i][j] == q[ni][nj] )
						cst = 0;
					int nPos = getPos(ni, nj);
					addEdge(curPos, nPos, cst);
				}
			}
			else
				addEdge(curPos, fin, 0);
		}
	int ans = findFlow(st, fin);
	printf("%d", ans);

	return 0;
}