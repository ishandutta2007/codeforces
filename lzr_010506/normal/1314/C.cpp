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
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define mpi map<int,vector<int> > ::iterator
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
int n, m, lcp[N][N];
ll k;
char s[N];

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	int l = lcp[a.X][b.X], l1 = a.Y - a.X + 1, l2 = b.Y - b.X + 1;
	l = min(l, min(l1, l2));
	int n1 = (l == l1 ? 0 : s[a.X + l]), n2 = (l == l2 ? 0 : s[b.X + l]);
	return n1 < n2;
}

ll dp[N][N];
const ll MAGIC = 1000000000000000000ll;
bool check(pair<int, int> sub)
{
	memset(dp, 0, sizeof(dp));
	dp[n + 1][0] = 1;
	rrep(i, n, 1)
	{
		int bound = 0;
		if (cmp(mp(i, n), sub)) bound = n + 1;
		else
		{
			int lv = min(lcp[i][sub.X], sub.Y - sub.X + 1);
			if (lv == sub.Y - sub.X + 1) bound = i + lv - 1;
			else bound = i + lv;
		}
		rep(j, 1, m)
			dp[i][j] = dp[bound + 1][j - 1];
		if (i == 1)
			return (dp[1][m] >= k);
		rep(j, 0, m)
		{
			dp[i][j] += dp[i + 1][j];
			if (dp[i][j] > MAGIC)
				dp[i][j] = MAGIC;
		}
	}
}

int main()
{
	n = read();
	m = read();
	k = read1();
	scanf("%s", s + 1);
	rrep(i, n, 1)
		rrep(j, n, 1)
			lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
	vector<pii> sub;
	rep(i, 1, n)
		rep(j, i, n)
			sub.pb(mp(i, j));
	sort(ALL(sub), cmp);
	int lb = 0, rb = sub.size(), mid;
	while (lb < rb - 1)
	{
		mid = (lb + rb) / 2;
		if (check(sub[mid]))
			lb = mid;
		else
			rb = mid;
	}
	rep(i, sub[lb].X, sub[lb].Y)
		putchar(s[i]);
	puts("");
	return 0;
}