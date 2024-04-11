#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define ld long double
#define db double
#define rs x << 1 | 1
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
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

#define N 2000010
struct Prob
{
	db gl;
	int ss, ls, st, lt;
	void in()
	{
		cin >> ss >> ls >> st >> lt >> gl;
	}
	bool operator<(const Prob &nd) const
	{
		return lt * gl * (1 - nd.gl) < nd.lt * nd.gl * (1 - gl);
	}
} a[N];
struct Node
{
	ld s, p;
	Node(){}
	Node(ld _s, ld _p)
	{
		s = _s, p = _p;
	}
	Node operator +(const Node &nd) const
	{
		return Node(s + nd.s, p + nd.p);
	}
} dp[N];
Node max1(const Node &a, const Node &b)
{
	if (fabs(a.s - b.s) > eps) return a.s > b.s ? a : b;
	return a.p < b.p ? a : b;
}
int n, t;
int main()
{
	n = read();
	t = read();
	rep(i, 1, n + 1) a[i].in();
	sort(a + 1, a + 1 + n);
	rep(i, 1, n + 1)
		rrep(j, t, a[i].st)
		{
			dp[j] = max1(dp[j], dp[j - a[i].st] + Node(a[i].ss, a[i].st));
			if (j >= a[i].st + a[i].lt)
				dp[j] = max1(dp[j],
					Node(dp[j - a[i].st - a[i].lt].s + a[i].ss + (1 - a[i].gl) * a[i].ls,
							a[i].gl * dp[j - a[i].st - a[i].lt].p + (1 - a[i].gl) * (j - a[i].st) + a[i].st));
		}

	Node ans(0, 0);
	rep(i, 0, t + 1) ans = max1(ans, dp[i]);
	printf("%.10lf %.10lf", (double)ans.s, (db)ans.p);
	return 0;
}