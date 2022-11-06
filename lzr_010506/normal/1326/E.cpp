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
#define X first
#define Y second
#define pcc pair<sum2r, sum2r>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define sti set<int>::iterator
#define All(x) (x).begin(), (x).end()
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
const int N = 3e6 + 10, MOD = 998244353;
int n, p[N], q[N], t[N], P[N], sum[N], mx[N];
void insert(int l, int r, int rt, int p, int v)
{
	if(l == r) sum[rt] += v;
	else
	{
	int mid = l + r >> 1;
	if(p <= mid) insert(l, mid, ls, p, v);
	else insert(mid + 1, r, rs, p, v);
	sum[rt] = sum[ls] + sum[rs];
	mx[rt] = max(mx[ls] + sum[rs], mx[rs]);
	}
}

int main()
{
	n = read();
	rep(i, 1, n) p[i] = read();
	rep(i, 1, n) P[p[i]] = i;
	rep(i, 1, n) q[i] = read();
	int now = n;
	insert(1, n, 1, P[n], 1);
	rep(i, 1, n - 1)
	{
		printf("%d ", now);
		insert(1, n, 1, q[i], -1);
		while(max(sum[1], mx[1]) == 0)
		{
			now --;
			insert(1, n, 1, P[now], 1);
		}
	}
	printf("%d\n", now);
	return 0;
}