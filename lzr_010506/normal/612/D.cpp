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
const int mod = 998244353;
const int N = 2e6 + 10;
struct Node
{
	int x, y;
}a[N];

bool cmp(Node a, Node b)
{
	if(a.x == b.x) return a.y > b.y;
	return a.x < b.x;
}
int Ans[N];
int main()
{
	int n = read();
	int m = read();
	int len = 0;
	rep(i, 1, n)
	{
		a[len].x = read();
		a[len + 1].x = read();
		a[len ++].y = 1;//st
		a[len ++].y = 0;//ed
	}
	sort(a, a + len, cmp);
	int ans = 0, sum = 0;
	rep0(i, len)
	{
		if(a[i].y)
		{
			sum ++;
			if(sum == m) Ans[ans ++] = a[i].x;
		}
		else
		{
			if(sum == m) Ans[ans ++] = a[i].x;
			sum --;
		}
	}
	printf("%d\n", ans / 2);
	rep0(i, ans)
	{
		printf("%d ", Ans[i]);
		if(i % 2 == 1) puts("");
	}
}