#include <iostream>
#include <vector>
using namespace std;

vector <int> q[100500];
vector <int> ind[100500];
bool used[505];
int qu[1500];

void bfs(int v, int a, int b)
{
	int l = 0, r = 0;
	qu[r++] = v;
	while (l < r)
	{
		int x = qu[l++];
		int len = q[x].size();
		for (int i = 0; i < len; i++)
		{
			int curind = ind[x][i];
			if (curind < a ||  curind > b)
			{
				int nx = q[x][i];
				if (!used[nx] )
				{
					qu[r++] = nx;
					used[nx] = true;
				}
			}
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		q[a].push_back(b);
		ind[a].push_back(i);
		q[b].push_back(a);
		ind[b].push_back(i);
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		memset(used, false, sizeof used);
			int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (!used[i] )	
			{
				bfs(i, l, r);
				ans++;
			}
		}
		printf("%d\n", ans);
	}



	return 0;
}