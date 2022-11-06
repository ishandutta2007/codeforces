#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
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
int ans;
ll w[20], ansa, ansb, ansc;

void dfs(ll a, ll b, ll c, ll nowa, ll nowb, ll jin, int nowl, int wei)
{
	if(nowl >= ans) return;
	if(!a && !b && !c && !jin) {ans = nowl; ansa = nowa; ansb = nowb; return;}
	if(!c)
	{
		int tot = 0;
		ll nw = jin + a + b;
		while(nw)
		{
			tot ++;
			nw /= 10;
		}
		dfs(0, 0, 0, nowa + a * w[wei], nowb + b * w[wei], 0, nowl + tot, wei);
		return;
	}
	if((a + b + jin) % 10 == c % 10)
		dfs(a / 10, b / 10, c / 10, nowa + a % 10 * w[wei], nowb + b % 10 * w[wei], (a % 10 + b % 10 + jin) / 10, nowl, wei + 1);
	else
	{
		dfs(a * 10 + (c + 10 - b % 10 - jin) % 10, b, c, nowa, nowb, jin, nowl + 1, wei);
		dfs(a, b * 10 + (c + 10 - a % 10 - jin) % 10, c, nowa, nowb, jin, nowl + 1, wei);
		dfs(a, b, c * 10 + (a + b + jin) % 10, nowa, nowb, jin, nowl + 1, wei);
	}
}
int a, b, c;
int main()
{
	scanf("%d+%d=%d", &a, &b, &c);
	w[0] = 1;
	ans = 12;
	rep(i, 1, 18) w[i] = w[i - 1] * 10;
	dfs(a, b, c, 0, 0, 0, 0, 0);
	printf("%I64d+%I64d=%I64d", ansa, ansb, ansa + ansb);
	return 0;
}