#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
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

const int N = 323456;

int a[N];
int f[N];
vector<int> q[N];

int lowbit(int x)
{
    return x & -x;
}

void update(int rt)
{
	while(rt < N)
	{
		f[rt] ++;
		rt += lowbit(rt);
	}
}

int get(int rt)
{
	int s = 0;
	while(rt)
	{
		s += f[rt];
		rt -= lowbit(rt);
	}
	return s;
}

int main()
{
	int n = read();
	rep(i, 0, n - 1)
	{
		a[i] = read();
		q[min(a[i] - 1, n - 1)].pb(i);
	}
	ll ans = 0;
	rep(i, 0, n - 1)
	{
		update(min(a[i], 250000));
		for (int x : q[i])
			ans += i + 1 - get(x);

	}
	rep(i, 0, n - 1)
		if (a[i] > i)
			ans--;
	printf("%lld\n", ans / 2);
	return 0;
}