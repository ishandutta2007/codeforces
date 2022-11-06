#include <bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define LG 17
using namespace std;
const int N = 4000010;
const ll inf = 1e18;
int n, q, s, cnt;
int U[100010][LG], V[100010][LG], lg[100010];
ll dis[N];
priority_queue<pair<ll, int> >Q;
vector<pair<int, int> > mp[N];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void insert(int u, int v, int w)
{
	mp[u].push_back(make_pair(v, w));
}

void Build()
{
	for(int i = 0; i < LG; i ++)
		for(int j = 1; j + (1 << i) - 1 <= n; j ++)
			U[j][i] = ++ cnt;
	for(int i = 0; i < LG; i ++)
		for(int j = 1; j + (1 << i) - 1 <= n; j ++)
			V[j][i] = ++ cnt;
	for(int i = 1; i <= n; i ++)
		insert(U[i][0], V[i][0], 0),
		insert(V[i][0], U[i][0], 0);
	for(int i = 1; i < LG; i ++)
		for(int j = 1; j + (1 << i) - 1 <= n; j ++)
			insert(V[j][i], V[j][i - 1], 0),
			insert(V[j][i], V[j + (1 << i - 1)][i - 1], 0),
			insert(U[j][i - 1], U[j][i], 0),
			insert(U[j + (1 << i - 1)][i - 1], U[j][i], 0);
	for(int i = 0; i < LG; i ++)
		for(int j = 1 << i; j < (1 << i + 1) && j <= n; j ++)
			lg[j] = i;
}

void dijks()
{
	for(int i = 1; i <= cnt; i ++)
        dis[i] = inf;
	dis[U[s][0]] = 0;
	Q.push(make_pair(-dis[U[s][0]], U[s][0]));
	while(!Q.empty())
	{
		int u = Q.top().Y;
		ll Dis = -Q.top().X;
		Q.pop();
		if(dis[u] != Dis)continue;
		for(int i = 0; i < mp[u].size(); i ++)
        {
            pair<int, int> v = mp[u][i];
			if(Dis + v.Y < dis[v.X])
			{
				dis[v.X] = Dis + v.Y;
				Q.push(make_pair(-dis[v.X],v.X));
			}
        }
	}

}

int main()
{
	n = read();
	q = read();
	s = read();
	Build();
	while(q --)
	{
		int op = read();
		if(op == 1)
		{
			int u = read();
			int v = read();
			int w = read();
			insert(U[u][0], U[v][0], w);
			insert(V[u][0], V[v][0], w);
		}
		if(op == 2)
		{
			int u = read();
			int l = read();
			int r = read();
			int w = read();
			int len = r - l + 1;
			insert(U[u][0], V[l][lg[len]], w);
			insert(U[u][0], V[r - (1 << lg[len]) + 1][lg[len]], w);
		}
		if(op == 3)
		{
			int u = read();
			int l = read();
			int r = read();
			int w = read();
			int len = r - l + 1;
			insert(U[l][lg[len]], V[u][0], w);
			insert(U[r - (1 << lg[len]) + 1][lg[len]], V[u][0], w);
		}
	}
	dijks();
	for(int i = 1; i <= n; i ++)
		if(dis[U[i][0]] == inf) printf("-1 ");
		else printf("%I64d ",dis[U[i][0]]);

	return 0;
}
//n 1-n u->v v->[l,r] [l,r]->v  