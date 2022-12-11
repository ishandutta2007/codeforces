#include <bits/stdc++.h>
 
using namespace std;
 
template<class T, class U>
void ckmin(T &a, U b)
{
	if (a > b) a = b;
}
template<class T, class U>
void ckmax(T &a, U b)
{
	if (a < b) a = b;
}
 
#define y1 eroschnit
#define y2 preparation
#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) ((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define MAXN 213
#define MAXM 100013
#define INF 1000000007
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
int N, X, Y;
vi compress;
array<int, 4> rect[MAXN];
vi xs, ys;
bitset<MAXN> flag[MAXN];
 
int E = 2, S, T;
int to[MAXM], link[MAXM], cap[MAXM];
int head[MAXN], dist[MAXN];
bitset<MAXN> seen;
int ans;
 
void addedge(int u, int v, int c)
{
	to[E] = v;
	link[E] = head[u];
	head[u] = E;
	cap[E] = c;
	E++;
	to[E] = u;
	link[E] = head[v];
	head[v] = E;
	cap[E] = 0;
	E++;
}
bool bfs()
{
	FOR(i, 0, T + 1)
	{
		dist[i] = INF;
		seen[i] = false;
	}
 	dist[S] = 0;
	queue<int> q; q.push(S);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for (int e = head[u]; e; e = link[e])
		{
			int v = to[e];
			if (cap[e] == 0) continue;
			if (dist[v] > dist[u] + 1)
			{
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return (dist[T] != INF);
}
int aug(int u, int f)
{
	if (u == T)
	{
		return f;
	}
	seen[u] = true;
	int cur = 0;
	for (int e = head[u]; e; e = link[e])
	{
		int v = to[e];
		if (dist[v] != dist[u] + 1) continue;
		if (cap[e] == 0) continue;
		if (seen[v]) continue;
		int gain = aug(v, min(cap[e], f));
		cap[e] -= gain;
		cap[e ^ 1] += gain;
		cur += gain;
		f -= gain;
	}
	return cur;
}
int maxflow()
{
	int res = 0;
	while(true)
	{
		if (!bfs()) return res;
		res += aug(S, INF);
	}
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> N;
	if (N == 0) 
	{
	    cout << "0\n"; return 0;
	}
	FOR(i, 0, N)
	{
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; x2++; y2++;
		xs.PB(x1); xs.PB(x2); ys.PB(y1); ys.PB(y2);
		rect[i] = {x1, x2, y1, y2};
	}
	sort(ALL(xs)); xs.erase(unique(ALL(xs)), xs.end()); X = SZ(xs) - 1;
	sort(ALL(ys)); ys.erase(unique(ALL(ys)), ys.end()); Y = SZ(ys) - 1;
	FOR(i, 0, N)
	{
		FOR(j, 0, 2)
		{
			rect[i][j] = LB(ALL(xs), rect[i][j]) - xs.begin();
		}
		FOR(j, 2, 4)
		{
			rect[i][j] = LB(ALL(ys), rect[i][j]) - ys.begin();
		}
		FOR(j, rect[i][0], rect[i][1])
		{
			FOR(k, rect[i][2], rect[i][3])
			{
				flag[j][k] = true;
			}
		}
	}
	FOR(i, 0, X)
	{
		FOR(j, 0, Y)
		{
			if (!flag[i][j]) continue;
			addedge(i, X + j, INF);
		}
	}
	S = X + Y; T = X + Y + 1;
	FOR(i, 0, X)
	{
		addedge(S, i, xs[i + 1] - xs[i]);
	}
	FOR(i, 0, Y)
	{
		addedge(X + i, T, ys[i + 1] - ys[i]);
	}
	ans = maxflow();
	cout << ans << '\n';
	return 0;
}