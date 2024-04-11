#include <bits/stdc++.h>
#include <math.h>
#define uint unsigned long long
#define ll long long
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
#define ept 1e-9

using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
struct edge
{
	int s,t,id,next;
}e[N << 1];
int head[N],cnt;
void addedge(int s,int t,int id)
{
	e[cnt].s = s;
	e[cnt].t = t;
	e[cnt].id = id;
	e[cnt].next = head[s];
	head[s] = cnt ++;

	e[cnt].s = t;
	e[cnt].t = s;
	e[cnt].id = id;
	e[cnt].next = head[t];
	head[t] = cnt ++;
}
int n,m,u,v,rt;
bool vis[N],vis2[N];
int d[N];
vector<int> ans;
int getf(int node)
{
	vis2[node] = 1;
	if (d[node] == -1) return node;
	int ret = -1;
	for (int i = head[node]; i != -1; i = e[i].next)
		if (!vis2[e[i].t])
			ret = max(ret, getf(e[i].t));
	return ret;
}
void dfs(int node, int fa)
{
	vis[node] = 1;
	for (int i = head[node]; i != -1; i = e[i].next)
		if (!vis[e[i].t])
			dfs(e[i].t, i);
	if (d[node] == 1 && fa != -1)
	{
		ans.pb(e[fa].id);
		d[node] ^= 1;
		if (d[e[fa].s] != -1) d[e[fa].s] ^= 1;
	}
}
int main()
{
	n = read();
	m = read();
	rep(i, 1, n) d[i] = read();
	memset(head, -1, sizeof(head));
	rep(i, 1, m)
	{
		u = read();
		v = read();
		addedge(u, v, i);
	}
	rep(i, 1, n)
		if (!vis[i])
		{
			rt = getf(i);
			if (rt != -1) dfs(rt, -1);
			else
			{
				dfs(i, -1);
				if (d[i] == 1)
				{
					puts("-1");
					return 0;
				}
			}
		}
	int nn = ans.size();
	printf("%d\n", nn);
	rep(i, 0, nn - 1)
		printf("%d ",ans[i]);
	return 0;
}