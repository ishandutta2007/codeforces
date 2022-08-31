#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <ctime>
#include <string>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

#define left ksjahfashfo
#define right fuck
#define up mirz
#define down azaza

const int INF = (int)1e9 + 10;
const int N = 3010;
char table[N][N];
int tree[N * N];
int up[N][N], down[N][N], left[N][N], right[N][N];
int n, m;

struct QueueMin
{
	pii frontQ[N], backQ[N];
	int frontS, backS;
	void init()
	{
		frontS = backS = 0;
	}
	void push(int val)
	{
		int old = (backS == 0 ? INF : backQ[backS - 1].Y);
		backQ[backS] = mp(val, min(val, old));
		backS++;
	}
	int getMin()
	{
		int m1 = (frontS == 0 ? INF : frontQ[frontS - 1].Y);
		int m2 = (backS == 0 ? INF : backQ[backS - 1].Y);
		return min(m1, m2);
	}
	void pop()
	{
		if (frontS > 0)
			frontS--;
		else
		{
			int old = INF;
			while (backS > 0)
			{
				frontQ[frontS] = mp(backQ[backS - 1].X, min(old, backQ[backS - 1].X));
				old = frontQ[frontS].Y;
				backS--;
				frontS++;
			}
			frontS--;
		}
	}
} qUp, qDown;

int tmpUp[N], tmpDown[N];

bool inRect(int x, int y, int x1, int x2, int y1, int y2)
{
	return x >= x1 && x <= x2 &&
			y >= y1 && y <= y2;
}

bool check(int len, int size)
{
	qUp.init();
	qDown.init();
	for (int i = 0; i < size; i++)
	{
		qUp.push(tmpUp[i]);
		qDown.push(tmpDown[i]);
	}
	for (int i = size; i < len; i++)
	{
		int d = qUp.getMin() + qDown.getMin();
		if (d >= size)
			return true;
		qUp.pop();
		qDown.pop();

		qUp.push(tmpUp[i]);
		qDown.push(tmpDown[i]);
	}

	int d = qUp.getMin() + qDown.getMin();
	if (d >= size)
		return true;
	return false;
}

int solveCase(int len)
{
		//cerr << tmpUp[i] << ":" << tmpDown[i] << endl;
	int l = 0, r = min(len, min(n, m)) + 1;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (check(len, mid))
			l = mid;
		else
			r = mid;
	}
	//cerr << "RESULT " << l << endl;
	return l;
}

int recalc(int x, int y, int v, int x1, int x2, int y1, int y2)
{
	if (x != -1 && !inRect(x, y, x1, x2, y1, y2))
		return tree[v];
	if (x2 - x1 > y2 - y1)
	{
		if (x1 == x2)
		{
			tree[v] = 0;
			for (int s = y1; s <= y2; s++)
				tree[v] = (table[x1][s] == 'X' ? 0 : 1);
			return tree[v];
		}
		int mid = (x1 + x2) / 2;
		int ans = recalc(x, y, 2 * v, x1, mid, y1, y2);
		ans = max(ans, recalc(x, y, 2 * v + 1, mid + 1, x2, y1, y2));
		//cerr << "!!!V " << v << endl;
		for (int i = y1; i <= y2; i++)
		{
			tmpUp[i - y1] = min(up[mid][i], mid - x1 + 1);
			tmpDown[i - y1] = min(down[mid + 1][i], x2 - mid);
		}
		ans = max(ans, solveCase(y2 - y1 + 1));
		tree[v] = ans;
	}
	else
	{
		if (y1 == y2)
		{
			tree[v] = 0;
			for (int s = x1; s <= x2; s++)
				tree[v] = (table[s][y1] == 'X' ? 0 : 1);
			return tree[v];
		}
		int mid = (y1 + y2) / 2;
		int ans = recalc(x, y, 2 * v, x1, x2, y1, mid);
		ans = max(ans, recalc(x, y, 2 * v + 1, x1, x2, mid + 1, y2));
		//cerr << "!!!V " << v << endl;
		for (int i = x1; i <= x2; i++)
		{
			tmpUp[i - x1] = min(left[i][mid], mid - y1 + 1);
			tmpDown[i - x1] = min(right[i][mid + 1], y2 - mid);
		}
		ans = max(ans, solveCase(x2 - x1 + 1));
		tree[v] = ans;
	}
	return tree[v];
}

bool free(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	return table[x][y] == '.';
}

int putTile(int x, int y)
{
	table[x][y] = 'X';
	int d = 1;
	up[x][y] = down[x][y] = left[x][y] = right[x][y] = 0;
	while (free(x - d, y))
	{
		down[x - d][y] = d;
		d++;
	}
	
	d = 1;
	while (free(x + d, y))
	{
		up[x + d][y] = d;
		d++;
	}

	d = 1;
	while (free(x, y - d))
	{
		right[x][y - d] = d;
		d++;
	}

	d = 1;
	while (free(x, y + d))
	{
		left[x][y + d] = d;
		d++;
	}

	return recalc(x, y, 1, 0, n - 1, 0, m - 1);
}

void initCalc()
{
	for (int i = 0; i < n; i++)
		for (int s = 0; s < m; s++)
		{
			if (table[i][s] == 'X')
				continue;
			up[i][s] = 1 + (i == 0 ? 0 : up[i - 1][s]);
			left[i][s] = 1 + (s == 0 ? 0 : left[i][s - 1]);
		}

	for (int i = n - 1; i >= 0; i--)
		for (int s = m - 1; s >= 0; s--)
		{
			if (table[i][s] == 'X')
				continue;
			down[i][s] = 1 + down[i + 1][s];
			right[i][s] = 1 + right[i][s + 1];
		}
}

int main()
{
	int k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < n; i++)
		scanf(" %s", table[i]);


	initCalc();
	recalc(-1, -1, 1, 0, n - 1, 0, m - 1);
	//cerr << "!!!END" << endl;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		int ans = putTile(x, y);
		printf("%d\n", ans);
	}

	return 0;
}