#include <bits/stdc++.h>
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
const int N = 1e4 + 10;
const int mod = 1e9 + 7;

struct Matrix
{
	ll v[3][3];
	Matrix() { memset(v, 0, sizeof v); }
	friend Matrix operator*(const Matrix &a, const Matrix &b)
	{
		Matrix c;
		rep(i, 0, 2)
			rep(j, 0, 2)
				rep(k, 0, 2)
					(c.v[i][k] += a.v[i][j] * b.v[j][k]) %= mod;
		return c;
	}
	friend Matrix operator^(Matrix a, ll n)
	{
		Matrix ans;
		rep(i, 0, 2) ans.v[i][i] = 1;
		while(n)
		{
			if(n & 1) ans = ans * a;
			a = a * a;
			n >>= 1;
		}
		return ans;
	}
};

struct Node
{
	ll pos;
	int a, op;
	bool operator<(const Node &e) const
	{
		return pos < e.pos;
	}
}b[2 * N];

int main()
{
	int n = read();
	ll m = read1();
	int j = 0;
	rep(i, 1, n)
	{
		int a = read();
		ll l = read1();
		ll r = read1();
		a --;
		b[j ++] = (Node){l, a, 1};
		b[j ++] = (Node){r + 1, a, -1};
	}
	b[2 * n] = (Node){m + 1, 0, 0};
	b[2 * n + 1] = (Node){2, 0, 0};
	sort(b, b + (n = 2 * n + 2));
	Matrix ans;
	int num[3] = {0, 0, 0};
	rep(i, 0, 2) ans.v[i][i] = 1;
	for (int i = 0; i < n - 1;)
	{
		ll t = b[i].pos;
		while (i < n - 1 && b[i].pos == t)
		{
			num[b[i].a] += b[i].op;
			++i;
		}
		Matrix y;
		y.v[0][0] = y.v[1][0] = !num[0];
		y.v[0][1] = y.v[1][1] = y.v[2][1] = !num[1];
		y.v[1][2] = y.v[2][2] = !num[2];
		ans = ans * (y ^ (b[i].pos - t));
	}
	printf("%I64d", ans.v[1][1]);
	return 0;
}