#include <bits/stdc++.h>
#include <ctime>
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
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
using namespace std;
 
const int N = 205, M = 20005 << 1;
 
int n, m, p, s, t;
 
int top, head[N], to[M], nxt[M], c[M], l[M];
 
void addedge(int u, int v, int cap, int len) {
	to[top] = v, nxt[top] = head[u], c[top] = cap, l[top] = len, head[u] = top++;
}
 
vector<pair<int, int> > paths;
 
int dis[N], fa[N];
 
bool inque[N];
 
const int INF = 1000000000;
 
bool go(int source, int target) {
	for (int i = 0; i < n; ++i) {
		dis[i] = INF;
	}
	dis[source] = 0;
	inque[source] = true;
	queue<int> q;
	q.push(source);
	while (q.size()) {
		int u = q.front();
		inque[u] = false;
		q.pop();
		for (int i = head[u]; ~i; i = nxt[i]) {
			if (c[i]) {
				int v = to[i], nd = dis[u] + l[i];
				if (dis[v] > nd) {
					dis[v] = nd;
					fa[v] = i;
					if (!inque[v]) {
						inque[v] = true;
						q.push(v);
					}
				}
			}
		}
	}
	if (dis[target] == INF) {
		return false;
	}
	int f = INF;
	int u = target;
	while (u != source) {
		int e = fa[u];
		f = min(f, c[e]);
		u = to[e ^ 1];
	}
	paths.push_back(make_pair(f, dis[target]));
	u = target;
	while (u != source) {
		int e = fa[u];
		c[e] -= f, c[e ^ 1] += f;
		u = to[e ^ 1];
	}
	return true;
}
 
int main() 
{
	n = read();
	m = read();
	s = 0;
	t = n - 1;
	top = 0;
	memset(head, -1, sizeof(head));
	rep0(i, m)
	{
		int u = read();
		int v = read();
		int d = read();
		--u, --v;
		addedge(u, v, 1, d);
		addedge(v, u, 0, -d);
	}
	while (go(s, t)) {
		continue;
	}
	int Q = read();
	while(Q --)
	{
		p = read();
			int csum = 0, fsum = 0;
		rep0(i, sz(paths))
		{
			csum += paths[i].first * paths[i].second;
			fsum += paths[i].first;
			double ans = (double)(p + csum) / fsum;
			if (i + 1 == paths.size() || ans < paths[i + 1].second) {
				printf("%.12f\n", ans);
				break;
			}
		}
	}
	
	return 0;
}