#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll long long
#define X first
#define Y second
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
using namespace std;

const int N = 200010;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, k, m, ans;
int a[N], cnt[1000110];
deque<int> q;
int main()
{
    n = read();
    m = read();
    k = read();
    rep(i, 1, n) a[i] = read();
    rep(i, 1, n) cnt[a[i]] ++;
    rep(i, 1, 1000000)
    {
        while (!q.empty() && i - m + 1 > q.front()) q.pop_front();
        while (cnt[i] --) q.pb(i);
        while (!q.empty() && q.size() >= k) q.pop_back(), ans ++;
    }
    printf("%d\n", ans);
    return 0;
}