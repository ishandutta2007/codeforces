#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define MN 201000

std::vector<int> v[MN];

int Ans[MN];

typedef std::pair<int, int> P;

std::priority_queue<P> pq;

int p[MN], c[MN];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, x, y; scanf("%d%d%d", &n, &x, &y);
		for(int i = 1; i <= n; i++)
		{
			int p; scanf("%d", &p);
			v[p].push_back(i);
		}
		int id;
		for(int i = 1; i <= n + 1; i++) if(v[i].size() == 0) id = i;
		for(int i = 1; i <= n + 1; i++)
			if(v[i].size())
				pq.push(P(v[i].size(), i));
		for(int j = 1; j <= x; j++)
		{
			P p = pq.top();
			int i = p.second;
			Ans[v[i].back()] = i;
			v[i].pop_back();
			pq.pop();
			if(--p.first > 0) pq.push(p);
		}
		int Max = 0;
		int N = 0;
		for(int i = 1; i <= n + 1; i++)
		{
			Max = std::max(Max, (int)v[i].size());
			for(int j = 0; j < v[i].size(); j++)
				++N, c[N] = i, p[N] = v[i][j];
		}
		for(int i = 1; i <= n - y; i++)	c[++N] = id;
		
		Max = std::max(Max, n - y);
		
		if(Max > N / 2) puts("NO");
		else
		{
			std::rotate(c + 1, c + Max + 1, c + N + 1);
			for(int i = 1; i <= n - x; i++)
				Ans[p[i]] = c[i];
			puts("YES");
			for(int i = 1; i <= n; i++) printf("%d ", Ans[i]); puts("");
		}
		
		while(!pq.empty()) pq.pop();
		for(int i = 1; i <= n + 1; i++) v[i].clear();
	}
}