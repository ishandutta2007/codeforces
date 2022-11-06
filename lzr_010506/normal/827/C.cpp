#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X firch
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define eps 1e-9
using namespace std;
const int N = 2e6 + 10;
const int MOD = 1e9 + 9;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, k, a[N];
char ch[N];
int pd_ch(char c)
{
	if(c == 'A') return 0;
	if(c == 'G') return 1;
	if(c == 'C') return 2;
	return 3;
}
int c[11][11][5][100010];
inline int lowbit(int x)
{
	return x & (-x);
}
void Add(int x, int y, int z, int k, int t)
{
	while(k <= n)
	{
		c[x][y][z][k] += t;
		k += lowbit(k);
	}
}
int Query(int x,int y,int z,int k)
{
	int ret = 0;
	while(k)
	{
		ret += c[x][y][z][k];
		k -= lowbit(k);
	}
	return ret;
}
int main()
{
	scanf("%s", ch + 1);
	n = strlen(ch + 1);
	rep(i, 1, n)
	{
		a[i] = pd_ch(ch[i]);
		rep(j, 1, 10) Add(j, i % j, a[i], i, 1);
	}
	int Q = read();
	rep(q, 1, Q)
	{
		int op = read();
		if(op == 1)
		{
			int x;
			char c;
			scanf("%d %c", &x, &c);
			int p = pd_ch(c);
			rep(i, 1, 10)
                Add(i, x % i, a[x], x, -1), Add(i, x % i, p, x, 1);
			a[x] = p;
		}
		else
		{
			int l, r, len;
			l = read();
			r = read();
			scanf("%s", ch + 1);
			len = strlen(ch + 1);
			int ans = 0;
			rep(i, 1, len)
				ans += Query(len, (l + i - 1) % len, pd_ch(ch[i]), r) - Query(len, (l + i - 1) % len, pd_ch(ch[i]), l - 1);
			cout << ans << endl;
		}
	}
	return 0;
}