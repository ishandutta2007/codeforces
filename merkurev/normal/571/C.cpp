#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int maxn = (int) 4e5 + 100;
vector <int> posIn[maxn];
vector <int> negIn[maxn];
vector <int> v[maxn];
int val[maxn];
bool used[maxn];

int deg[maxn];
vector <int> one;

vector <int> st;

int cntX = 0;

void setPos(int x)
{
	if (val[x] != 0)
		return;
	eprintf("set %d pos\n", x);
	cntX++;
	val[x] = 1;
	for (int i = 0; i < (int) posIn[x].size(); i++)
		st.push_back(posIn[x][i] );
	int ptr = x;
	for (int i = 0; i < (int) negIn[ptr].size(); i++)
	{
		int x = negIn[ptr][i];
		deg[x]--;
		if (deg[x] == 1 )
			one.push_back(x);
	}
}

void setNeg(int x)
{
	if (val[x] != 0)
		return;
	eprintf("set %d neg\n", x);
	cntX++;
	val[x] = -1;
	for (int i = 0; i < (int) negIn[x].size(); i++)
		st.push_back(negIn[x][i] );
	int ptr = x;
	for (int i = 0; i < (int) posIn[ptr].size(); i++)
	{
		int x = posIn[ptr][i];
		deg[x]--;
		if (deg[x] == 1 )
			one.push_back(x);
	}
}


void markGood(int x)
{
	used[x] = true;
	for (int i = 0; i < (int) v[x].size(); i++)
	{
		int a = v[x][i];
		if (a > 0)
			setNeg(a - 1);
		if (a < 0)
			setPos(-a - 1);
	}
}


void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		for (int j = 0; j < x; j++)
		{
			int y;
			scanf("%d", &y);
			v[i].push_back(y);
			
			if (y > 0)
			{
				posIn[y - 1].push_back(i);
			}
			else
			{
				negIn[-y - 1].push_back(i);
			}
		}
		deg[i] = x;
		if (deg[i] == 1)
			one.push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		if (posIn[i].empty() )
			setNeg(i);
		if (negIn[i].empty() )
			setPos(i);
	}

	int ptr = 0;
	while (cntX < m)
	{
		if (!st.empty() )
		{
			int x = st.back();
			st.pop_back();
			markGood(x);
			continue;
		}

		bool ch = false;
		if (!one.empty() )
		{
			ch = true;
			int x = one.back();
			one.pop_back();
		
			for (int i = 0; i < (int) v[x].size(); i++)
			{
				int y = v[x][i];
				if (y > 0)
					setPos(y - 1);
				else
					setNeg(-y - 1);
			}
			continue;
		}
		
		if (cntX == m)
			break;
		
		if (!ch)
		{
			while (val[ptr] != 0)
				ptr++;
			setPos(ptr);
		}
	}
	for (int i = 0; i < n; i++)
	{
		bool good = false;
		for (int j = 0; j < (int) v[i].size(); j++)
		{
			int x = v[i][j];
			if (x > 0 && val[x - 1] == 1)
				good = true;
			if (x < 0 && val[-x - 1] == -1)
				good = true;
		}
		if (!good) 
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	for (int i = 0; i < m; i++)
		if (val[i] == 1)
			printf("1");
		else
			printf("0");
	printf("\n");
}

int main(int, char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}