#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
const int mod = 1e9 + 7;
 
const int MN = 305;
const int Inf = 1000000000;
 
struct edge 
{
	int a, b, cap, cost;
	edge(int a = 0, int b = 0, int cap = 0, int cost = 0): a(a), b(b), cap(cap), cost(cost) {}
};
 
int n, q;
int T;
int L[MN], R[MN];
vector <edge> E;
vector <int> neigh[MN];
int dist[MN], par[MN];
 
void addEdge(int a, int b, int cap, int cost)
{
	neigh[a].pb(sz(E)); E.pb(edge(a, b, cap, cost));
	neigh[b].pb(sz(E)); E.pb(edge(b, a, 0, -cost));
}
 
bool getFlow(int &res)
{
	fill(dist, dist + T, Inf); 
	dist[0] = 0;
	priority_queue <pii> Q; 
	Q.push(mp(-dist[0], 0));
	while (!Q.empty()) 
	{
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (dist[v] != d) continue;
		rep0(i, sz(neigh[v]))
		{
			int e = neigh[v][i];
			if (E[e].cap > 0 && d + E[e].cost < dist[E[e].b]) 
			{
				dist[E[e].b] = d + E[e].cost; par[E[e].b] = e;
				Q.push(mp(-dist[E[e].b], E[e].b));
			}
		}
	}
	int v = T - 1;
	if (dist[v] >= Inf) return false;
	res = dist[v];
	while (v)
	{
		int e = par[v];
		E[e].cap --; 
		E[e ^ 1].cap ++;
		v = E[e].a;
	}
	return true;
}
 
int main()
{
	n = read();
	q = read();
	T = 2 + 2 * n;
	rep(i, 1, n) L[i] = 1, R[i] = n;
	while (q --) 
	{
		int t = read();
		int l = read();
		int r = read();
		int v = read();
		if (t == 1)	rep(i, l, r) L[i] = max(L[i], v);
		else rep(i, l, r) R[i] = min(R[i], v);
	}
	rep(i, 1, n)
	{
		addEdge(0, i, 1, 0);
		if (L[i] > R[i]) { puts("-1"); return 0; }
		rep(j, L[i], R[i]) addEdge(i, n + j, 1, 0);
	}
	rep(i, 1, n)
		rep(j, 1, n)
			addEdge(n + i, T - 1, 1, 2 * j - 1);
	int res = 0, add;
	while (getFlow(add)) res += add;
	printf("%d\n", res);
	return 0;
}