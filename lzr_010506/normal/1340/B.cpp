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
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define All(x) (x).begin(), (x).end()
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
const int N = 1e5 + 10;
const int biao[10] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};

int n, k, a[N], ans[N];
char c[N][10];
bool f[2010][2010];

void dfs(int wei, int x) 
{
    if (x > k) return; 
    if (f[wei][x]) return; 
    f[wei][x] = 1;
    if (wei == n) 
    {
        if (x == k) 
        {
        	rep0(j, n) printf("%d", ans[j]);
            exit(0);
        } 
        return;
    }
    rrep(j, 9, 0)
    {
        ans[wei] = j;
        int y = x + __builtin_popcount(biao[j] ^ a[wei]);
        if ((biao[j] & a[wei]) == a[wei]) 
            dfs(wei + 1, y);
    }
}

int main() 
{
	n = read();
	k = read();
	rep0(i, n)
	{
        scanf("%s", c[i]);
        rep0(j, 7) a[i] = a[i] * 2 + (c[i][j] - '0');
    }
    dfs(0, 0);
    puts("-1");
    return 0;
}