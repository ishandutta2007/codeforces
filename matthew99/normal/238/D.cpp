#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(cur) (int((cur).size()))
#define ALL(cur) (cur).begin(), (cur).end()

using namespace std;

const int maxn = 100000, maxq = 100000;

int n, nq;

vector<int> begin[maxn + 5], end[maxn + 5];

char s[maxn + 5];

int ans[maxq + 5][10];

int vis[maxq + 5];

int cnt[10];

int nxt[maxn + 5], pre[maxn + 5];

void del(const int &cur)
{
	int pp = pre[cur], nn = nxt[cur];
	if (pp != -1) nxt[pp] = nn;
	if (nn != n) pre[nn] = pp;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &nq);
	scanf("%s", s);
	REP(i, 0, nq)
	{
		static int x, y;
		scanf("%d%d", &x, &y), --x;
		begin[x].pb(i), end[y].pb(i);
	}
	int cur = 0;
	REP(i, 0, n) nxt[i] = i + 1, pre[i] = i - 1;
	int Max = -1;
	priority_queue<pair<int, int> > q;
	while (cur < n)
	{
		cur = Max + 1;
		int tmp = cur;
		int way = 1;
		for ( ; ; )
		{
			Max = max(Max, cur);
			REP(i, 0, SZ(begin[cur]))
			{
				if (vis[begin[cur][i]]) continue;
				vis[begin[cur][i]] = 1;
				q.push(mp(cur, begin[cur][i]));
				REP(j, 0, 10) ans[begin[cur][i]][j] = -cnt[j];
			}
			begin[cur].clear();
			REP(i, 0, SZ(end[cur]))
				if (vis[end[cur][i]] == 1)
				{
					vis[end[cur][i]] = 2;
					REP(j, 0, 10) ans[end[cur][i]][j] += cnt[j];
				}
			end[cur].clear();
			while (!q.empty())
			{
				pair<int, int> x = q.top();
				if (x.x <= cur) break;
				q.pop();
				if (vis[x.y] == 2) continue;
				vis[x.y] = 2;
				REP(j, 0, 10) ans[x.y][j] += cnt[j];
			}
			if (cur >= n || cur < tmp) break;		
			if (s[cur] == '<')
			{
				way = -1;
				if (pre[cur] >= 0 && (s[pre[cur]] == '<' || s[pre[cur]] == '>')) del(cur);
				cur = pre[cur];
			}
			else if (s[cur] == '>')
			{
				way = 1;
				if (nxt[cur] < n && (s[nxt[cur]] == '<' || s[nxt[cur]] == '>')) del(cur);
				cur = nxt[cur];
			}
			else
			{
				++cnt[s[cur] - '0'];
				if (--s[cur] < '0') del(cur);
				if (way == -1) cur = pre[cur];
				else cur = nxt[cur];
			}
		}
	}
	REP(i, 0, nq)
	{
		REP(j, 0, 10)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}