#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MAXN = 100010;
const int INF = 1000000000;

int n, m, k;
map<pii, int> H;
set<int> Hx[MAXN], Hy[MAXN];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int place(int x, int y)
{
	if (!H.count(pii(x, y)))
	{
		int cur = H.size();
		H[pii(x, y)] = cur+1;
	}
	return n+m+H[pii(x, y)];
}

int row(int x)
{
	return x;
}

int column(int y)
{
	return n+y;
}

vector<pii> v[MAXN];

void addedge(int x, int y, int c)
{
	//printf("%d %d %d\n", x, y, c);
	v[x].push_back(pii(y, c));
}

int F[MAXN], pre[MAXN];

int main()
{
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; ++ i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		H[pii(x, y)] = i;
		Hx[x].insert(y);
		Hy[y].insert(x);
	}
	
	for (auto pp : H)
	{
		auto p = pp.X;
		for (int k = 0; k < 4; ++ k)
		{
			int tx = p.X+dx[k], ty = p.Y+dy[k];
			if (1 <= tx && tx <= n && 1 <= ty && ty <= m)
				if (H.count(pii(tx, ty)))
					addedge(place(p.X, p.Y), place(tx, ty), 0);
		}
		addedge(place(p.X, p.Y), row(p.X), 1);
		addedge(place(p.X, p.Y), column(p.Y), 1);
		addedge(row(p.X), place(p.X, p.Y), 0);
		addedge(column(p.Y), place(p.X, p.Y), 0);
		if (p.X >= 2)
		{
			addedge(place(p.X, p.Y), row(p.X-1), 1);
			addedge(row(p.X-1), place(p.X, p.Y), 0);
		}
		if (p.X <= n-1)
		{
			addedge(place(p.X, p.Y), row(p.X+1), 1);
			addedge(row(p.X+1), place(p.X, p.Y), 0);
		}
		if (p.Y >= 2)
		{
			addedge(place(p.X, p.Y), column(p.Y-1), 1);
			addedge(column(p.Y-1), place(p.X, p.Y), 0);
		}
		if (p.Y <= m-1)
		{
			addedge(place(p.X, p.Y), column(p.Y+1), 1);
			addedge(column(p.Y+1), place(p.X, p.Y), 0);
		}
	}
	addedge(row(n), place(n, m), 0);
	addedge(column(m), place(n, m), 0);
	
	//if (n-1 >= 1) addedge(row(n-1), place(n, m), 0);
	//if (m-1 >= 1) addedge(column(m-1), place(n, m), 0);
	
	
	priority_queue<pii, vector<pii >, greater<pii > > Q;
	int tot = n+m+H.size();
	for (int i = 1; i <= tot; ++ i)
		F[i] = INF;
	F[place(1, 1)] = 0;
	Q.push(make_pair(0, place(1, 1)));
	while (!Q.empty())
	{
		int d = Q.top().X;
		int x = Q.top().Y;
		Q.pop();
		if (F[x] != d) continue;
		for (auto y : v[x])
			if (F[y.X] > d+y.Y)
			{
				pre[y.X] = x;
				F[y.X] = d+y.Y;
				Q.push(pii(F[y.X], y.X));
			}
	}
	if (F[place(n, m)] != INF)
		printf("%d\n", F[place(n, m)]);
	else
		puts("-1");
	
	return 0;
}