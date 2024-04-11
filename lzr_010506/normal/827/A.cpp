#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X firch
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define eps 1e-9
using namespace std;
const int N = 2e6 + 10;
const int MOD = 1e9 + 9;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, k, Mx = 0, fa[N];
char ch[N], ans[N];
int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int main()
{
	n = read();
	rep(i, 1, 2000005) fa[i] = i;
	rep(T, 1, n)
	{
		scanf("%s", ch + 1);
		int len = strlen(ch + 1);
		int k = read();
		rep(Q, 1, k)
		{
			int x;
			x = read();
			int now = find(x);
			while(now - x + 1 <= len)
			{
				ans[now] = ch[now - x + 1];
				fa[now] = now + 1;
				now = find(now + 1);
			}
			Mx = max(Mx, x + len - 1);
		}
	}
	rep(i, 1, Mx) putchar(ans[i] ? ans[i] : 'a');
	return 0;
}