#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define eps 1e-9
using namespace std;
const int N = 5e5 + 10;
const int MOD = 1e9 + 9;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, a[N], b[N], c[N];
ll ans;
int main()
{
	n = read();
    rep(i, 1, n)
    	a[i] = read();
    int cnt = 0;
    rep(i, 1, n)
    {
        while (cnt > 1 && b[cnt - 1] >= b[cnt] && b[cnt] <= a[i]) ans += min(b[cnt - 1], a[i]), cnt --;
        b[++ cnt] = a[i];
    }
    sort(b + 1, b + cnt + 1);
    rep(i, 1, cnt - 2)
    	ans += b[i];
    cout << ans;

	return 0;
}