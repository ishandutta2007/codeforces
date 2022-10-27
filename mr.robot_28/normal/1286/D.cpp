#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
int n;
const int N = 1e5 + 100;
int x[N], v1[N], p[N][2];
const int mod = 998244353;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b % 2 == 0)
	{
		int t = power(a , b / 2);
		return t * t % mod;
	}
	return a * power(a, b - 1) % mod;
}
struct node{
	int id;
	bool d1, d2;
	int x, y;
}cra[N << 1];
bool cmp(node a, node b)
{
	return a.x * b.y < b.x * a.y;
}
struct matrix{
	int a[2][2];
	matrix operator * (const matrix x1)const{
		matrix res;
		for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				res.a[i][j] = 0;
				for(int k = 0; k < 2; k++)
				{
					res.a[i][j] = (res.a[i][j] + a[i][k] * x1.a[k][j]) % mod;
				}
			}
		}
		return res;
	}
}lim[N];
matrix Tree[N << 2];
void build(int v, int l, int r)
{
	if(l == r)
	{
		Tree[v] = lim[l];
		return;
	}
	int m = (r + l) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m + 1, r);
	Tree[v] = Tree[v * 2] * Tree[v * 2 + 1];
}
void update(int v, int l, int r, int idx, matrix val)
{
	if(l == r)
	{
		Tree[v] = val;
		return;
	}
	int m = (r + l) / 2;
	if(idx <= m)
	{
		update(v * 2, l, m, idx, val);
	}
	else
	{
		update(v * 2 + 1, m + 1, r, idx, val);
	}
	Tree[v] = Tree[v * 2] * Tree[v * 2 + 1];
}

signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n;
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	int tot = 0;
	int inv = power(100, mod - 2);
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i] >> v1[i] >> p[i][1];
		p[i][1] = p[i][1] * inv % mod;
		p[i][0] = (1 - p[i][1] + mod) % mod;
		if(i > 1)
		{
			cra[++tot] = (node){i, 1, 0, x[i] - x[i - 1], v1[i] + v1[i - 1]};
			if(v1[i - 1] > v1[i])
			{
				cra[++tot] = (node){i, 1, 1, x[i] - x[i - 1], v1[i - 1] - v1[i]};
			}
			if(v1[i] > v1[i - 1])
			{
				cra[++tot] = (node){i, 0, 0, x[i] - x[i - 1], v1[i] - v1[i - 1]};
			}
		}
	}
	sort(cra + 1, cra + tot + 1, cmp);
	lim[1].a[0][0] = p[1][0];
	lim[1].a[0][1] = p[1][1];
	lim[1].a[1][0] = lim[1].a[1][1] = 0;
	for(int i = 2; i <= n; i++)
	{
		lim[i].a[0][0] = lim[i].a[1][0] = p[i][0];
		lim[i].a[0][1] = lim[i].a[1][1] = p[i][1];
	}
	int ans = 0;
	build(1, 1, n);
	int last = 1;
	for(int i = 1; i <= tot; i++)
	{
		int id = cra[i].id;
		int tim = cra[i].x * power(cra[i].y, mod - 2) % mod;
		lim[id].a[cra[i].d1][cra[i].d2] = 0;
		update(1, 1, n, id, lim[id]);
		int p = (Tree[1].a[0][0] + Tree[1].a[0][1]) % mod;
		ans = (ans + tim * (last - p + mod)) % mod;
		last = p;
	}
	cout << ans;
	return 0;
}