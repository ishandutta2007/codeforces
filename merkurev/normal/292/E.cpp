#include <iostream>
#include <vector>
#include <set>
using namespace std;




struct task
{
	bool isSet;
	int a, b, l;
	task(bool isSet, int a, int b, int l) : isSet(isSet), a(a), b(b), l(l) {}
};

task setT(int a, int b, int l)
{
	return task(true, a, b, l);
}
int numTask = 0;
task getT(int x)
{
	return task(false, x, numTask++, 0);
}

int a[200500], b[100500];
vector <task> qu;
set <int> interestPoints;
vector <int> answers[100500];
int ans[100500];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < 2 * n; i++)
		scanf("%d", &a[i] );
	qu.push_back(setT(0, n, n) );
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		if (x == 1)
		{
			int a, b, l;
			scanf("%d%d%d", &a, &b, &l);
			a--;
			b--;
			qu.push_back(setT(b, a, l) );
		}
		else if (x == 2)
		{
			int y;
			scanf("%d", &y);
			y--;
			qu.push_back(getT(y) );
		}
	}
	for (int i = qu.size() - 1; i >= 0; i--)
	{
		if (qu[i].isSet == false)
		{
			answers[qu[i].a].push_back(qu[i].b);
			interestPoints.insert(qu[i].a);
			continue;
		}
		while (true)
		{
			auto s = interestPoints.lower_bound(qu[i].a);
			if (s == interestPoints.end() )
				break;
			int x = *s;
			if (x >= qu[i].a + qu[i].l)
				break;
			interestPoints.erase(s);
			int curVal = a[qu[i].b + x - qu[i].a];
			for (int i = 0; i < answers[x].size(); i++)
			{
				ans[answers[x][i] ] = curVal;
			}
			answers[x].clear();
		}
	}


	for (int i = 0; i < numTask; i++)
		printf("%d\n", ans[i] );


	return 0;
}