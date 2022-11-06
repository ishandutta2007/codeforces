#include <bits/stdc++.h>
#define ull unsigned long long
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
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
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
const int N = 2010;
const int M = 210;
const int mod = 998244853;
const ull p1 = 31;
const int p2 = 37;

struct Node
{
	ull x; int y;
	Node(){}
	Node(ull x,int y):x(x),y(y){}
	friend Node operator +(Node a, Node b)
	{
		return Node(a.x + b.x, (a.y + b.y) % mod);
	}
	friend Node operator *(Node a, Node b)
	{
		return Node(a.x * b.x, 1ll * a.y * b.y % mod);
	}
	friend Node operator -(Node a, Node b)
	{
		return Node(a.x - b.x, (a.y - b.y + mod) % mod);
	}
	friend bool operator ==(Node a,Node b)
	{
		return (a.x == b.x && a.y == b.y);
	}
} h1[N * M], h2[N], p[N * M], w;
int n, m, ans, L, R;
int id[N][M];
char s1[N][M], s2[M][N];

Node geth1(int l, int r)
{
	return h1[r] - h1[l - 1] * p[r - l + 1];
}

int main()
{
	n = read();
	m = read();
	rep(i, 1, n) scanf("%s", s1[i] + 1);
	rep(i, 1, m) scanf("%s", s2[i] + 1);
	p[0] = Node(1, 1);
	rep(i, 1, n * m) p[i] = p[i - 1] * Node(p1, p2);
	rep(i, 1, n - m + 1)
	{
		h2[i] = Node(0, 0);
		rep(j, 1, m)
			rep(k, 1, m)
				h2[i] = h2[i] * Node(p1, p2) + Node(s2[j][i + k - 1], s2[j][i + k - 1]);
	}
	rep(i, 1, n)
		rep(j, 1, m)
			id[i][j] = (i - 1) * m + j;
	rep(i, 1, n)
		rep(j, 1, m)
			h1[id[i][j]] = h1[id[i][j] - 1] * Node(p1, p2) + Node(s1[i][j], s1[i][j]);
	rep(i, 1, n - m + 1)
	{
		L = id[i][1];
		R = id[i + m - 1][m];
		w = geth1(L, R);
		rep(j, 1, n - m + 1)
			if (w == h2[j])
			{
				printf("%d %d\n", i, j);
				return 0;
			}
	}
	return 0;
}