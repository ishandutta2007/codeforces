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
#define ALL(x) (x).begin(), (x).end()
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
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
using namespace std;
int n, ans[100005], id;
bool check(int x)
{
	printf("? %d %d\n", x, 1);
	rep(i, 1, x) printf("%d ", i);
	printf("\n%d\n", id);
	fflush(stdout);
	int q = read();
	return q != 0;
}
int main()
{
	int T = read();
	while (T --)
	{
		int n = read();
		rep(i, 1, n) ans[i] = 0;
		id = -1;
		rep(i, 2, n)
		{
			printf("? %d %d\n", i - 1, 1);
			rep(j, 1, i - 1) printf("%d ", j);
			printf("\n%d\n", i);
			fflush(stdout);
			int q = read();
			if (q)
			{
				id = i;
				break;
			}
		}
		ans[id] = 1;
		rep(i, id + 1, n)
		{
			printf("? 1 1\n%d\n%d\n", id, i);
			fflush(stdout);
			int q = read();
			if (q) ans[i] = 1;
		}
		int l = 1, r = id, mid;
		while (l < r)
		{
			mid = (l + r) >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		ans[l] = 1;
		int ct = 0;
		rep(i, 1, n)
			if (!ans[i])
				ct++;
		printf("! %d ", ct);
		rep(i, 1, n)
			if (!ans[i])
				printf("%d ", i);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}