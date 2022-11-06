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
#define pll pair<ll, ll>
#define X first
#define Y second
#define py pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define Alsls(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
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
const int N = (1e2 + 7) * 26, M = N * 100, inf = 0x3f3f3f3f;
struct Edge 
{
	int from, to, next, v, c;
} e[M]; 
int head[N], b[N], c[N];
int cnt = 1, S, T, n, j, inq[N], q[N], from[N], t, w, dis[N], ans, i; 
char s[N];
void ins(int u, int v, int w, int c) 
{
	e[++ cnt].from = u; 
	e[cnt].to = v;
	e[cnt].v = w; 
	e[cnt].c = c;
	e[cnt].next = head[u]; 
	head[u] = cnt;
}
void insert(int u, int v, int w, int c)
{
	ins(u, v, w, c); 
	ins(v, u, 0, -c);
}
bool spfa() 
{
	rep0(i, T + 1) dis[i] = -inf;
	t = 0, w = 1; 
	dis[S] = 0; 
	inq[S] = 1; 
	q[0] = S;
	while (t != w) 
	{
		int now = q[t++]; 
		if (t == N) t = 0; 
		inq[now] = 0;
		for (int i = head[now]; i; i = e[i].next)
			if (e[i].v && dis[now] + e[i].c > dis[e[i].to]) 
			{
				dis[e[i].to] = dis[now] + e[i].c;
				from[e[i].to] = i;
				if (!inq[e[i].to]) 
				{
					inq[e[i].to] = 1;
					q[w ++] = e[i].to;
					if (w == N) w = 0;
				}
			}
	}
	if (dis[T] == -inf)return 0;
	return 1;
}
void mncf() 
{
	int sum = inf;
	for (int i = from[T]; i; i = from[e[i].from])
		sum = min(sum, e[i].v);
	for (int i = from[T]; i; i = from[e[i].from]) 
	{
		e[i].v -= sum;
		e[i ^ 1].v += sum;
		ans += sum * e[i].c;
	}
}
int main() 
{
	n = read();
	scanf("%s", s + 1);
	rep(i, 1, n) b[s[i] - 'a' + 1] ++, c[i] = read(); 
	S = 0; T = n + n * 26 / 2 + 26 + 1;
	rep(i, 1, 26) insert(S, n + n * 26 / 2 + i, b[i], 0);
	rep(i, 1, n) insert(i, T, 1, 0);
	rep(i, 1, n / 2)
	{
		rep(j, 1, 26) insert(n + n * 26 / 2 + j, n + (i - 1) * 26 + j, 1, 0);
		rep(j, 1, 26)
		{
			if (j == s[i] - 'a' + 1) insert(n + (i - 1) * 26 + j, i, 1, c[i]); 
			else insert(n + (i - 1) * 26 + j, i, 1, 0);
			if (j == s[n - i + 1] - 'a' + 1) insert(n + (i - 1) * 26 + j, n + 1 - i, 1, c[n + 1 - i]);
			else insert(n + (i - 1) * 26 + j, n + 1 - i, 1, 0);
		}
	}
	while (spfa())mncf();
	return cout << ans << endl, 0;
}