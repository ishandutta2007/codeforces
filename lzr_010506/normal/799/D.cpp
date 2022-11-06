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
const int N = 1e5 + 10;
int a, b, h, w, n, c[N], ans;

void dfs(int a, int b, int num)
{
    if (!a && !b)
    {
        ans = min(ans, num);
        return;
    }
    if (num >= n) return;
    if (c[num + 1] == 2)
    {
        while (a) a >>= 1, num ++;
        while (b) b >>= 1, num ++;
        ans = min(ans, num);
        return;
    }
    if (a) dfs(a / c[num + 1], b, num + 1);
    if (b) dfs(a, b / c[num + 1], num + 1);
}

int main()
{
	a = read();
	b = read();
	h = read();
	w = read();
	n = read();
	rep(i, 1, n) c[i] = read();
    sort(c + 1, c + 1 + n);
    reverse(c + 1, c + 1 + n);
    ans = n + 1;
    dfs((a - 1) / h, (b - 1) / w, 0);
    dfs((b - 1) / h, (a - 1) / w, 0);
    if(ans == n + 1) cout << -1;
    else cout << ans;
    return 0;
}