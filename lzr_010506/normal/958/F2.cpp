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
const int N = 2e5 + 10;
inline int min(int a, int b)
{
    if(a < b) return a;
    return b;
}
int n, m, ans, mx, sum, a[N], b[N], cnt[N], nxt[N], head[N], pos[N];
bool tag;

int main()
{
	n = read();
	m = read();
	rep(i, 1, n) a[i] = read(), cnt[a[i]] ++;
 	rep(i, 1, m) b[i] = read(), sum += b[i];
 	rep(i, 1, m)
 		if (cnt[i] < b[i])
 		{
			printf("-1\n");
			return 0;
		}
	rep(i, 1, m) head[i] = n + 1;
	rrep(i, n, 1) nxt[i] = head[a[i]], head[a[i]] = i;
	rep(i, 1, m)
	{
		if(!b[i]) continue;
		pos[i] = head[i];
		rep(j, 1, b[i] - 1) pos[i] = nxt[pos[i]];
		mx = max(mx, pos[i]);
	}
	ans = n - sum;
	ans = min(ans, mx - sum);
	rep(i, 1, n - 1)
	{
		pos[a[i]] = nxt[pos[a[i]]];
		mx = max(mx, pos[a[i]]);
		if (mx > n) break;
		ans = min(ans, mx - i - sum);
	}
	printf("%d", ans);
	return 0;
}