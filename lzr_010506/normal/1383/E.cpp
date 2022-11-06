#include <bits/stdc++.h>
#define pcc pair<char, char>
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define mp make_pair
#define pb push_back
#define ls rt << 1
#define rs rt << 1 | 1
#define F first
#define S second
#define X first
#define Y second
#define eps 1e-9
#define inf 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ll long long
#define db double
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
bool f1, f2;
int a[N], n, m, b[N << 2], sum[N], pos[N], dp[N];
char s[N];
int qry(int l, int r, int rt, int x, int y) 
{
	if(x <= l && r <= y) return b[rt];
	int mid = l + r >> 1;
	int ans = 0;
	if(x <= mid) ans = max(ans, qry(l, mid, ls, x, y));
	if(y > mid) ans = max(ans, qry(mid + 1, r, rs, x, y));
	return ans;
}
void modify(int l, int r, int rt, int x, int y) 
{
	if(l == r) {b[rt] = max(b[rt], y); return;}
	int mid = l + r >> 1;
	if(x <= mid) modify(l, mid, ls, x, y);
	else modify(mid + 1, r, rs, x, y);
	b[rt] = max(b[ls], b[rs]);
}
inline int lowbit(int x)
{
	return x & (-x);
}
int qry(int x)
{
    int ret = 0;
    while (x < N)
    {
        ret = max(ret, b[x]);
        x += x & (-x);
    }
    return ret;
}
void modify(int x,int y)
{
    while (x)
    {
        b[x] = max(b[x],y);
        x -= x & (-x);
    }
}
int main() 
{
	scanf("%s", s + 1);
	m = strlen(s + 1);
	rep(i, 1, m) if (s[i] == '1') pos[++ n] = i;
	if (n == 0) {cout << m << endl; return 0;}
	rep(i, 1, n) a[i] = pos[i] - pos[i - 1] - 1;
	a[n + 1] = m - pos[n]; 
	n ++;
	int res = 1ll * (a[1] + 1) * (a[n] + 1) % mod;
	n -= 2;
	rep(i, 1, n) a[i] = a[i + 1];
	dp[0] = 1; sum[0] = 1;
	rep(i, 1, n)
	{
		dp[i] = dp[i - 1];
		rep(j, 1, a[i])
		{
			//int x = qry(1, n, 1, 1, j);
			int x = qry(j);
			(dp[i] += sum[i - 1]) %= mod;
			if (x > 0) dp[i] -= sum[x - 1];
			if (dp[i] < 0) dp[i] += mod;
			dp[i] %= mod;
		}
		sum[i] = sum[i - 1];
		(sum[i] += dp[i]) %= mod;
		modify(a[i], i);
		//modify(1, n, 1, a[i], i);
	}
	printf("%lld\n", 1ll * sum[n] * res % mod);
	return 0;
}